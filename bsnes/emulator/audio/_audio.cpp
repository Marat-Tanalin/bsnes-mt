/* MT. */
#include <memory>
#include <vector>
/* /MT. */

namespace Emulator {

#include "_stream.cpp"
Audio audio;

Audio::~Audio() {
  reset(nullptr);
}

auto Audio::reset(Interface* interface) -> void {
  _interface = interface;
  _streams.reset();
  _channels = 0;
}

auto Audio::setFrequency(double frequency) -> void {
  _frequency = frequency;
  for(auto& stream : _streams) {
    stream->setFrequency(stream->inputFrequency, frequency);
  }
}

auto Audio::setVolume(double volume) -> void {
  _volume = volume;
}

auto Audio::setBalance(double balance) -> void {
  _balance = balance;
}

auto Audio::createStream(uint channels, double frequency) -> shared_pointer<Stream> {
  _channels = max(_channels, channels);
  shared_pointer<Stream> stream = new Stream;
  stream->reset(channels, frequency, _frequency);
  _streams.append(stream);
  return stream;
}

auto Audio::process() -> void {
  while(_streams) {
    for(auto& stream : _streams) {
      if(!stream->pending()) return;
    }

    std::vector<double> samples(_channels); // Changed by MT. Was `double samples[_channels];`.

    for(auto& sample : samples) sample = 0.0;

    for(auto& stream : _streams) {
      auto buffer = std::make_unique<double[]>(_channels); // Changed by MT. Was `double buffer[_channels];`.
      uint length = stream->read(buffer.get()), offset = 0;

      for(auto& sample : samples) {
        sample += buffer[offset];
        if(++offset >= length) offset = 0;
      }
    }

    for(auto c : range(_channels)) {
      samples[c] = max(-1.0, min(+1.0, samples[c] * _volume));
    }

    if(_channels == 2) {
      if(_balance < 0.0) samples[1] *= 1.0 + _balance;
      if(_balance > 0.0) samples[0] *= 1.0 - _balance;
    }

    platform->audioFrame(samples.data(), _channels); // `.data()` after `samples` added by MT.
  }
}

}

#undef double
