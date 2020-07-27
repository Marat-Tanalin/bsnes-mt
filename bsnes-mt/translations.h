/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

const uint8_t EN = 1, // English
              RU = 2, // Russian
              JP = 3; // Japanese

static map<string, map<uint8_t, string>> strings = {
	{
		"Common.Yes",
		{
			{EN, "Yes"},
			{RU, "Да"},
			{JP, "はい"}
		}
	},
	{
		"Common.No",
		{
			{EN, "No"},
			{RU, "Нет"},
			{JP, "いいえ"}
		}
	},
	{
		"Common.Cancel",
		{
			{EN, "Cancel"},
			{RU, "Отмена"},
			{JP, "キャンセル"}
		}
	},
	{
		"Common.Always",
		{
			{EN, "Always"},
			{RU, "Всегда"}
		}
	},
	{
		"Common.AreYouSure",
		{
			{EN, "Are you sure?"},
			{RU, "Вы уверены?"}
		}
	},
	{
		"Common.Open",
		{
			{EN, "Open"},
			{RU, "Открыть"},
			{JP, "開く"}
		}
	},
	{
		"Common.Load",
		{
			{EN, "Load"},
			{RU, "Загрузить"}
		}
	},
	{
		"Common.Save",
		{
			{EN, "Save"},
			{RU, "Сохранить"},
			{JP, "保存"}
		}
	},
	{
		"Common.Add",
		{
			{EN, "Add"},
			{RU, "Добавить"}
		}
	},
	{
		"Common.Remove",
		{
			{EN, "Remove"},
			{RU, "Удалить"}
		}
	},
	{
		"Common.Delete",
		{
			{EN, "Delete"},
			{RU, "Удалить"}
		}
	},
	{
		"Common.Rename",
		{
			{EN, "Rename"},
			{RU, "Переименовать"}
		}
	},
	{
		"Common.Reset",
		{
			{EN, "Reset"},
			{RU, "Сброс"},
			{JP, "リセット"}
		}
	},
	{
		"Common.Clear",
		{
			{EN, "Clear"},
			{RU, "Очистить"}
		}
	},
	{
		"Common.None",
		{
			{EN, "None"},
			{RU, "Нет"},
			{JP, "なし"}
		}
	},
	{
		"Common.Disabled",
		{
			{EN, "Disabled"},
			{RU, "Отключено"}
		}
	},
	{
		"Common.Default",
		{
			{EN, "Default"},
			{RU, "По умолчанию"}
		}
	},
	{
		"Common.Name",
		{
			{EN, "Name"},
			{RU, "Название"}
		}
	},
	{
		"Common.Date",
		{
			{EN, "Date"},
			{RU, "Дата"}
		}
	},
	{
		"Common.Success",
		{
			{EN, "Success"},
			{RU, "Успех"}
		}
	},
	{
		"Common.Failure",
		{
			{EN, "Failure"},
			{RU, "Неудача"}
		}
	},
	{
		"Common.Error",
		{
			{EN, "Error"},
			{RU, "Ошибка"}
		}
	},
	{
		"Common.Warning",
		{
			{EN, "Warning"},
			{RU, "Внимание"}
		}
	},
	{
		"Common.Auto",
		{
			{EN, "Auto"},
			{RU, "Авто"}
		}
	},
	{
		"Common.Video",
		{
			{EN, "Video"},
			{RU, "Видео"}
		}
	},
	{
		"Common.Audio",
		{
			{EN, "Audio"},
			{RU, "Звук"}
		}
	},
	{
		"Common.Fps", // Frames per second (frame-rate unit).
		{
			{EN, "FPS"},
			{RU, "к/с"}
		}
	},
	{
		"Common.Hz",
		{
			{EN, "Hz"},
			{RU, "Гц"}
		}
	},
	{
		"Common.number",
		{
			{EN, "#"},
			{RU, "№"}
		}
	},

	{
		"Menu.File",
		{
			{EN, "File"},
			{RU, "Файл"}
		}
	},
	{
		"Menu.File.OpenGame",
		{
			{EN, "Open Game"},
			{RU, "Открыть игру"},
			{JP, "ゲームを読み込み"}
		}
	},
	{
		"Menu.File.OpenRecentGame",
		{
			{EN, "Open Recent Game"},
			{RU, "Открыть недавнюю игру"},
			{JP, "最新ゲームを読み込み"}
		}
	},
	{
		"Menu.File.OpenRecentGame.ClearList",
		{
			{EN, "Clear List"},
			{RU, "Очистить список"},
			{JP, "全部を消す"}
		}
	},
	{
		"Menu.File.OpenRecentGame.NoRecentGames",
		{
			{EN, "No Recent Games"},
			{RU, "Нет недавних игр"}
		}
	},
	{
		"Menu.File.CloseGame",
		{
			{EN, "Close Game"},
			{RU, "Закрыть игру"},
			{JP, "ゲームをアンロード"}
		}
	},
	{
		"Menu.File.Exit",
		{
			{EN, "Exit"},
			{RU, "Выход"},
			{JP, "終了"}
		}
	},

	{
		"Menu.System",
		{
			{EN, "System"},
			{RU, "Система"},
			{JP, "システム"}
		}
	},
	{
		"Menu.System.ControllerPort",
		{
			{EN, "Controller Port"},
			{RU, "Порт контроллера"},
			{JP, "コントローラポート"}
		}
	},
	{
		"Menu.System.ExpansionPort",
		{
			{EN, "Expansion Port"},
			{RU, "Порт расширения"},
			{JP, "拡張ポート"}
		}
	},

	{
		"Menu.Settings.Size",
		{
			{EN, "Size"},
			{RU, "Размер"}
		}
	},
	{
		"Menu.Settings.Size.ShrinkWindowToSize",
		{
			{EN, "Shrink Window to Size"},
			{RU, "Подогнать окно под размер"}
		}
	},
	{
		"Menu.Settings.Size.CenterWindow",
		{
			{EN, "Center Window"},
			{RU, "Центрировать окно"}
		}
	},
	{
		"Menu.Settings.Size.FullScreenMode",
		{
			{EN, "Full-Screen Mode"},
			{RU, "Полноэкранный режим"}
		}
	},
	{
		"Menu.Settings.Size.PseudoFullScreenMode",
		{
			{EN, "Pseudo-Full-Screen Mode"},
			{RU, "Псевдополноэкранный режим"}
		}
	},
	{
		"Menu.Settings.Output",
		{
			{EN, "Output"},
			{RU, "Изображение"}
		}
	},
	{
		"Menu.Settings.Output.Center",
		{
			{EN, "Center"},
			{RU, "По центру"}
		}
	},
	{
		"Menu.Settings.Output.PixelPerfect",
		{
			{EN, "Pixel-Perfect"},
			{RU, "Целочисленное масштабирование"}
		}
	},
	{
		"Menu.Settings.Output.Scale",
		{
			{EN, "Scale"},
			{RU, "Масштабирование с сохранением пропорций"}
		}
	},
	{
		"Menu.Settings.Output.Stretch",
		{
			{EN, "Stretch"},
			{RU, "Растяжение без сохранения пропорций"}
		}
	},
	{
		"Menu.Settings.Output.AspectRatioCorrection",
		{
			{EN, "Aspect-Ratio Correction"},
			{RU, "Коррекция соотношения сторон"}
		}
	},
	{
		"Menu.Settings.Output.ShowOverscanArea",
		{
			{EN, "Show Overscan Area"},
			{RU, "Показать область «overscan»"}
		}
	},
	{
		"Menu.Settings.Output.scalingInfo",
		{
			{EN, "Scaling Info in Status Bar"},
			{RU, "Информация о масштабировании в строке состояния"}
		}
	},
	{
		"Menu.Settings.Output.HiresBlurEmulation",
		{
			{EN, "Hires Blur Emulation"},
			{RU, "Эмуляция размытия в режиме высокого разрешения"}
		}
	},
	{
		"Menu.Settings.Filter",
		{
			{EN, "Filter"},
			{RU, "Фильтр"}
		}
	},
	{
		"Menu.Settings.Shader",
		{
			{EN, "Shader"},
			{RU, "Шейдер"}
		}
	},
	{
		"Menu.Settings.Shader.Blur",
		{
			{EN, "Blur"},
			{RU, "Размытие"}
		}
	},
	{
		"Menu.Settings.MuteAudio",
		{
			{EN, "Mute Audio"},
			{RU, "Выключить звук"}
		}
	},
	{
		"Menu.Settings.ShowStatusBar",
		{
			{EN, "Show Status Bar"},
			{RU, "Показать строку состояния"}
		}
	},
	// For settings-sections' menu-items, see "Settings.*".
	{
		"Menu.Settings.OpenSettingsFolder",
		{
			{EN, "Open Settings Folder"},
			{RU, "Открыть папку настроек"}
		}
	},

	{
		"Menu.Help",
		{
			{EN, "Help"},
			{RU, "Справка"},
			{JP, "ヘルプ"}
		}
	},
	{
		"Menu.Help.About",
		{
			{EN, "About |"},
			{RU, "О программе |"},
			{JP, "| について"}
		}
	},

	{
		"Settings",
		{
			{EN, "Settings"},
			{RU, "Настройки"},
			{JP, "設定"}
		}
	},

	// Used in "Hotkeys", "Input" and "Paths" settings.
	{
		"Settings.Common.Assign",
		{
			{EN, "Assign"},
			{RU, "Задать"}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.AssignLowercase",
		{
			{EN, "assign"},
			{RU, "задать"}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.Mapping",
		{
			{EN, "Mapping"},
			{RU, "Соответствие"}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.MappingAssigned",
		{
			{EN, "Mapping assigned."},
			{RU, "Соответствие задано."}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.PressKeyOrButtonForMapping",
		{
			{EN, "Press a key or button for mapping"},
			{RU, "Нажмите клавишу или кнопку для привязки"}
		}
	},
	// Used in "Emulator" and "Enhancements" settings.
	{
		"Settings.Common.FrameLowercase",
		{
			{EN, "frame"},
			{RU, "кадр"}
		}
	},

	// "Settings.Video" -- see "Common.Video".
	{
		"Settings.Video.ColorAdjustment",
		{
			{EN, "Color Adjustment"},
			{RU, "Настройка цвета"}
		}
	},
	{
		"Settings.Video.Luminance",
		{
			{EN, "Luminance"},
			{RU, "Яркость"}
		}
	},
	{
		"Settings.Video.Saturation",
		{
			{EN, "Saturation"},
			{RU, "Насыщенность"}
		}
	},
	{
		"Settings.Video.Gamma",
		{
			{EN, "Gamma"},
			{RU, "Контрастность"}
		}
	},
	{
		"Settings.Video.DimVideoWhenIdle",
		{
			{EN, "Dim video when idle"},
			{RU, "Затемнять изображение при простое"}
		}
	},
	{
		"Settings.Video.DimVideoWhenIdle.tooltip",
		{
			{EN, "Darkens the video to indicate that the emulation is not running."},
			{RU, "Затемняет изображение, чтобы показать, что эмуляция приостановлена."}
		}
	},
	{
		"Settings.Video.DrawSnowEffectWhenIdle",
		{
			{EN, "Draw snow effect when idle"},
			{RU, "Применять эффект снега при простое"}
		}
	},

	// "Settings.Audio" -- see "Common.Audio".
	{
		"Settings.Audio.Effects",
		{
			{EN, "Effects"},
			{RU, "Эффекты"}
		}
	},
	{
		"Settings.Audio.Skew",
		{
			{EN, "Skew"},
			{RU, "Частота"}
		}
	},
	{
		"Settings.Audio.Skew.tooltip",
		{
			{
				EN,
				"Adjusts the audio frequency by the skew amount (in Hz).\n\n"
				"This is essentially static rate control.\n"
				"First, enable both video and audio sync.\n"
				"Then, raise or lower this value to try to reduce errors.\n"
				"One direction will help video, but hurt audio.\n"
				"The other direction will do the reverse.\n"
				"The idea is to find the best middle ground.\n\n"
				"You should leave this at 0 when using dynamic rate control."
			},
			{
				RU,
				"Изменяет частоту дискретизации на заданную величину (в Гц).\n\n"
				"По сути это статическое управление частотой.\n"
				"Сначала включите синхронизацию как для видео, так и для звука.\n"
				"Затем попробуйте увеличить или уменьшить это значение для уменьшения ошибок.\n"
				"Изменение в одном направлении положительно скажется на видео, но отрицательно — на звуке.\n"
				"Изменение в другом направлении приведёт к обратному результату.\n"
				"Смысл в том, чтобы найти наилучший компромисс.\n\n"
				"При динамическом управлении частотой используйте значение 0."
			}
		}
	},
	{
		"Settings.Audio.Volume",
		{
			{EN, "Volume"},
			{RU, "Громкость"}
		}
	},
	{
		"Settings.Audio.Volume.tooltip",
		{
			{
				EN,
				"Adjusts the audio output volume.\n\n"
				"You should not use values above 100%, if possible!\n"
				"If you do, audio clipping distortion can occur."
			},
			{
				RU,
				"Изменяет громкость звука.\n\n"
				"По возможности не следует использовать значения выше 100%!\n"
				"В противном случае возможны искажения из-за превышения максимально возможного уровня."
			}
		}
	},
	{
		"Settings.Audio.Balance",
		{
			{EN, "Balance"},
			{RU, "Панорама"}
		}
	},
	{
		"Settings.Audio.Balance.tooltip",
		{
			{
				EN,
				"Pans audio to the left (lower values) or right (higher values).\n\n"
				"50% (centered) is the recommended setting."
			},
			{
				RU,
				"Панорамирует звук влево (меньшие значения) или вправо (более высокие значения).\n\n"
				"Рекомендуемое значение — 50% (по центру)."
			}
		}
	},
	{
		"Settings.Audio.MuteWhenUnfocused",
		{
			{EN, "Mute when unfocused"},
			{RU, "Отключать звук при неактивном окне программы"}
		}
	},

	{
		"Settings.Input",
		{
			{EN, "Input"},
			{RU, "Устройства ввода"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost",
		{
			{EN, "When focus is lost"},
			{RU, "При неактивном окне программы"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost.PauseEmulation",
		{
			{EN, "Pause emulation"},
			{RU, "Приостановить эмуляцию"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost.BlockInput",
		{
			{EN, "Block input"},
			{RU, "Блокировать ввод"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost.AllowInput",
		{
			{EN, "Allow input"},
			{RU, "Разрешить ввод"}
		}
	},
	{
		"Settings.Input.Port",
		{
			{EN, "Port"},
			{RU, "Порт"}
		}
	},
	{
		"Settings.Input.Device",
		{
			{EN, "Device"},
			{RU, "Устройство"}
		}
	},
	{
		"Settings.Input.TurboRate",
		{
			{EN, "Turbo rate"},
			{RU, "Частота турбо"}
		}
	},
	{
		"Settings.Input.TurboRate.tooltip",
		{
			{EN, "The number of frames to wait between toggling turbo buttons."},
			{RU, "Количество кадров между срабатываниями турбо-кнопок."}
		}
	},
	{
		"Settings.Input.MouseLeft",
		{
			{EN, "Mouse Left"},
			{RU, "Левая кнопка мыши"}
		}
	},
	{
		"Settings.Input.MouseMiddle",
		{
			{EN, "Mouse Middle"},
			{RU, "Средняя кнопка мыши"}
		}
	},
	{
		"Settings.Input.MouseRight",
		{
			{EN, "Mouse Right"},
			{RU, "Правая кнопка мыши"}
		}
	},
	{
		"Settings.Input.MouseXAxis",
		{
			{EN, "Mouse X-axis"},
			{RU, "Мышь по оси X"}
		}
	},
	{
		"Settings.Input.MouseYAxis",
		{
			{EN, "Mouse Y-axis"},
			{RU, "Мышь по оси Y"}
		}
	},

	{
		"Settings.Hotkeys",
		{
			{EN, "Hotkeys"},
			{RU, "Горячие клавиши"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic",
		{
			{EN, "Combinational logic"},
			{RU, "Комбинационная логика"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.tooltip",
		{
			{
				EN,
				"Determines whether all or any mappings must be pressed to activate hotkeys.\n"
				"Use “AND” logic if you want keyboard combinations such as Ctrl+F to trigger a hotkey.\n"
				"Use “OR” logic if you want both a keyboard and joypad to trigger the same hotkey."
			},
			{
				RU,
				"Определяет, все или любое из соответствий требуется нажать для активации горячих клавиш.\n"
				"Используйте логику «И», если для активации горячих клавиш вам нужны такие сочетания клавиш, как Ctrl+F.\n"
				"Используйте логику «ИЛИ», если для активации одних и тех же горячих клавиш вы хотите использовать как клавиатуру, так и геймпад."
			}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.And",
		{
			{EN, "AND"},
			{RU, "И"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.And.tooltip",
		{
			{EN, "Every mapping must be pressed to activate a given hotkey."},
			{RU, "Для активации заданных горячих клавиш требуется нажать все соответствия."}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.Or",
		{
			{EN, "OR"},
			{RU, "ИЛИ"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.Or.tooltip",
		{
			{EN, "Any mapping can be pressed to activate a given hotkey."},
			{RU, "Для активации заданных горячих клавиш можно нажать любое из соответствий."}
		}
	},
	{
		"Settings.Hotkeys.Rewind.enableFirst",
		{
			{EN, "Please enable rewind support in “Settings” → “Emulator” first"},
			{RU, "Пожалуйста, сначала включите поддержку перемотки: «Настройки» → «Эмулятор»"}
		}
	},

	{
		"Settings.Paths",
		{
			{EN, "Paths"},
			{RU, "Пути"}
		}
	},
	{
		"Settings.Paths.Games",
		{
			{EN, "Games"},
			{RU, "Игры"}
		}
	},
	{
		"Settings.Paths.Patches",
		{
			{EN, "Patches"},
			{RU, "Патчи"}
		}
	},
	{
		"Settings.Paths.Saves",
		{
			{EN, "Saves"},
			{RU, "Сохранения"}
		}
	},
	{
		"Settings.Paths.Cheats",
		{
			{EN, "Cheats"},
			{RU, "Читы"}
		}
	},
	{
		"Settings.Paths.States",
		{
			{EN, "States"},
			{RU, "Быстрые сохранения"}
		}
	},
	{
		"Settings.Paths.Screenshots",
		{
			{EN, "Screenshots"},
			{RU, "Скриншоты"}
		}
	},
	{
		"Settings.Paths.LastRecentlyUsed",
		{
			{EN, "last recently used"},
			{RU, "последняя использованная папка"}
		}
	},
	{
		"Settings.Paths.SameAsLoadedGame",
		{
			{EN, "same as loaded game"},
			{RU, "папка текущей игры"}
		}
	},

	{
		"Settings.Emulator",
		{
			{EN, "Emulator"},
			{RU, "Эмулятор"}
		}
	},
	{
		"Settings.Emulator.General",
		{
			{EN, "General"},
			{RU, "Общие"}
		}
	},
	{
		"Settings.Emulator.General.warnOnUnverifiedGames",
		{
			{EN, "Warn when opening games that have not been verified"},
			{RU, "Предупреждать при открытии непроверенных игр"}
		}
	},
	{
		"Settings.Emulator.General.autoSaveMemory",
		{
			{EN, "Auto-save memory periodically"},
			{RU, "Периодически автоматически сохранять память"}
		}
	},
	{
		"Settings.Emulator.General.autoSaveStateOnUnload",
		{
			{EN, "Auto-save undo state when unloading games"},
			{RU, "Автоматически сохранять состояние отмены действия при закрытии игр"}
		}
	},
	{
		"Settings.Emulator.General.AutoResumeOnLoad",
		{
			{EN, "Auto-resume on load"},
			{RU, "Автоматически возобновлять при загрузке"}
		}
	},
	{
		"Settings.Emulator.General.UseNativeFileDialogs",
		{
			{EN, "Use native file dialogs"},
			{RU, "Использовать стандартные окна открытия/сохранения файлов"}
		}
	},
	{
		"Settings.Emulator.FastForward",
		{
			{EN, "Fast Forward"},
			{RU, "Перемотка вперёд (Fast Forward)"}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip",
		{
			{EN, "Frame skip"},
			{RU, "Пропуск кадров"}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip.tooltip",
		{
			{
				EN,
				"Sets how many frames to skip while fast forwarding.\n"
				"Frame skipping allows a higher maximum fast forwarding frame rate."
			},
			{
				RU,
				"Задаёт, сколько кадров пропускать при перемотке вперёд.\n"
				"Пропуск кадров позволяет увеличить скорость перемотки."
			}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip.Frames2to4", // 2-4
		{
			{EN, "| frames"},
			{RU, "| кадра"}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip.Frames", // 4+
		{
			{EN, "| frames"},
			{RU, "| кадров"}
		}
	},
	{
		"Settings.Emulator.FastForward.Limiter",
		{
			{EN, "Limiter"},
			{RU, "Ограничение"}
		}
	},
	{
		"Settings.Emulator.FastForward.Limiter.tooltip",
		{
			{EN, "Sets the maximum speed when fast forwarding."},
			{RU, "Задаёт максимальную скорость при перемотке вперёд."}
		}
	},
	{
		"Settings.Emulator.FastForward.mute",
		{
			{EN, "Mute while fast forwarding"},
			{RU, "Отключать звук при перемотке вперёд"}
		}
	},
	{
		"Settings.Emulator.Rewind",
		{
			{EN, "Rewind"},
			{RU, "Перемотка назад (Rewind)"}
		}
	},
	{
		"Settings.Emulator.Rewind.Frequency",
		{
			{EN, "Frequency"},
			{RU, "Частота"}
		}
	},
	{
		"Settings.Emulator.Rewind.Frequency.everyFrames",
		{
			{EN, "Every | frames"},
			{RU, "Каждые | кадров"}
		}
	},
	{
		"Settings.Emulator.Rewind.Length",
		{
			{EN, "Length"},
			{RU, "Длина"}
		}
	},
	{
		"Settings.Emulator.Rewind.Length.states",
		{
			{EN, "| states"},
			{RU, "| состояний"}
		}
	},
	{
		"Settings.Emulator.Rewind.mute",
		{
			{EN, "Mute while rewinding"},
			{RU, "Отключать звук при перемотке назад"}
		}
	},

	{
		"Settings.Enhancements",
		{
			{EN, "Enhancements"},
			{RU, "Улучшения"}
		}
	},
	{
		"Settings.Enhancements.FastMode",
		{
			{EN, "Fast mode"},
			{RU, "Быстрый режим"}
		}
	},
	{
		"Settings.Enhancements.RunAhead",
		{
			{EN, "Run-Ahead"},
			{RU, "Опережающая эмуляция (Run-Ahead)"}
		}
	},
	{
		// "Two-four frames"
		"Settings.Enhancements.RunAhead.Frames",
		{
			{EN, "frames"},
			{RU, "кадра"}
		}
	},
	{
		// "One frame"
		"Settings.Enhancements.RunAhead.One",
		{
			{EN, "One"},
			{RU, "Один"}
		}
	},
	{
		// "Two frames"
		"Settings.Enhancements.RunAhead.Two",
		{
			{EN, "Two"},
			{RU, "Два"}
		}
	},
	{
		"Settings.Enhancements.RunAhead.Three",
		{
			{EN, "Three"},
			{RU, "Три"}
		}
	},
	{
		"Settings.Enhancements.RunAhead.Four",
		{
			{EN, "Four"},
			{RU, "Четыре"}
		}
	},
	{
		"Settings.Enhancements.Overclocking",
		{
			{EN, "Overclocking"},
			{RU, "Разгон"}
		}
	},
	{
		"Settings.Enhancements.Ppu.Video",
		{
			{EN, "video"},
			{RU, "видео"}
		}
	},
	{
		"Settings.Enhancements.Ppu.Deinterlace",
		{
			{EN, "Deinterlace"},
			{RU, "Устранение чересстрочности"}
		}
	},
	{
		"Settings.Enhancements.Ppu.NoSpriteLimit",
		{
			{EN, "No sprite limit"},
			{RU, "Не ограничивать количество спрайтов"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.FastPpuOnly",
		{
			{EN, "fast PPU only"},
			{RU, "только в быстром режиме PPU"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.Scale",
		{
			{EN, "Scale"},
			{RU, "Масштаб"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.PerspectiveCorrection",
		{
			{EN, "Perspective correction"},
			{RU, "Коррекция перспективы"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.Supersampling",
		{
			{EN, "Supersampling"},
			{RU, "Избыточная выборка"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.HdToSdMosaic",
		{
			{EN, "HD→SD Mosaic"},
			{RU, "Мозаичность HD→SD"}
		}
	},
	{
		"Settings.Enhancements.Dsp.Audio",
		{
			{EN, "audio"},
			{RU, "звук"}
		}
	},
	{
		"Settings.Enhancements.Dsp.CubicInterpolation",
		{
			{EN, "Cubic interpolation"},
			{RU, "Кубическая интерполяция"}
		}
	},
	{
		"Settings.Enhancements.Coprocessors",
		{
			{EN, "Coprocessors"},
			{RU, "Сопроцессоры"}
		}
	},
	{
		"Settings.Enhancements.Coprocessors.PreferHle",
		{
			{EN, "Prefer high-level emulation (HLE)"},
			{RU, "Предпочитать высокоуровневую эмуляцию (HLE)"}
		}
	},
	{
		"Settings.Enhancements.Coprocessors.PreferHle.tooltip",
		{
			{
				EN,
				"When checked, less accurate HLE emulation will always be used when available.\n"
				"When unchecked, HLE will only be used when low-level-emulation (LLE) firmware is missing."
			},
			{
				RU,
				"Когда включено, менее точная высокоуровневая эмуляция будет использоваться всегда, когда возможно.\n"
				"Когда выключено, высокоуровневая эмуляция будет использоваться только при отсутствии низкоуровневой (LLE) прошивки."
			}
		}
	},
	{
		"Settings.Enhancements.GameEnhancements",
		{
			{EN, "Game Enhancements"},
			{RU, "Улучшения игр"}
		}
	},
	{
		"Settings.Enhancements.GameEnhancements.Hotfixes",
		{
			{EN, "Hotfixes"},
			{RU, "Исправления ошибок"}
		}
	},
	{
		"Settings.Enhancements.GameEnhancements.Hotfixes.tooltip",
		{
			{
				EN,
				"Even commercially licensed and officially released software sometimes shipped with bugs.\n"
				"This option will correct certain issues that occurred even on real hardware."
			},
			{  
				RU,
				"Даже в коммерчески лицензированных и официально выпущенных программах иногда есть ошибки.\n"
				"Этот параметр исправит определённые проблемы, которые имели место на реальном оборудовании."
			}
		}
	},

	{
		"Settings.Compatibility",
		{
			{EN, "Compatibility"},
			{RU, "Совместимость"}
		}
	},
	{
		"Settings.Compatibility.entropy",
		{
			{EN, "Entropy (randomization)"},
			{RU, "Энтропия (степень случайности)"}
		}
	},
	{
		"Settings.Compatibility.entropy.None.tooltip",
		{
			{
				EN,
				"All memory and registers are initialized to constant values at startup.\n"
				"Use this for compatibility with very old demoscene homebrew games."
			},
			{
				RU,
				"При запуске вся память и регистры устанавливаются в постоянные значения.\n"
				"Используйте этот вариант для совместимости с очень старыми самодельными играми демосцены."
			}
		}
	},
	{
		"Settings.Compatibility.entropy.Low",
		{
			{EN, "Low"},
			{RU, "Низкая"}
		}
	},
	{
		"Settings.Compatibility.entropy.Low.tooltip",
		{
			{
				EN,
				"All memory is randomized with repeating patterns, all registers are randomized at startup.\n"
				"Use this for the most accurate representation of a real SNES."
			},
			{
				RU,
				"При запуске вся память заполняется повторяющимися случайными значениями, все регистры устанавливаются в случайные значения.\n"
				"Используйте этот вариант для наиболее точного соответствия реальной SNES."
			}
		}
	},
	{
		"Settings.Compatibility.entropy.High",
		{
			{EN, "High"},
			{RU, "Высокая"}
		}
	},
	{
		"Settings.Compatibility.entropy.High.tooltip",
		{
			{
				EN,
				"All memory and registers are randomized as much as possible.\n"
				"Use this when developing new SNES software to ensure maximum compatibility with real hardware."
			},
			{
				RU,
				"Вся память и регистры устанавливаются в максимально случайные значения.\n"
				"Используйте этот вариант при разработке новых программ для SNES,\n"
				"чтобы гарантировать максимальную совместимость с реальным оборудованием."
			}
		}
	},
	{
		"Settings.Compatibility.cpu.Processor",
		{
			{EN, "processor"},
			{RU, "процессор"}
		}
	},
	{
		"Settings.Compatibility.cpu.FastMath",
		{
			{EN, "Fast math"},
			{RU, "Быстрая математика"}
		}
	},
	{
		"Settings.Compatibility.cpu.FastMath.tooltip",
		{
			{
				EN,
				"CPU multiplication and division take time to complete on a real SNES.\n"
				"Older emulators did not simulate these delays, and provided results immediately.\n"
				"Some older ROM hacks do not wait for math operations to complete and need this hack."
			},
			{
				RU,
				"На реальной SNES умножение и деление средствами процессора занимает время.\n"
				"Старые эмуляторы не учитывали эти задержки и возвращали результат сразу.\n"
				"Этот параметр нужен некоторым старым ROM-хакам, которые не ждали завершения математических операций."
			}
		}
	},
	{
		"Settings.Compatibility.ppu.Video",
		{
			{EN, "video"},
			{RU, "видео"}
		}
	},
	{
		"Settings.Compatibility.ppu.NoVramBlocking",
		{
			{EN, "No video-memory (VRAM) blocking"},
			{RU, "Не блокировать видеопамять (VRAM)"}
		}
	},
	{
		"Settings.Compatibility.ppu.NoVramBlocking.tooltip",
		{
			{
				EN,
				"This option enables emulating a bug in older releases of ZSNES and Snes9x where VRAM blocking was not emulated.\n"
				"A few older ROM hacks relied on this behavior, and will render graphics incorrectly if not enabled.\n"
				"Not only is this extremely inaccurate to real hardware, it also hurts the speed of the fast PPU.\n"
				"Do not enable this option unless you need to play a game that works incorrectly otherwise."
			},
			{
				RU,
				"Этот параметр включает эмуляцию ошибки старых версий ZSNES and Snes9x, где не было эмуляции блокировки видеопамяти.\n"
				"Некоторые старые ROM-хаки рассчитывали на это поведение и будут отрисовываться неправильно, если этот параметр не включить.\n"
				"Это не только сильно отличается от поведения реального оборудования, но и снижает быстродействие быстрого PPU.\n"
				"Не включайте этот параметр, если вам не требуется поиграть в игру, в противном случае работающую неправильно."
			}
		}
	},
	{
		"Settings.Compatibility.dsp.Audio",
		{
			{EN, "audio"},
			{RU, "звук"}
		}
	},
	{
		"Settings.Compatibility.dsp.EchoShadowRam",
		{
			{EN, "Echo shadow RAM"},
			{RU, "Отображать теневую память (echo shadow RAM)"}
		}
	},
	{
		"Settings.Compatibility.dsp.EchoShadowRam.tooltip",
		{
			{
				EN,
				"This option enables emulating a bug in ZSNES where echo RAM was treated as separate from APU RAM.\n"
				"Many older ROM hacks for “Super Mario World” relied on this behavior, and will crash without enabling this.\n"
				"It is, however, extremely inaccurate to real hardware and should not be enabled unless required."
			},
			{
				RU,
				"Этот параметр включает эмуляцию ошибки ZSNES, где отображаемая память (echo RAM) рассматривалась отдельно от памяти APU.\n"
				"Многие старые ROM-хаки «Super Mario World» рассчитывали на это поведение и не будут работать без включения этого параметра.\n"
				"Однако это сильно отличается от поведения реального оборудования, и не следует включать этот параметр без необходимости."
			}
		}
	},

	{
		"Settings.Drivers",
		{
			{EN, "Drivers"},
			{RU, "Драйверы"}
		}
	},
	{
		"Settings.Drivers.Driver",
		{
			{EN, "Driver"},
			{RU, "Драйвер"}
		}
	},
	{
		"Settings.Drivers.Change",
		{
			{EN, "Change"},
			{RU, "Изменить"}
		}
	},
	{
		"Settings.Drivers.Reload",
		{
			{EN, "Reload"},
			{RU, "Перезагрузить"}
		}
	},
	{
		"Settings.Drivers.ExclusiveMode",
		{
			{EN, "Exclusive mode"},
			{RU, "Эксклюзивный режим"}
		}
	},
	{
		"Settings.Drivers.Synchronize",
		{
			{EN, "Synchronize"},
			{RU, "Синхронизация"}
		}
	},
	{
		"Settings.Drivers.ActiveDriver",
		{
			{EN, "Active driver"},
			{RU, "Активный драйвер"}
		}
	},
	{
		"Settings.Drivers.changeConfirm.title",
		{
			{EN, "Change driver?"},
			{RU, "Изменить драйвер?"}
		}
	},
	{
		"Settings.Drivers.changeConfirm",
		{
			{
				EN,
				"Warning: incompatible drivers may cause the application to crash.\n"
				"It is highly recommended you unload your game first to be safe.\n"
				"Do you wish to proceed with the driver change now anyway?"
			},
			{
				RU,
				"Внимание: несовместимые драйверы могут привести к невозможности работы программы.\n"
				"Для безопасности настоятельно рекомендуется сначала закрыть вашу игру.\n"
				"Хотите ли вы изменить драйвер в любом случае?"
			}
		}
	},
	{
		"Settings.noteGameRestart",
		{
			{EN, "Note: some settings do not take effect until reloading the game."},
			{RU, "Примечание: некоторые настройки применяются только после перезагрузки игры."}
		}
	},
	{
		"Settings.Drivers.Video.failedToInitialize",
		{
			{EN, "Failed to initialize [|] video driver"},
			{RU, "Не удалось инициализировать видеодрайвер [|]"}
		}
	},
	{
		"Settings.Drivers.Video.FullScreenMonitor",
		{
			{EN, "Full-screen monitor"},
			{RU, "Монитор для полноэкранного режима"}
		}
	},
	{
		"Settings.Drivers.Video.FullScreenMonitor.tooltip",
		{
			{EN, "Sets which monitor video is sent to in full-screen mode."},
			{RU, "Задаёт, на какой монитор выводится изображение в полноэкранном режиме."}
		}
	},
	{
		"Settings.Drivers.Video.Format",
		{
			{EN, "Format"},
			{RU, "Формат"}
		}
	},
	{
		"Settings.Drivers.Video.ExclusiveMode.tooltip",
		{
			{
				EN,
				"Causes full-screen mode to take over all monitors.\n"
				"This allows adaptive sync to work better and reduces input latency.\n"
				"However, multi-monitor users should turn this option off.\n"
				"Note: Direct3D exclusive mode also does not honor the requested monitor."
			},
			{
				RU,
				"Приводит к тому, что в полноэкранном режиме изображение занимает все мониторы.\n"
				"Улучшает работу адаптивной синхронизации (adaptive sync) и уменьшает задержку ввода.\n"
				"Однако пользователям многомониторных конфигураций имеет смысл отключить этот параметр.\n"
				"Примечание: для Direct3D в эксклюзивном режиме также не учитывается выбранный монитор."
			}
		}
	},
	{
		"Settings.Drivers.Video.Synchronize.tooltip",
		{
			{
				EN,
				"Waits for the video card to be ready before rendering frames.\n"
				"Eliminates dropped or duplicated frames, but can distort audio.\n\n"
				"With this option, it’s recommended to disable audio sync,\n"
				"and enable dynamic rate control. Or alternatively, adjust\n"
				"the audio skew option to reduce buffer under/overflows."
			},
			{
				RU,
				"Ожидает готовности видеокарты перед отрисовкой кадров.\n"
				"Устраняет пропуск или повторение кадров, но может искажать звук.\n\n"
				"При использовании этого параметра рекомендуется отключить синхронизацию\n"
				"звука и включить динамическое управление частотой. Как вариант,\n"
				"подстройте звуковой параметр «Частота» для снижения вероятности\n"
				"опустошения/переполнения буфера."
			}
		}
	},
	{
		"Settings.Drivers.Video.GpuSync",
		{
			{EN, "GPU sync"},
			{RU, "Синхронизация GPU"}
		}
	},
	{
		"Settings.Drivers.Video.GpuSync.tooltip",
		{
			{
				EN,
				"(OpenGL driver only)\n\n"
				"Causes the GPU to wait until frames are fully rendered.\n"
				"In the best case, this can remove up to one frame of input lag.\n"
				"However, it incurs a roughly 20% performance penalty.\n\n"
				"You should disable this option unless you find it necessary."
			},
			{
				RU,
				"(Только для драйвера OpenGL)\n\n"
				"Заставляет видеокарту ожидать, пока кадры не будут полностью отрисованы.\n"
				"В лучшем случае это может устранить до одного кадра задержки ввода.\n"
				"Однако при этом быстродействие снижается примерно на 20%.\n\n"
				"Следует отключить этот параметр, если он вам не требуется."
			}
		}
	},
	{
		"Settings.Drivers.Audio.failedToInitialize",
		{
			{EN, "Failed to initialize [|] audio driver"},
			{RU, "Не удалось инициализировать аудиодрайвер [|]"}
		}
	},
	{
		"Settings.Drivers.Audio.OutputDevice",
		{
			{EN, "Output device"},
			{RU, "Устройство вывода"}
		}
	},
	{
		"Settings.Drivers.Audio.SampleRate",
		{
			{EN, "Sample Rate"},
			{RU, "Частота дискретизации"}
		}
	},
	{
		"Settings.Drivers.Audio.Latency",
		{
			{EN, "Latency"},
			{RU, "Задержка"}
		}
	},
	{
		"Settings.Drivers.Audio.ExclusiveMode.tooltip",
		{
			{
				EN,
				"(WASAPI driver only)\n\n"
				"Acquires exclusive control of the sound card device.\n"
				"This can significantly reduce audio latency.\n"
				"However, it will block sounds from all other applications."
			},
			{
				RU,
				"(Только для драйвера WASAPI)\n\n"
				"Включает исключительный доступ к звуковой карте.\n"
				"Это может существенно снизить задержку вывода звука.\n"
				"Однако звуки от всех других приложений заблокируются."
			}
		}
	},
	{
		"Settings.Drivers.Audio.Synchronize.tooltip",
		{
			{
				EN,
				"Waits for the audio card to be ready before outputting samples.\n"
				"Eliminates audio distortion, but can distort video.\n\n"
				"With this option, it’s recommended to disable video sync.\n"
				"For best results, use this with an adaptive sync monitor."
			},
			{
				RU,
				"Ожидает готовности звуковой карты перед выводом звука.\n"
				"Устраняет искажения звука, но может искажать видео.\n\n"
				"При использовании этого параметра рекомендуется отключить синхронизацию видео.\n"
				"Для наилучших результатов используйте этот параметр\n"
				"с монитором, поддерживающим адаптивную синхронизацию."
			}
		}
	},
	{
		"Settings.Drivers.Audio.DynamicRate",
		{
			{EN, "Dynamic rate"},
			{RU, "Динамическая частота"}
		}
	},
	{
		"Settings.Drivers.Audio.DynamicRate.tooltip",
		{
			{
				EN,
				"(OSS, XAudio2, waveOut drivers only)\n\n"
				"Dynamically adjusts the audio frequency by tiny amounts.\n"
				"Use this with video sync enabled, and audio sync disabled.\n\n"
				"This can produce perfectly smooth video and clean audio,\n"
				"but only if your monitor refresh rate is set correctly:\n"
				"60 Hz for NTSC games, and 50 Hz for PAL games."
			},
			{
				RU,
				"(Только для драйверов OSS, XAudio2, waveOut)\n\n"
				"Динамически подстраивает частоту звука на небольшие величины.\n"
				"Используйте при включённой синхронизации видео\n"
				"и отключённой синхронизации звука.\n\n"
				"Может обеспечить идеально плавное видео и чистый звук,\n"
				"но только при правильно установленной частоте обновления монитора:\n"
				"60 Гц для игр NTSC и 50 Гц для игр PAL."
			}
		}
	},
	{
		"Settings.Drivers.Input.failedToInitialize",
		{
			{EN, "Failed to initialize [|] input driver"},
			{RU, "Не удалось инициализировать драйвер устройства ввода [|]"}
		}
	},
	{
		"Settings.Drivers.Input.Reload.tooltip",
		{
			{
				EN, 
				"A driver reload can be used to detect hotplugged devices.\n"
				"This is useful for APIs that lack auto-hotplug support,\n"
				"such as DirectInput and SDL."
			},
			{
				RU,
				"Перезагрузку драйвера можно использовать для обнаружения\n"
				"устройств, подключённых в «горячем» режиме.\n"
				"Полезно для программных интерфейсов (API), не поддерживающих\n"
				"«горячее» подключение, таких как DirectInput и SDL."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets",
		{
			{EN, "Synchronization Mode Presets"},
			{RU, "Предустановки режимов синхронизации"}
		}
	},
	{
		"Settings.Drivers.syncModePresets.requirements",
		{
			{
				EN,
				"Adaptive Sync: requires G-Sync or FreeSync monitor.\n"
				"Dynamic Rate Control: requires monitor and SNES refresh rates to match."
			},
			{
				RU,
				"Адаптивная синхронизация: требуется монитор с поддержкой G-Sync или FreeSync.\n"
				"Динамическое управление частотой: частоты обновления монитора и SNES должны совпадать."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync",
		{
			{EN, "Adaptive Sync"},
			{RU, "Адаптивная синхронизация"}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync.failure",
		{
			{
				EN,
				"Sorry, the current driver configuration is not compatible with adaptive sync mode.\n"
				"Adaptive sync requires audio-synchronization support."
			},
			{
				RU,
				"Извините, текущая конфигурация драйверов несовместима с режимом адаптивной синхронизации.\n"
				"Для адаптивной синхронизации требуется поддержка синхронизации звука."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync.success",
		{
			{
				EN,
				"Adaptive sync works best in exclusive full-screen mode.\n"
				"Use the lowest audio latency setting your system can manage.\n"
				"A G-Sync or FreeSync monitor is required.\n"
				"Adaptive sync must be enabled in your driver settings panel."
			},
			{
				RU,
				"Адаптивная синхронизация лучше всего работает в эксклюзивном полноэкранном режиме.\n"
				"Используйте минимальную задержку звука, которая возможна на вашей системе.\n"
				"Требуется монитор с поддержкой G-Sync или FreeSync.\n"
				"Требуется включить адаптивную синхронизацию в панели управления вашего видеодрайвера."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl",
		{
			{EN, "Dynamic Rate Control"},
			{RU, "Динамическое управление частотой"}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl.failure",
		{
			{
				EN,
				"Sorry, the current driver configuration is "
				"not compatible with the dynamic-rate-control mode.\n"
				"Dynamic rate control requires video synchronization "
				"and audio-dynamic-rate support."
			},
			{
				RU,
				"Извините, текущая конфигруация драйверов несовместима "
				"с режимом динамического управления частотой.\n"
				"Для динамического управления частотой требуется "
				"поддержка вертикальной синхронизации "
				"и динамического изменения частоты звука."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl.success",
		{
			{
				EN,
				"Dynamic rate control requires your monitor to be running at:\n"
				"60 Hz refresh rate for NTSC games, 50 Hz refresh rate for PAL games.\n"
				"Use the lowest audio latency setting your system can manage."
			},
			{
				RU,
				"Для динамического управления частотой требуется, "
				"чтобы частота обновления вашего монитора была:\n"
				"60 Гц для игр NTSC, 50 Гц для игр PAL.\n"
				"Используйте минимальную задержку звука, которая возможна на вашей системе."
			}
		}
	},

	{
		"Tools",
		{
			{EN, "Tools"},
			{RU, "Инструменты"},
			{JP, "ツール"}
		}
	},

	{
		"Tools.SaveState",
		{
			{EN, "Save State"},
			{RU, "Сохранить состояние"}
		}
	},
	{
		"Tools.SaveState.Slot",
		{
			{EN, "Slot"},
			{RU, "Слот"}
		}
	},
	{
		"Tools.SaveState.Slot.Empty",
		{
			{EN, "empty"},
			{RU, "пусто"},
			{JP, "なし"}
		}
	},

	{
		"Tools.LoadState",
		{
			{EN, "Load State"},
			{RU, "Загрузить состояние"}
		}
	},
	{
		"Tools.LoadState.SelectedStateSlot",
		{
			{EN, "Selected state slot"},
			{RU, "Выбран слот быстрого сохранения"}
		}
	},
	{
		"Tools.LoadState.UndoLastSave",
		{
			{EN, "Undo Last Save"},
			{RU, "Отменить последнее сохранение"}
		}
	},
	{
		"Tools.LoadState.RedoLastUndo",
		{
			{EN, "Redo Last Undo"},
			{RU, "Вернуть последнее отменённое сохранение"}
		}
	},
	{
		"Tools.LoadState.RemoveAllStates",
		{
			{EN, "Remove All States"},
			{RU, "Удалить все сохранения"}
		}
	},
	{
		"Tools.LoadState.RemoveAllStates.confirm.title",
		{
			{EN, "Remove quick states?"},
			{RU, "Удалить быстрые сохранения?"}
		}
	},
	{
		"Tools.LoadState.RemoveAllStates.confirm",
		{
			{EN, "Are you sure you want to permanently remove all quick states for this game?"},
			{RU, "Вы уверены, что хотите навсегда удалить все быстрые сохранения для этой игры?"}
		}
	},

	{
		"Tools.Speed",
		{
			{EN, "Speed"},
			{RU, "Скорость"}
		}
	},
	{
		"Tools.Speed.Slowest",
		{
			{EN, "Slowest"},
			{RU, "Очень медленно"}
		}
	},
	{
		"Tools.Speed.Slow",
		{
			{EN, "Slow"},
			{RU, "Медленно"}
		}
	},
	{
		"Tools.Speed.Normal",
		{
			{EN, "Normal"},
			{RU, "Обычная скорость"}
		}
	},
	{
		"Tools.Speed.Fast",
		{
			{EN, "Fast"},
			{RU, "Быстро"}
		}
	},
	{
		"Tools.Speed.Fastest",
		{
			{EN, "Fastest"},
			{RU, "Очень быстро"}
		}
	},

	{
		"Tools.RunMode",
		{
			{EN, "Run Mode"},
			{RU, "Режим исполнения"}
		}
	},
	{
		"Tools.RunMode.Normal",
		{
			{EN, "Normal"},
			{RU, "Обычный"}
		}
	},
	{
		"Tools.RunMode.PauseEmulation",
		{
			{EN, "Pause Emulation"},
			{RU, "Приостановить эмуляцию"}
		}
	},
	{
		"Tools.RunMode.FrameAdvance",
		{
			{EN, "Frame Advance"},
			{RU, "Покадрово (Frame Advance)"}
		}
	},

	{
		"Tools.Movie",
		{
			{EN, "Movie"},
			{RU, "Видеозапись"}
		}
	},
	{
		"Tools.Movie.Play",
		{
			{EN, "Play"},
			{RU, "Воспроизведение"}
		}
	},
	{
		"Tools.Movie.Record",
		{
			{EN, "Record"},
			{RU, "Запись"}
		}
	},
	{
		"Tools.Movie.ResetAndRecord",
		{
			{EN, "Reset and Record"},
			{RU, "Сброс и запись"}
		}
	},
	{
		"Tools.Movie.Stop",
		{
			{EN, "Stop"},
			{RU, "Стоп"}
		}
	},

	{
		"Tools.TakeScreenshot",
		{
			{EN, "Take Screenshot"},
			{RU, "Снять скриншот"}
		}
	},

	{
		"Tools.CheatFinder",
		{
			{EN, "Cheat Finder"},
			{RU, "Поиск читов"}
		}
	},
	{
		"Tools.CheatFinder.Address",
		{
			{EN, "Address"},
			{RU, "Адрес"}
		}
	},
	{
		"Tools.CheatFinder.Value",
		{
			{EN, "Value"},
			{RU, "Значение"}
		}
	},
	{
		"Tools.CheatFinder.Scan",
		{
			{EN, "Scan"},
			{RU, "Сканировать"}
		}
	},
	{
		"Tools.CheatFinder.All",
		{
			{EN, "All"},
			{RU, "Все"}
		}
	},

	{
		"Tools.CheatEditor",
		{
			{EN, "Cheat Editor"},
			{RU, "Редактор читов"}
		}
	},
	{
		"Tools.CheatEditor.remove.confirm.title",
		{
			{EN, "Remove cheat(s)?"},
			{RU, "Удалить читы?"}
		}
	},
	{
		"Tools.CheatEditor.remove.confirm",
		{
			{EN, "Are you sure you want to permanently remove the selected cheat(s)?"},
			{RU, "Вы уверены, что хотите навсегда удалить выделенные читы?"}
		}
	},
	{
		"Tools.CheatEditor.Codes",
		{
			{EN, "Code(s)"},
			{RU, "Код(ы)"}
		}
	},
	{
		"Tools.CheatEditor.Enable",
		{
			{EN, "Enable"},
			{RU, "Включить"}
		}
	},
	{
		"Tools.CheatEditor.SelectAll",
		{
			{EN, "Select All"},
			{RU, "Выделить всё"}
		}
	},
	{
		"Tools.CheatEditor.UnselectAll",
		{
			{EN, "Unselect All"},
			{RU, "Снять выделение"}
		}
	},
	{
		"Tools.CheatEditor.AddCheats",
		{
			{EN, "Add Cheats"},
			{RU, "Добавить читы"}
		}
	},
	{
		"Tools.CheatEditor.AddCheat",
		{
			{EN, "Add Cheat"},
			{RU, "Добавить чит"}
		}
	},
	{
		"Tools.CheatEditor.EditCheat",
		{
			{EN, "Edit Cheat"},
			{RU, "Изменить чит"}
		}
	},
	{
		"Tools.CheatEditor.Edit",
		{
			{EN, "Edit"},
			{RU, "Изменить"}
		}
	},
	{
		"Tools.CheatEditor.FindCheats",
		{
			{EN, "Find Cheats"},
			{RU, "Найти читы"}
		}
	},
	{
		"Tools.CheatEditor.noCheats",
		{
			{EN, "Sorry, no cheats were found for this game."},
			{RU, "К сожалению, читы для этой игры не найдены."}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats",
		{
			{EN, "Enable Cheats"},
			{RU, "Включить читы"}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats.tooltip",
		{
			{
				EN,
				"Master enable for all cheat codes.\n"
				"When unchecked, no cheat codes will be active.\n\n"
				"Use this to bypass game areas that have problems with cheats."
			},
			{
				RU,
				"Включает все чит-коды.\n"
				"Когда выключено, ни один чит-код не будет активен.\n\n"
				"Используйте при прохождении частей игр, где читы приводят к проблемам."
			}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats.disabled",
		{
			{EN, "All cheat codes are disabled"},
			{RU, "Все чит-коды выключены"}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats.enabled",
		{
			{EN, "Active cheat codes are enabled"},
			{RU, "Активные чит-коды включены"}
		}
	},
	{
		"Tools.CheatEditor.invalidFormat",
		{
			{EN, "Invalid code(s), please only use codes in the following format"},
			{RU, "Некорректный код(ы), пожалуста, используйте следующий формат"}
		}
	},

	{
		"Tools.StateManager",
		{
			{EN, "State Manager"},
			{RU, "Менеджер сохранений"}
		}
	},
	{
		"Tools.StateManager.Category",
		{
			{EN, "Category"},
			{RU, "Категория"}
		}
	},
	{
		"Tools.StateManager.Category.ManagedStates",
		{
			{EN, "Managed States"},
			{RU, "Управляемые состояния"}
		}
	},
	{
		"Tools.StateManager.Category.QuickStates",
		{
			{EN, "Quick States"},
			{RU, "Быстрые сохранения"}
		}
	},
	{
		"Tools.StateManager.QuickStates.Undo",
		{
			{EN, "Undo"},
			{RU, "Отмена"}
		}
	},
	{
		"Tools.StateManager.Preview",
		{
			{EN, "Preview"},
			{RU, "Предпросмотр"}
		}
	},
	{
		"Tools.StateManager.AddState",
		{
			{EN, "Add State"},
			{RU, "Добавить состояние"}
		}
	},
	{
		"Tools.StateManager.RenameState",
		{
			{EN, "Rename State"},
			{RU, "Переименовать состояние"}
		}
	},
	{
		"Tools.StateManager.remove.confirm.title",
		{
			{EN, "Remove state(s)?"},
			{RU, "Удалить сохранения?"}
		}
	},
	{
		"Tools.StateManager.remove.confirm",
		{
			{EN, "Are you sure you want to permanently remove the selected state(s)?"},
			{RU, "Вы уверены, что хотите навсегда удалить выделенные сохранения?"}
		}
	},

	{
		"Tools.ManifestViewer",
		{
			{EN, "Manifest Viewer"},
			{RU, "Просмотр манифеста"}
		}
	},
	{
		"Tools.ManifestViewer.Manifest",
		{
			{EN, "Manifest"},
			{RU, "Манифест"}
		}
	},

	{
		"Game.VerifiedGameOpened",
		{
			{EN, "Verified game opened"},
			{RU, "Открыта проверенная игра"}
		}
	},
	{
		"Game.GameOpened",
		{
			{EN, "Game opened"},
			{RU, "Открыта игра"}
		}
	},
	{
		"Game.GameClosed",
		{
			{EN, "Game closed"},
			{RU, "Закрыта игра"}
		}
	},
	{
		"Game.GameReset",
		{
			{EN, "Game reset"},
			{RU, "Игра сброшена"}
		}
	},
	{
		"Game.AndPatchApplied",
		{
			{EN, " and patch applied"},
			{RU, ", и применён патч"}
		}
	},
	{
		"Game.GameOpeningCancelled",
		{
			{EN, "Game opening cancelled"},
			{RU, "Открытие игры отменено"}
		}
	},
	{
		"Game.unverifiedGameWarning.title",
		{
			{EN, "Unverified game image"},
			{RU, "Непроверенный образ игры"}
		}
	},
	{
		"Game.unverifiedGameWarning",
		{
			{
				EN,
				"Warning: this game image is unverified.\n"
				"Running it *may* be a security risk.\n\n"
				"Do you wish to run the game anyway?"
			},
			{
				RU,
				"Внимание: этот образ игры не проверен.\n"
				"Запуск игры *может* быть небезопасным.\n\n"
				"Хотите ли вы запустить игру в любом случае?"
			}
		}
	},
	{
		"Game.unverifiedGameWarning.alwaysQuestion.title",
		{
			{EN, "Disable warning?"},
			{RU, "Отключить предупреждение?"}
		}
	},
	{
		"Game.unverifiedGameWarning.alwaysQuestion",
		{
			{EN, "Do you wish to disable warning when trying to run unverified games?"},
			{RU, "Отключить предупреждение при запуске непроверенных игр?"}
		}
	},

	{
		"Program.Paused",
		{
			{EN, "Paused"},
			{RU, "Пауза"},
			{JP, "ポーズ"}
		}
	},
	{
		"Program.Unloaded",
		{
			{EN, "Unloaded"},
			{RU, "Простой"},
			{JP, "アンロードされる"}
		}
	},
	{
		"Program.CapturedScreenshot",
		{
			{EN, "Captured screenshot"},
			{RU, "Снят скриншот"}
		}
	},
	{
		"Program.Open.MissingRequiredData",
		{
			{EN, "Missing required data"},
			{RU, "Отсутствуют необходимые данные"}
		}
	},
	{
		"Program.Load.LoadGameBoyRom",
		{
			{EN, "Load Game Boy ROM"},
			{RU, "Загрузить игру Game Boy"}
		}
	},
	{
		"Program.Load.GameBoyRoms",
		{
			{EN, "Game Boy ROMs"},
			{RU, "Игры Game Boy"}
		}
	},
	{
		"Program.Load.LoadBsMemoryRom",
		{
			{EN, "Load BS Memory ROM"},
			{RU, "Загрузить образ BS-памяти"}
		}
	},
	{
		"Program.Load.BsMemoryRoms",
		{
			{EN, "BS Memory ROMs"},
			{RU, "Образы BS-памяти"}
		}
	},
	{
		"Program.Load.LoadSufamiTurboRomSlot",
		{
			{EN, "Load Sufami Turbo ROM – Slot"},
			{RU, "Загрузить игру Sufami Turbo — слот"}
		}
	},
	{
		"Program.Load.SufamiTurboRoms",
		{
			{EN, "Sufami Turbo ROMs"},
			{RU, "Игры Sufami Turbo"}
		}
	},

	{
		"About.Version",
		{
			{EN, "Version"},
			{RU, "Версия"},
			{JP, "バージョン"}
		}
	},
	{
		"About.Copyright",
		{
			{EN, "Copyright"},
			{RU, "Авторские права"}
		}
	},
	{
		"About.License",
		{
			{EN, "License"},
			{RU, "Лицензия"},
			{JP, "ライセンス"}
		}
	},
	{
		"About.Website",
		{
			{EN, "Website"},
			{RU, "Сайт"},
			{JP, "公式サイト"}
		}
	},

	{
		"About.SameBoy.description",
		{
			{EN, "Super Game Boy emulator"},
			{RU, "Эмулятор Super Game Boy"}
		}
	},

	{
		"About.Bsnes.description",
		{
			{EN, "Super Nintendo emulator"},
			{RU, "Эмулятор Super Nintendo"}
		}
	},
	{
		"About.Bsnes.copyright",
		{
			{EN, "byuu et al"},
			{RU, "byuu и другие"}
		}
	},
	{
		"About.Bsnes.license",
		{
			{EN, "GPLv3 or later"},
			{RU, "GPLv3 или новее"}
		}
	},

	{
		"Browser.OpenSnesRom",
		{
			{EN, "Open SNES ROM"},
			{RU, "Открыть игру SNES"}
		}
	},
	{
		"Browser.SnesRoms",
		{
			{EN, "SNES ROMs"},
			{RU, "Игры SNES"}
		}
	},
	{
		"Browser.AllFiles",
		{
			{EN, "All Files"},
			{RU, "Все файлы"}
		}
	},
	{
		"Browser.Select",
		{
			{EN, "Select"},
			{RU, "Выбрать"},
			{JP, "選択"}
		}
	},
	{
		"Browser.SelectFolder",
		{
			{EN, "Select Folder"},
			{RU, "Выбрать папку"}
		}
	},
	{
		"Browser.ChooseFolder",
		{
			{EN, "Choose a folder"},
			{RU, "Выберите папку"}
		}
	},
	{
		"Browser.Rename.EnterNewFolderName",
		{
			{EN, "Enter the new folder name"},
			{RU, "Введите новое имя папки"}
		}
	},
	{
		"Browser.Rename.EnterNewFileName",
		{
			{EN, "Enter the new file name"},
			{RU, "Введите новое имя файла"}
		}
	},
	{
		"Browser.Rename.FailedToRenameFolder",
		{
			{EN, "Failed to rename folder."},
			{RU, "Не удалось переименовать папку."}
		}
	},
	{
		"Browser.Rename.FailedToRenameFile",
		{
			{EN, "Failed to rename file."},
			{RU, "Не удалось переименовать файл."}
		}
	},
	{
		"Browser.Create",
		{
			{EN, "Create"},
			{RU, "Создать"}
		}
	},
	{
		"Browser.Create.EnterName",
		{
			{EN, "Enter a name"},
			{RU, "Введите имя"}
		}
	},
	{
		"Browser.CreateFolder",
		{
			{EN, "Create Folder"},
			{RU, "Создать папку"}
		}
	},
	{
		"Browser.CreateFolder.EnterNewFolderName",
		{
			{EN, "Enter a new-folder name"},
			{RU, "Введите имя новой папки"}
		}
	},
	{
		"Browser.Delete.DeleteSelected",
		{
			{EN, "Delete Selected"},
			{RU, "Удалить выделенные"}
		}
	},
	{
		"Browser.Delete.FailedToDelete",
		{
			{EN, "Failed to delete |. Continue trying to remove remaining items?"},
			{RU, "Не удалось удалить |. Попытаться удалить остальные элементы?"}
		}
	},
	{
		"Browser.Delete.confirm",
		{
			{EN, "Are you sure you want to permanently delete the |"},
			{RU, "Вы уверены, что хотите навсегда удалить |"}
		}
	},
	{
		"Browser.Delete.confirm.item",
		{
			{EN, "selected item"},
			{RU, "выделенный элемент"}
		}
	},
	{
		"Browser.Delete.confirm.items",
		{
			{EN, "selected items"},
			{RU, "выделенные элементы"}
		}
	},
	{
		"Browser.ShowHidden",
		{
			{EN, "Show Hidden"},
			{RU, "Показать скрытые"}
		}
	},
	{
		"Browser.OpenFile",
		{
			{EN, "Open File"},
			{RU, "Открыть файл"}
		}
	},
	{
		"Browser.OpenFiles",
		{
			{EN, "Open Files"},
			{RU, "Открыть файлы"}
		}
	},
	{
		"Browser.OpenFolder",
		{
			{EN, "Open Folder"},
			{RU, "Открыть папку"}
		}
	},
	{
		"Browser.OpenObject",
		{
			{EN, "Open Object"},
			{RU, "Открыть объект"}
		}
	},
	{
		"Browser.SaveFile",
		{
			{EN, "Save File"},
			{RU, "Сохранить файл"}
		}
	},
	{
		"Browser.SaveFile.fileExists.title",
		{
			{EN, "Overwrite file?"},
			{RU, "Заменить файл?"}
		}
	},
	{
		"Browser.SaveFile.fileExists",
		{
			{EN, "File already exists. Overwrite it?"},
			{RU, "Файл уже существует. Заменить его?"}
		}
	},

	{
		"StatusIcon.verifiedRom.tooltip",
		{
			{
				EN,
				"This is a known clean game image.\n"
				"PCB emulation is 100% accurate."
			},
			{
				RU,
				"Это известный качественный образ игры.\n"
				"Эмуляция платы (PCB) на 100% точная."
			}
		}
	},
	{
		"StatusIcon.unverifiedRom.tooltip",
		{
			{
				EN,
				"This is not a verified game image.\n"
				"PCB emulation is relying on heuristics."
			},
			{
				RU,
				"Этот образ игры не проверен.\n"
				"При эмуляции платы (PCB) будет использоваться эвристика."
			}
		}
	},

	{
		"ResetDrivers.message.title",
		{
			{EN, "Reset drivers"},
			{RU, "Сброс драйверов"}
		}
	},
	{
		"ResetDrivers.message",
		{
			{
				EN,
				"Hardware drivers have been reset according "
				"to the `--resetdrivers` command-line option.\n\n"
				"Please reconfigure drivers in the “Settings” → “Drivers” "
				"window that will now open."
			},
			{
				RU,
				"Драйверы оборудования были сброшены согласно "
				"параметру командной строки `--resetdrivers`.\n\n"
				"Пожалуйста, выберите новые настройки драйверов в окне "
				"«Настройки» → «Драйверы», которое сейчас откроется."
			}
		}
	},

	{
		"Rewind.HistoryExhausted",
		{
			{EN, "Rewind history exhausted"},
			{RU, "История перемотки исчерпана"}
		}
	},

	{
		"States.incompatibleFormat",
		{
			{EN, "[|] is in incompatible format"},
			{RU, "[|] имеет несовместимый формат"}
		}
	},
	{
		"States.Loaded",
		{
			{EN, "Loaded"},
			{RU, "Загружено"}
		}
	},
	{
		"States.NotFound",
		{
			{EN, "[|] not found"},
			{RU, "[|] не найдено"}
		}
	},
	{
		"States.FailedToSave",
		{
			{EN, "Failed to save [|]"},
			{RU, "Не удалось сохранить [|]"}
		}
	},
	{
		"States.UnableToWriteToDisk",
		{
			{EN, "Unable to write [|] to disk"},
			{RU, "Не удаётся записать [|] на диск"}
		}
	},
	{
		"States.Saved",
		{
			{EN, "Saved [|]"},
			{RU, "Сохранено [|]"}
		}
	},

	{
		"Patch.ipsWarning",
		{
			{
				EN,
				"(You’re seeing this prompt because IPS is a terrible patch-file format, "
				"and nobody can agree on whether SNES ROMs should be headered or not.\n"
				"Please consider asking the patch author to use BPS patches instead.)\n\n"
				"Does this IPS patch expect to be applied to a headered ROM?\n"
				"If you’re not sure, try “No”, and if it fails to work, try again with “Yes”."
			},
			{
				RU,
				"(Вы видите этот запрос потому, что IPS — ужасный формат файлов патчей, "
				"и нет единого мнения, должны ли SNES-игры снабжаться заголовками.\n"
				"Пожалуйста, попробуйте попросить автора патча использовать формат BPS.)\n\n"
				"Предусмотрена ли в этом IPS-патче возможность применения к игре с заголовком?\n"
				"Если вы не уверены, попробуйте «Нет», а если не сработает, попробуйте "
				"снова с ответом «Да»."
			}
		}
	},
	{
		"Patch.ensureHeaderless",
		{
			{EN, "Please ensure you are using the correct (headerless) ROM for this patch."},
			{RU, "Пожалуйста, удостоверьтесь, что используете для этого патча правильный (без заголовка) образ."}
		}
	},

	{
		"Movies.PlayMovie",
		{
			{EN, "Play Movie"},
			{RU, "Воспроизвести видео"}
		}
	},
	{
		"Movies.Movies",
		{
			{EN, "Movies"},
			{RU, "Видеозаписи"}
		}
	},
	{
		"Movies.playbackStarted",
		{
			{EN, "Movie playback started"},
			{RU, "Началось воспроизведение видео"}
		}
	},
	{
		"Movies.playbackStopped",
		{
			{EN, "Movie playback stopped"},
			{RU, "Воспроизведение видео остановлено"}
		}
	},
	{
		"Movies.formatNotSupported",
		{
			{EN, "Movie format is not supported"},
			{RU, "Формат видео не поддерживается"}
		}
	},
	{
		"Movies.recordingStarted",
		{
			{EN, "Movie recording started"},
			{RU, "Началась запись видео"}
		}
	},
	{
		"Movies.SaveMovie",
		{
			{EN, "Save Movie"},
			{RU, "Сохранить видео"}
		}
	},
	{
		"Movies.MovieRecorded",
		{
			{EN, "Movie recorded"},
			{RU, "Видео записано"}
		}
	},
	{
		"Movies.MovieNotRecorded",
		{
			{EN, "Movie not recorded"},
			{RU, "Видео не записано"}
		}
	},
	{
		"Movies.cantRecord",
		{
			{EN, "Movie could not be recorded"},
			{RU, "Не удаётся записать видео"}
		}
	}
	/*{
		"",
		{
			{EN, ""},
			{RU, ""}
		}
	}*/
};

static map<string, map<uint8_t, string>> deviceStrings = {
	{
		"Gamepad",
		{
			{RU, "Геймпад"},
			{JP, "ゲームパッド"}
		}
	},
	{
		"Mouse",
		{
			{RU, "Мышь"},
			{JP, "マウス"}
		}
	},
	{
		"Super Multitap",
		{
			{JP, "スーパーマルチタップ"}
		}
	},
	{
		"Super Scope",
		{
			{JP, "スーパースコップ"}
		}
	},
	{
		"Justifier",
		{
			{JP, "1挺のジャスティファイアー"}
		}
	},
	{
		"Justifiers",
		{
			{JP, "2挺のジャスティファイアー"}
		}
	},
	{
		"Satellaview",
		{
			{JP, "サテラビュー"}
		}
	}
};

static map<string, map<uint8_t, string>> hotkeyStrings = {
	{
		"Toggle Mouse Capture",
		{
			{RU, "Захватить указатель мыши"}
		}
	},
	{
		"Toggle Cheat Codes",
		{
			{RU, "Включить чит-коды"}
		}
	},
	{
		"Rewind",
		{
			{RU, "Перемотать назад (Rewind)"}
		}
	},
	{
		"Load Undo State",
		{
			{RU, "Загрузить состояние отмены действия"}
		}
	},
	{
		"Load Redo State",
		{
			{RU, "Загрузить состояния повтора действия"}
		}
	},
	{
		"Decrement State Slot",
		{
			{RU, "Предыдущий слот быстрого сохранения"}
		}
	},
	{
		"Increment State Slot",
		{
			{RU, "Следующий слот быстрого сохранения"}
		}
	},
	{
		"Fast Forward",
		{
			{RU, "Перемотать вперёд (Fast Forward)"}
		}
	},
	{
		"Frame Advance",
		{
			{EN, "Next frame in Frame Advance mode"},
			{RU, "Следующий кадр в покадровом режиме"}
		}
	},
	{
		"Decrease HD Mode 7",
		{
			{RU, "Уменьшить разрешение HD Mode 7"}
		}
	},
	{
		"Increase HD Mode 7",
		{
			{RU, "Увеличить разрешение HD Mode 7"}
		}
	},
	{
		"Toggle Supersampling",
		{
			{RU, "Включить избыточную выборку (supersampling)"}
		}
	},
	{
		"Reset Emulation",
		{
			{RU, "Сбросить эмуляцию"}
		}
	},
	{
		"Quit Emulator",
		{
			{RU, "Выйти из эмулятора"}
		}
	}
};

// Not a subject for translation.
static map<string, string> deviceStringsToRegularStrings = {
	{
		"None", "Common.None"
	}
};

// Not a subject for translation.
static map<string, string> hotkeyStringsToRegularStrings = {
	{
		"Toggle Fullscreen", "Menu.Settings.Size.FullScreenMode"
	},
	{
		"Toggle Pseudo-Fullscreen", "Menu.Settings.Size.PseudoFullScreenMode"
	},
	{
		"Toggle Mute", "Menu.Settings.MuteAudio"
	},
	{
		"Save State", "Tools.SaveState"
	},
	{
		"Load State", "Tools.LoadState"
	},
	{
		"Capture Screenshot", "Tools.TakeScreenshot"
	},
	{
		"Pause Emulation", "Tools.RunMode.PauseEmulation"
	}
};