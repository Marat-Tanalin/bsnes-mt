/* MT. */
#include "bsnes-mt/translations.h"

namespace bmt = bsnesMt::translations;
/* /MT. */

auto AudioSettings::create() -> void {
	setCollapsible();
	setVisible(false);

	char colon = ':';

	effectsLabel.setFont(Font().setBold()).setText(bmt::get("Settings.Audio.Effects").data());

	effectsLayout.setSize({3, 3});
	effectsLayout.column(0).setAlignment(1.0);

	skewLabel.setText({bmt::get("Settings.Audio.Skew").data(), colon})
		.setToolTip(bmt::get("Settings.Audio.Skew.tooltip").data());

	skewValue.setAlignment(0.5).setToolTip(skewLabel.toolTip());

	skewSlider.setLength(10001).setPosition(settings.audio.skew + 5000)
		.onChange([&] {
			string value = {skewSlider.position() > 5000 ? "+" : "", (int)skewSlider.position() - 5000};
			settings.audio.skew = value.integer();
			skewValue.setText(value);
	
			if (audio.driver() != "None") {
				program.updateAudioFrequency();
			}
		})
		.doChange();

	volumeLabel.setText({bmt::get("Settings.Audio.Volume").data(), colon})
		.setToolTip(bmt::get("Settings.Audio.Volume.tooltip").data());

	volumeValue.setAlignment(0.5).setToolTip(volumeLabel.toolTip());

	volumeSlider.setLength(201).setPosition(settings.audio.volume)
		.onChange([&] {
			string value = {volumeSlider.position(), "%"};
			settings.audio.volume = value.natural();
			volumeValue.setText(value);
			program.updateAudioEffects();
		})
		.doChange();

	balanceLabel.setText({bmt::get("Settings.Audio.Balance").data(), colon})
		.setToolTip(bmt::get("Settings.Audio.Balance.tooltip").data());

	balanceValue.setAlignment(0.5).setToolTip(balanceLabel.toolTip());

	balanceSlider.setLength(101).setPosition(settings.audio.balance)
		.onChange([&] {
			string value = {balanceSlider.position(), "%"};
			settings.audio.balance = value.natural();
			balanceValue.setText(value);
			program.updateAudioEffects();
		})
		.doChange();

	muteUnfocused.setText(bmt::get("Settings.Audio.MuteWhenUnfocused").data())
		.setChecked(settings.audio.muteUnfocused)
		.onToggle([&] {
			settings.audio.muteUnfocused = muteUnfocused.checked();
		});
}