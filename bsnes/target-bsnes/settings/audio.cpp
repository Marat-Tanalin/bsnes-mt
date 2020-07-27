/* MT. */
#include "bsnes-mt/strings.h"

namespace bms = bsnesMt::strings;
/* /MT. */

auto AudioSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	char colon = ':';

	effectsLabel.setFont(Font().setBold()).setText(bms::get("Settings.Audio.Effects").data());

	effectsLayout.setSize({3, 3});
	effectsLayout.column(0).setAlignment(1.0);

	skewLabel.setText({bms::get("Settings.Audio.Skew").data(), colon}).setToolTip( // "Skew:"
		bms::get("Settings.Audio.Skew.tooltip").data()
	);

	skewValue.setAlignment(0.5).setToolTip(skewLabel.toolTip());

	skewSlider.setLength(10001).setPosition(settings.audio.skew + 5000).onChange([&] {
		string value = {skewSlider.position() > 5000 ? "+" : "", (int)skewSlider.position() - 5000};
		settings.audio.skew = value.integer();
		skewValue.setText(value);

		if (audio.driver() != "None") {
			program.updateAudioFrequency();
		}
	}).doChange();

	volumeLabel.setText({bms::get("Settings.Audio.Volume").data(), colon}).setToolTip( // "Volume:"
		bms::get("Settings.Audio.Volume.tooltip").data()
	);

	volumeValue.setAlignment(0.5).setToolTip(volumeLabel.toolTip());

	volumeSlider.setLength(201).setPosition(settings.audio.volume).onChange([&] {
		string value = {volumeSlider.position(), "%"};
		settings.audio.volume = value.natural();
		volumeValue.setText(value);
		program.updateAudioEffects();
	}).doChange();

	balanceLabel.setText({bms::get("Settings.Audio.Balance").data(), colon}).setToolTip( // "Balance:"
		bms::get("Settings.Audio.Balance.tooltip").data()
	);

	balanceValue.setAlignment(0.5).setToolTip(balanceLabel.toolTip());

	balanceSlider.setLength(101).setPosition(settings.audio.balance).onChange([&] {
		string value = {balanceSlider.position(), "%"};
		settings.audio.balance = value.natural();
		balanceValue.setText(value);
		program.updateAudioEffects();
	}).doChange();

	muteUnfocused.setText(bms::get("Settings.Audio.MuteWhenUnfocused").data()).setChecked(settings.audio.muteUnfocused).onToggle([&] { // "Mute when unfocused"
		settings.audio.muteUnfocused = muteUnfocused.checked();
	});
}