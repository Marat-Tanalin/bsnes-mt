#if defined(Hiro_BrowserDialog)

struct BrowserDialogWindow {
  // Application::Namespace tr{"BrowserDialog"}; // Commented-out by MT.

  BrowserDialogWindow(BrowserDialog::State& state) : state(state) {}
  auto accept() -> void;
  auto activate() -> void;
  auto change() -> void;
  auto context() -> void;
  auto isObject(const string& name) -> bool;
  auto isFile(const string& name) -> bool;
  auto isFolder(const string& name) -> bool;
  auto isMatch(const string& name) -> bool;
  auto run() -> BrowserDialog::Response;
  auto setPath(string path, const string& contains = "") -> void;

private:
  Window window;
    VerticalLayout layout{&window};
      HorizontalLayout pathLayout{&layout, Size{~0, 0}, 5_sx};
        LineEdit pathName{&pathLayout, Size{~0, 0}, 0};
        Button pathRefresh{&pathLayout, Size{0, 0}, 0};
        Button pathNew{&pathLayout, Size{0, 0}, 0};
        Button pathHome{&pathLayout, Size{0, 0}, 0};
        Button pathUp{&pathLayout, Size{0, 0}, 0};
      ListView view{&layout, Size{~0, ~0}, 5_sx};
      HorizontalLayout controlLayout{&layout, Size{~0, 0}};
        ComboButton filterList{&controlLayout, Size{0, 0}, 0};
        Button searchButton{&controlLayout, Size{0, 0}, 0};
        LineEdit fileName{&controlLayout, Size{~0, 0}, 5_sx};
        ComboButton optionList{&controlLayout, Size{0, 0}, 5_sx};
        Button acceptButton{&controlLayout, Size{80_sx, 0}, 5_sx};
        Button cancelButton{&controlLayout, Size{80_sx, 0}, 5_sx};

  PopupMenu contextMenu;
    MenuItem createAction{&contextMenu};
    MenuItem renameAction{&contextMenu};
    MenuItem removeAction{&contextMenu};
    MenuSeparator contextSeparator{&contextMenu};
    MenuCheckItem showHiddenOption{&contextMenu};

  BrowserDialog::State& state;
  BrowserDialog::Response response;
  vector<vector<string>> filters;
};

//accept button clicked, or enter pressed inside file name field
//also called by table view activate after special case handling
auto BrowserDialogWindow::accept() -> void {
  auto batched = view.batched();

  if(state.action == "openFile" && batched.size() == 1) {
    string name = batched[0].text();
    if(isFolder(name)) return setPath({state.path, name});
    response.selected.append({state.path, name});
  }

  if(state.action == "openFiles" && batched) {
    string name = batched[0].text();
    if(isFolder(name) && batched.size() == 1) return setPath({state.path, name});
    for(auto item : batched) {
      string name = item.text();
      if(isFolder(name)) {
        response.selected.reset();
        return;
      }
      response.selected.append({state.path, name});
    }
  }

  if(state.action == "openFolder" && batched.size() == 1) {
    string name = batched[0].text();
    if(!isMatch(name)) return setPath({state.path, name});
    response.selected.append({state.path, name, "/"});
  }

  if(state.action == "openObject" && batched.size() == 1) {
    string name = batched[0].text();
    if(!isMatch(name) && isFolder(name)) return setPath({state.path, name});
    response.selected.append({state.path, name, isFolder(name) ? "/" : ""});
  }

  if(state.action == "saveFile") {
    string name = fileName.text();
    if(!name || isFolder(name)) return;
    if(file::exists({state.path, name})) {
      /* // Commented-out by MT.
      if(MessageDialog(bms::get("Browser.SaveFile.fileExists").data()).question({bms::get("Common.Yes").data(), 
        bms::get("Common.No").data()}) != bms::get("Common.Yes").data())
      */
      if (!bmw::confirmById("Browser.SaveFile.fileExists"), window.handle()) { // MT.
        return;
      } // "File already exists. Overwrite it?" // "Yes"
    }
    response.selected.append({state.path, name});
  }

  if(state.action == "selectFolder") {
    if(!batched) {
      response.selected.append(state.path);
    } else if(batched.size() == 1) {
      string name = batched[0].text();
      if(isFolder(name)) response.selected.append({state.path, name, "/"});
    }
  }

  if(response.selected) window.setModal(false);
}

