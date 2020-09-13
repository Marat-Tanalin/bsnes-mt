auto ManifestViewer::create() -> void {
	setCollapsible();
	setVisible(false);

	manifestLabel.setText({bmt::get("Tools.ManifestViewer.Manifest").data(), ':'});

	manifestOption.onChange([&] {
		selectManifest();
	});

	manifestSpacer.setColor({192, 192, 192});

	#if 0 && defined(Hiro_SourceEdit)
	manifestView.setFont(Font().setFamily(Font::Mono).setSize(10));
	#else
	manifestView.setFont(Font().setFamily(Font::Mono));
	#endif

	manifestView.setEditable(false);
	manifestView.setWordWrap(false);
	typeIcon.setIcon(Icon::Device::Storage);
	nameLabel.setText("...");
}

auto ManifestViewer::loadManifest() -> void {
	manifestOption.reset();
	manifestView.setText("");

	if (!emulator->loaded()) {
		return;
	}

	auto manifests = emulator->manifests();
	auto titles    = emulator->titles();

	for (uint offset : range(manifests.size())) {
		ComboButtonItem item{&manifestOption};

		item.setAttribute("manifest", manifests[offset]);
		item.setText(titles[offset]);

		bool verified = false;

		if (offset == 0) {
			verified = program.superFamicom.verified;
		}
		else if (offset == 1) {
			if (program.gameBoy) {
				verified = program.gameBoy.verified;
			}
			else if (program.bsMemory) {
				verified = program.bsMemory.verified;
			}
			else if (program.sufamiTurboA) {
				verified = program.sufamiTurboA.verified;
			}
		}
		else if (offset == 2 && program.sufamiTurboB) {
			verified = program.sufamiTurboB.verified;
		}

		item.setIcon(verified ? (image)Icon::Emblem::Program : (image)Icon::Emblem::Binary);
	}

	manifestOption.doChange();
}

auto ManifestViewer::selectManifest() -> void {
	auto selected = manifestOption.selected();
	uint offset   = selected->offset();

	manifestView.setText(selected.attribute("manifest"));
	string location;

	if (offset == 0) {
		location = program.superFamicom.location;
	}
	else if (offset == 1) {
		if (program.gameBoy) {
			location = program.gameBoy.location;
		}
		else if (program.bsMemory) {
			location = program.bsMemory.location;
		}
		else if (program.sufamiTurboA) {
			location = program.sufamiTurboA.location;
		}
	}
	else if (offset == 2 && program.sufamiTurboB) {
		location = program.sufamiTurboB.location;
	}

	typeIcon.setIcon(location.endsWith("/") ? (image)Icon::Action::Open : (image)Icon::Emblem::File);
	nameLabel.setText(location.trimRight("/", 1L));
}