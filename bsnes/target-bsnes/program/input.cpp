auto Program::updateInputDriver(Window parent) -> void {
  auto changed = (bool)input;
  input.create(settings.input.driver);
  input.setContext(presentation.viewport.handle());
  if(changed) {
  }

  inputManager.initialize();
  inputSettings.reloadPorts();
  hotkeySettings.reloadMappings();

  if(!input.ready()) {
    /* MT. */
    string message = bms::get("Settings.Drivers.Input.failedToInitialize").data();
    /* MT. */

    // "Error: failed to initialize [", settings.input.driver, "] input driver."
    // MessageDialog(message.replace('|', settings.input.driver)).setAlignment(parent).error(); // Commented-out by MT.
    bmw::showError(message.replace('|', settings.input.driver).data(), "", parent.handle()); // MT.
    settings.input.driver = "None";
    return updateInputDriver(parent);
  }
}