//table view item double-clicked, or enter pressed on selected table view item
auto BrowserDialogWindow::activate() -> void {
  auto batched = view.batched();

  if(state.action == "saveFile" && batched.size() == 1) {
    string name = batched[0].text();
    if(isFolder(name)) return setPath({state.path, name});
    fileName.setText(name);
  }

  if(state.action == "selectFolder" && batched.size() == 1) {
    string name = batched[0].text();
    if(isFolder(name)) return setPath({state.path, name});
  }

  accept();
}

//table view item changed
auto BrowserDialogWindow::change() -> void {
  auto batched = view.batched();
  if(state.action == "openFile") {
    acceptButton.setEnabled(batched.size() == 1);
  }
  if(state.action == "openFiles") {
    bool enabled = true;
    for(auto item : batched) enabled &= !isFolder(item.text());
    if(batched.size() == 1 && isFolder(batched[0].text())) enabled = true;
    acceptButton.setEnabled(enabled);
  }
  if(state.action == "openFolder") {
    acceptButton.setEnabled(batched.size() == 1);
  }
  if(state.action == "openObject") {
    acceptButton.setEnabled(batched.size() == 1);
  }
  if(state.action == "saveFile") {
    string result;
    if(batched.size() == 1) {
      string name = batched[0].text();
      if(!isFolder(name)) result = name;
    }
    if(result != fileName.text()) {
      fileName.setText(result).doChange();
    }
  }
  if(state.action == "selectFolder") {
    acceptButton.setEnabled(!batched || (batched.size() == 1 && isFolder(batched[0].text())));
  }
}

auto BrowserDialogWindow::context() -> void {
  auto batched = view.batched();
  if(!batched) {
    createAction.setVisible(true);
    renameAction.setVisible(false);
    removeAction.setVisible(false);
  } else if(batched.size() == 1) {
    createAction.setVisible(false);
    renameAction.setVisible(true);
    removeAction.setVisible(true);
  } else {
    createAction.setVisible(false);
    renameAction.setVisible(false);
    removeAction.setVisible(true);
  }
  contextMenu.setVisible();
}

auto BrowserDialogWindow::isObject(const string& name) -> bool {
  return inode::exists({state.path, name});
}

auto BrowserDialogWindow::isFile(const string& name) -> bool {
  return file::exists({state.path, name});
}

auto BrowserDialogWindow::isFolder(const string& name) -> bool {
  return directory::exists({state.path, name});
}

auto BrowserDialogWindow::isMatch(const string& name) -> bool {
  if(auto selectedItem = filterList.selected()) {
    for(auto& filter : filters[selectedItem->offset()]) {
      if(name.match(filter)) return true;
    }
  }
  return false;
}

