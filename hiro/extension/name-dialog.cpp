#if defined(Hiro_NameDialog)

NameDialog::NameDialog() {
  layout.setPadding(5_sx, 5_sy);
  typeIcon.setCollapsible();
  nameValue.onActivate([&] { acceptButton.doActivate(); });
  acceptButton.onActivate([&] {
    response = nameValue.text();
    window.doClose();
  });
  cancelButton.setText(bmt::get("Common.Cancel").data()).onActivate([&] { window.doClose(); }); // "Cancel"

  window.onClose([&] {
    window.setModal(false);
    window.setVisible(false);
  });

  window.setDismissable();
}

auto NameDialog::create(string name) -> string {
  return show("Create", name);
}

auto NameDialog::rename(string name) -> string {
  return show("Rename", name);
}

auto NameDialog::setAlignment(Alignment alignment) -> type& {
  state.alignment = alignment;
  state.relativeTo = {};
  return *this;
}

auto NameDialog::setAlignment(sWindow relativeTo, Alignment alignment) -> type& {
  state.alignment = alignment;
  state.relativeTo = relativeTo;
  return *this;
}

auto NameDialog::setIcon(const image& icon) -> type& {
  state.icon = icon;
  return *this;
}

auto NameDialog::setText(const string& text) -> type& {
  state.text = text;
  return *this;
}

auto NameDialog::setTitle(const string& title) -> type& {
  state.title = title;
  return *this;
}

auto NameDialog::show(string mode, string name) -> string {
  response = {};
  setTitle(state.title);
  if(!state.title && mode == "Create") setTitle(bmt::get("Browser.Create").data()); // "Create"
  if(!state.title && mode == "Rename") setTitle({bmt::get("Common.Rename").data(), ' ', name}); // "Rename "

  string enterNameString = {bmt::get("Browser.Create.EnterName").data(), ':'}; // MT.

  textLabel.setText(state.text ? state.text : enterNameString); // "Enter a name:"

  if(state.icon) {
    image icon{state.icon};
    icon.scale(16_sx, 16_sy);
    typeIcon.setIcon(icon);
  } else {
    typeIcon.setVisible(false);
  }
  nameValue.setText(name);
  acceptButton.setText(mode == "Rename" ? bmt::get("Common.Rename").data() : bmt::get("Browser.Create").data());
  window.setTitle(state.title);
  window.setSize({400_sx, layout.minimumSize().height()});
  window.setAlignment(state.relativeTo, state.alignment);
  window.setVisible();
  nameValue.setFocused();
  window.setModal();
  return response;
}

#endif
