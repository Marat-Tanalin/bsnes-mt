auto Program::movieMode(Movie::Mode mode) -> void {
  movie.mode = mode;

  if(movie.mode == Movie::Mode::Inactive) {
    presentation.moviePlay.setEnabled(true);
    presentation.movieRecord.setEnabled(true);
    presentation.movieStop.setEnabled(false);
  }

  if(movie.mode == Movie::Mode::Playing) {
    presentation.moviePlay.setEnabled(false);
    presentation.movieRecord.setEnabled(false);
    presentation.movieStop.setEnabled(true);
  }

  if(movie.mode == Movie::Mode::Recording) {
    presentation.moviePlay.setEnabled(false);
    presentation.movieRecord.setEnabled(false);
    presentation.movieStop.setEnabled(true);
  }
}

auto Program::moviePlay() -> void {
  BrowserDialog dialog;
  dialog.setTitle(bms::get("Movies.PlayMovie").data()); // "Play Movie"
  dialog.setPath(Path::desktop());
  dialog.setFilters({{bms::get("Movies.Movies").data(), " (.bsv)|*.bsv"}}); // "Movies"
  if(auto location = openFile(dialog)) {
    if(auto fp = file::open(location, file::mode::read)) {
      bool failed = false;
      if(fp.read() != 'B') failed = true;
      if(fp.read() != 'S') failed = true;
      if(fp.read() != 'V') failed = true;
      if(fp.read() != '1') failed = true;
      if(uint32_t size = fp.readl(4L)) {
        if(fp.size() - fp.offset() < size) failed = true;
        if(!failed) {
          auto data = new uint8_t[size];
          fp.read({data, size});
          serializer s{data, size};
          if(!emulator->unserialize(s)) failed = true;
        }
      } else {
        //entropy can desync movies recorded without save states
        emulator->configure("Hacks/Entropy", "None");
        emulator->power();
      }
      if(!failed) {
        movieMode(Movie::Mode::Playing);
        movie.input.reset();
        while(fp.size() - fp.offset() >= 2) {
          movie.input.append(fp.readl(2L));
        }
        showMessage(bms::get("Movies.playbackStarted").data()); // "Movie playback started"
      } else {
        showMessage(bms::get("Movies.formatNotSupported").data()); // "Movie format not supported"
      }
    }
  }
}

auto Program::movieRecord(bool fromBeginning) -> void {
  if(movie.mode == Movie::Mode::Inactive) {
    movieMode(Movie::Mode::Recording);
    if(fromBeginning) {
      //entropy can desync movies recorded without save states
      emulator->configure("Hacks/Entropy", "None");
      emulator->power();
      movie.state = {};
    } else {
      movie.state = emulator->serialize();
    }
    movie.input.reset();
    showMessage(bms::get("Movies.recordingStarted").data()); // "Movie recording started"
  }
}

auto Program::movieStop() -> void {
  if(movie.mode == Movie::Mode::Inactive) {
    return;
  }

  if(movie.mode == Movie::Mode::Playing) {
    showMessage(bms::get("Movies.playbackStopped").data()); // "Movie playback stopped"
  }

  if(movie.mode == Movie::Mode::Recording) {
    //stop recording more inputs while attempting to save file asynchronously
    movieMode(Movie::Mode::Inactive);

    BrowserDialog dialog;
    dialog.setTitle(bms::get("Movies.SaveMovie").data()); // "Save Movie"
    dialog.setPath(Path::desktop());
    dialog.setFilters({{bms::get("Movies.Movies").data(), " (.bsv)|*.bsv"}}); // "Movies"
    if(auto location = saveFile(dialog)) {
      if(!location.endsWith(".bsv")) location.append(".bsv");
      if(auto fp = file::open(location, file::mode::write)) {
        fp.write('B');
        fp.write('S');
        fp.write('V');
        fp.write('1');
        fp.writel(movie.state.size(), 4L);
        fp.write({movie.state.data(), movie.state.size()});
        for(auto& input : movie.input) fp.writel(input, 2L);
        showMessage(bms::get("Movies.MovieRecorded").data()); // "Movie recorded"
      } else {
        showMessage(bms::get("Movies.cantRecord").data()); // "Movie could not be recorded"
      }
    } else {
      showMessage(bms::get("Movies.MovieNotRecorded").data()); // "Movie not recorded"
    }
  }

  movieMode(Movie::Mode::Inactive);
  movie.state = {};
  movie.input.reset();
}