auto BrowserDialogWindow::run() -> BrowserDialog::Response {
  response = {};

  auto document = BML::unserialize(file::read({Path::userSettings(), "hiro/browser-dialog.bml"}));
  struct Settings {
    bool showHidden = true;
  } settings;
  if(auto node = document["BrowserDialog/ShowHidden"]) settings.showHidden = node.boolean();

  layout.setPadding(5_sx, 5_sy);
  pathName.onActivate([&] { setPath(pathName.text()); });
  image iconRefresh{Icon::Action::Refresh};
  iconRefresh.scale(16_sx, 16_sy);
  pathRefresh.setBordered(false).setIcon(iconRefresh).onActivate([&] { setPath(state.path); });
  image iconNew{Icon::Action::NewFolder};
  iconNew.scale(16_sx, 16_sy);
  pathNew.setBordered(false).setIcon(iconNew).onActivate([&] { createAction.doActivate(); });
  image iconHome{Icon::Go::Home};
  iconHome.scale(16_sx, 16_sy);
  pathHome.setBordered(false).setIcon(iconHome).onActivate([&] { setPath(Path::user()); });
  image iconUp{Icon::Go::Up};
  iconUp.scale(16_sx, 16_sy);
  pathUp.setBordered(false).setIcon(iconUp).onActivate([&] { setPath(Location::dir(state.path)); });
  view.setBatchable(state.action == "openFiles").onActivate([&] { activate(); }).onChange([&] { change(); });
  view.onContext([&] { context(); });
  filterList.setVisible(state.action != "selectFolder").onChange([&] { setPath(state.path); });
  for(auto& filter : state.filters) {
    auto part = filter.split("|", 1L);
    filterList.append(ComboButtonItem().setText(part.left()));
  }
  optionList.setCollapsible().setVisible((bool)state.options).onChange([&] { response.option = optionList.selected().text(); });
  for(auto& option : state.options) {
    optionList.append(ComboButtonItem().setText(option));
  }
  optionList.doChange();  //updates response.option to point to the default (first) option
  image iconSearch{Icon::Action::Search};
  iconSearch.scale(16_sx, 16_sy);
  searchButton.setIcon(iconSearch).setBordered(false).onActivate([&] { setPath(state.path, fileName.text()); });
  fileName.onActivate([&] {
    string name = fileName.text();
    if((state.action == "openFile" || state.action == "openFiles") && isFile(name)) {
      response.selected.append({state.path, name});
      return (void)window.setModal(false);
    }
    if((state.action == "openFolder" || state.action == "selectFolder") && isFolder(name)) {
      response.selected.append({state.path, name});
      return (void)window.setModal(false);
    }
    if(state.action == "openObject" && isObject(name)) {
      response.selected.append({state.path, name});
      return (void)window.setModal(false);
    }
    if(state.action == "saveFile") return accept();
    setPath(state.path, name);
  }).onChange([&] {
    auto name = fileName.text();
    if(state.action == "saveFile") acceptButton.setEnabled(name && !isFolder(name));
  });
  acceptButton.setEnabled(false).onActivate([&] { accept(); });
  if(state.action.beginsWith("open")) acceptButton.setText(bms::get("Common.Open").data()); // tr("Open")
  if(state.action.beginsWith("save")) acceptButton.setText(bms::get("Common.Save").data()); // tr("Save")
  if(state.action.beginsWith("select")) acceptButton.setText(bms::get("Browser.Select").data()); // tr("Select")
  cancelButton.setText(bms::get("Common.Cancel").data()).onActivate([&] { window.setModal(false); }); // tr("Cancel")

  if(!state.filters) state.filters.append("All|*");
  for(auto& filter : state.filters) {
    auto part = filter.split("|", 1L);
    filters.append(part.right().split(":"));
  }

  /* MT. */
  char colon = ':';
  char space = ' ';
  string ellipsis = "...";
  /* /MT. */

  createAction.setIcon(Icon::Action::NewFolder).setText({bms::get("Browser.CreateFolder").data(), ellipsis}).onActivate([&] { // "Create Folder..."
    if(auto name = NameDialog()
    .setTitle(bms::get("Browser.CreateFolder").data()) // "Create Folder"
    .setText({bms::get("Browser.CreateFolder.EnterNewFolderName").data(), colon}) // "Enter a new folder name:"
    .setIcon(Icon::Emblem::Folder)
    .setAlignment(window)
    .create()
    ) {
      directory::create({state.path, name});
      pathRefresh.doActivate();
    }
  });

  renameAction.setIcon(Icon::Application::TextEditor).setText({bms::get("Common.Rename").data(), ellipsis}).onActivate([&] { // "Rename..."
    auto batched = view.batched();
    if(batched.size() != 1) return;
    auto name = batched[0].text();

    if(directory::exists({state.path, name})) {
      if(auto rename = NameDialog()
      .setTitle({bms::get("Common.Rename").data(), space, name}) // "Rename "
      .setText({bms::get("Browser.Rename.EnterNewFolderName").data(), colon}) // "Enter the new folder name:"
      .setIcon(Icon::Emblem::Folder)
      .setAlignment(window)
      .rename(name)
      ) {
        if(name == rename) return;
        if(!directory::rename({state.path, name}, {state.path, rename})) {
          /* // Commented-out by MT.
          return (void)MessageDialog()
            .setTitle(bms::get("Common.Error").data()) // "Error"
            .setText(bms::get("Browser.Rename.FailedToRenameFolder").data()) // "Failed to rename folder."
            .setAlignment(window)
            .error();
          */

          /* MT. */
          bmw::showError(bms::get("Browser.Rename.FailedToRenameFolder"), "", window.handle());
          return;
          /* /MT. */
        }
        pathRefresh.doActivate();
      }
    } else if(file::exists({state.path, name})) {
      if(auto rename = NameDialog()
      .setTitle({bms::get("Common.Rename").data(), space, name}) // "Rename "
      .setText({bms::get("Browser.Rename.EnterNewFileName").data(), colon}) // "Enter the new file name:"
      .setIcon(Icon::Emblem::File)
      .setAlignment(window)
      .rename(name)
      ) {
        if(name == rename) return;
        if(!file::rename({state.path, name}, {state.path, rename})) {
          /* // Commented-out by MT.
          return (void)MessageDialog()
            .setTitle(bms::get("Common.Error").data()) // "Error"
            .setText(bms::get("Browser.Rename.FailedToRenameFile").data()) // "Failed to rename file."
            .setAlignment(window)
            .error();
          */

          /* MT. */
          bmw::showError(bms::get("Browser.Rename.FailedToRenameFile"), "", window.handle());
          return;
          /* /MT. */
        }

        pathRefresh.doActivate();
      }
    }
  });

  removeAction.setIcon(Icon::Action::Remove).setText({bms::get("Common.Delete").data(), ellipsis}).onActivate([&] { // "Delete..."
    auto batched = view.batched();
    if(!batched) return;

    /* // Commented-out by MT.
    if(MessageDialog()
    .setTitle(bms::get("Browser.Delete.DeleteSelected").data()) // "Remove Selected"
    .setText({bms::get("Browser.Delete.confirm").data(), space, batched.size() == 1 ? 
      bms::get("Browser.Delete.SelectedItem").data() : 
      bms::get("Browser.Delete.SelectedItems").data(), "?"}) // "Are you sure you want to permanently delete the selected item" // "s"
    .setAlignment(window)
    .question({bms::get("Common.Yes").data(), bms::get("Common.No").data()}) == bms::get("Common.No").data()) { // "No"
    */

    /* MT. */
    string selectedItemsString = batched.size() == 1
                               ? bms::get("Browser.Delete.confirm.item").data()
                               : bms::get("Browser.Delete.confirm.items").data();

    string messageText = {
      string(bms::get("Browser.Delete.confirm").data()).replace('|', selectedItemsString), "?"
    };
    /* /MT. */

    if (!bmw::confirm(messageText.data(), bms::get("Browser.Delete.DeleteSelected"), window.handle())) { // MT.
      return;
    }

    for(auto& item : batched) {
      auto name = item.text();

      /* MT. */
      string continueMessageText = string(bms::get("Browser.Delete.FailedToDelete").data()).replace('|', name);
      /* /MT. */

      if(directory::exists({state.path, name})) {
        if(!directory::remove({state.path, name})) {
          /* // Commented-out by MT.
          if(MessageDialog()
          .setTitle(bms::get("Common.Warning").data()) // "Warning"
          .setText({bms::get("Browser.Delete.FailedToDelete").data(), space, name, "\n\n", 
            bms::get("Browser.Delete.continueDeletingRemaining").data(), "?"}) // "Failed to remove " // Continue trying to remove remaining items
          .question({bms::get("Common.Yes").data(), bms::get("Common.No").data()}) == bms::get("Common.No").data()) { // "No"
          */

          if (!bmw::confirm(continueMessageText.data(), bms::get("Common.Warning"), window.handle())) { // MT.
            break;
          }
        }
      } else if(file::exists({state.path, name})) {
        if(!file::remove({state.path, name})) {
          /*
          if(MessageDialog()
          .setTitle(bms::get("Common.Warning").data()) // "Warning"
          .setText({bms::get("Browser.Delete.FailedToDelete").data(), space, name, "\n\n", 
            bms::get("Browser.Delete.continueDeletingRemaining").data(), "?"}) // "Failed to remove " // Continue trying to remove remaining items
          .question({bms::get("Common.Yes").data(), bms::get("Common.No").data()}) == bms::get("Common.No").data()) { // "No"
          */

          if (!bmw::confirm(continueMessageText.data(), bms::get("Common.Warning"), window.handle())) { // MT.
            break;
          }
        }
      }
    }
    pathRefresh.doActivate();
  });

  showHiddenOption.setChecked(settings.showHidden).setText(bms::get("Browser.ShowHidden").data()).onToggle([&] { // "Show Hidden"
    auto document = BML::unserialize(file::read({Path::userSettings(), "hiro/browser-dialog.bml"}));
    document("BrowserDialog/ShowHidden").setValue(showHiddenOption.checked());
    directory::create({Path::userSettings(), "hiro/"});
    file::write({Path::userSettings(), "hiro/browser-dialog.bml"}, BML::serialize(document));
    pathRefresh.doActivate();
  });

  setPath(state.path);

  window.onClose([&] { window.setModal(false); });
  window.setTitle(state.title);
  window.setSize({640_sx, 480_sy});
  window.setAlignment(state.relativeTo, state.alignment);
  window.setDismissable();
  window.setVisible();
  fileName.setText(state.name).setFocused().doChange();
  Application::processEvents();
  view->resizeColumns();
  window.setModal();
  window.setVisible(false);

  return response;
}

