auto Program::updateInputDriver(Window parent) -> void {
	auto changed = (bool)input;

	input.create(settings.input.driver);
	input.setContext(presentation.viewport.handle());

	// if (changed) {} // Commented-out by MT because does nothing.

	inputManager.initialize();
	inputSettings.reloadPorts();
	hotkeySettings.reloadMappings();

	if (!input.ready()) {
		string message = bms::get("Settings.Drivers.Input.failedToInitialize").data(); // MT.

		// MessageDialog(message.replace('|', settings.input.driver)).setAlignment(parent).error(); // Commented-out by MT.
		bmw::showError(message.replace('|', settings.input.driver).data(), "", parent.handle()); // MT.
		settings.input.driver = "None";

		return updateInputDriver(parent);
	}
}