auto BrowserDialogWindow::setPath(string path, const string& contains) -> void {
  path.transform("\\", "/");
  if((path || Path::root() == "/") && !path.endsWith("/")) path.append("/");
  pathName.setText(state.path = path);
  view.reset();
  auto contents = directory::icontents(path);

  for(auto content : contents) {
    bool isFolder = content.endsWith("/");
    if(isFolder) {
      content.trimRight("/", 1L);
      if(state.action == "openFolder" || state.action == "openObject") {
        if(isMatch(content)) continue;
      }
    } else {
      continue;
    }
    if(!showHiddenOption.checked() && directory::hidden({state.path, content})) continue;
    view.append(ListViewItem().setText(content).setIcon(Icon::Emblem::Folder));
  }

  for(auto content : contents) {
    bool isFolder = content.endsWith("/");
    if(isFolder) {
      content.trimRight("/", 1L);
      if(state.action != "openFolder" && state.action != "openObject") continue;
    } else {
      if(state.action == "openFolder") continue;
    }
    if(!isMatch(content)) continue;
    if(contains && !content.ifind(contains)) continue;
    if(!showHiddenOption.checked() && file::hidden({state.path, content})) continue;
    view.append(ListViewItem().setText(content).setIcon(isFolder ? (image)Icon::Action::Open : (image)Icon::Emblem::File));
  }

  Application::processEvents();
  view->resizeColumns();  //todo: on Windows, adding items may add vertical scrollbar; this hack corrects column width
  view.doChange();
}

//

BrowserDialog::BrowserDialog() {
}

auto BrowserDialog::alignment() const -> Alignment {
  return state.alignment;
}

auto BrowserDialog::alignmentWindow() const -> Window {
  return state.relativeTo;
}

auto BrowserDialog::filters() const -> vector<string> {
  return state.filters;
}

auto BrowserDialog::openFile() -> string {
  state.action = "openFile";
  if(!state.title) state.title = bms::get("Browser.OpenFile").data(); // "Open File"
  if(auto result = _run()) return result.left();
  return {};
}

auto BrowserDialog::openFiles() -> vector<string> {
  state.action = "openFiles";
  if(!state.title) state.title = bms::get("Browser.OpenFiles").data(); // "Open Files"
  if(auto result = _run()) return result;
  return {};
}

auto BrowserDialog::openFolder() -> string {
  state.action = "openFolder";
  if(!state.title) state.title = bms::get("Browser.OpenFolder").data(); // "Open Folder"
  if(auto result = _run()) return result.left();
  return {};
}

auto BrowserDialog::openObject() -> string {
  state.action = "openObject";
  if(!state.title) state.title = bms::get("Browser.OpenObject").data(); // "Open Object"
  if(auto result = _run()) return result.left();
  return {};
}

auto BrowserDialog::option() -> string {
  return response.option;
}

auto BrowserDialog::path() const -> string {
  return state.path;
}

auto BrowserDialog::saveFile() -> string {
  state.action = "saveFile";
  if(!state.title) state.title = bms::get("Browser.SaveFile").data(); // "Save File"
  if(auto result = _run()) return result.left();
  return {};
}

auto BrowserDialog::selected() -> vector<string> {
  return response.selected;
}

auto BrowserDialog::selectFolder() -> string {
  state.action = "selectFolder";
  if(!state.title) state.title = bms::get("Browser.SelectFolder").data(); // "Select Folder"
  if(auto result = _run()) return result.left();
  return {};
}

auto BrowserDialog::setAlignment(Alignment alignment) -> type& {
  state.alignment = alignment;
  state.relativeTo = {};
  return *this;
}

auto BrowserDialog::setAlignment(sWindow relativeTo, Alignment alignment) -> type& {
  state.alignment = alignment;
  state.relativeTo = relativeTo;
  return *this;
}

auto BrowserDialog::setFilters(const vector<string>& filters) -> type& {
  state.filters = filters;
  return *this;
}

auto BrowserDialog::setName(const string& name) -> type& {
  state.name = name;
  return *this;
}

auto BrowserDialog::setOptions(const vector<string>& options) -> type& {
  state.options = options;
  return *this;
}

auto BrowserDialog::setPath(const string& path) -> type& {
  state.path = path;
  return *this;
}

auto BrowserDialog::setTitle(const string& title) -> type& {
  state.title = title;
  return *this;
}

auto BrowserDialog::title() const -> string {
  return state.title;
}

auto BrowserDialog::_run() -> vector<string> {
  if(!state.path) state.path = Path::user();
  response = BrowserDialogWindow(state).run();
  return response.selected;
}

#endif
