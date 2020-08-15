/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

namespace bsnesMt::strings {

using std::map, std::string;

const uint8_t EN = 1, // English
              RU = 2, // Russian
              JA = 3, // Japanese
              IT = 4; // Italian

static map<string, map<uint8_t, string>> strings = {
	{
		"Common.Yes",
		{
			{EN, u8"Yes"},
			{RU, u8"Да"},
			{JA, u8"はい"},
			{IT, u8"Si"}
		}
	},
	{
		"Common.No",
		{
			{EN, u8"No"},
			{RU, u8"Нет"},
			{JA, u8"いいえ"},
			{IT, u8"No"}
		}
	},
	{
		"Common.Cancel",
		{
			{EN, u8"Cancel"},
			{RU, u8"Отмена"},
			{JA, u8"キャンセル"},
			{IT, u8"Cancella"}
		}
	},
	{
		"Common.Always",
		{
			{EN, u8"Always"},
			{RU, u8"Всегда"},
			{IT, u8"Sempre"}
		}
	},
	{
		"Common.AreYouSure",
		{
			{EN, u8"Are you sure?"},
			{RU, u8"Вы уверены?"},
			{IT, u8"Sei sicuro?"}
		}
	},
	{
		"Common.Open",
		{
			{EN, u8"Open"},
			{RU, u8"Открыть"},
			{JA, u8"開く"},
			{IT, u8"Apri"}
		}
	},
	{
		"Common.Load",
		{
			{EN, u8"Load"},
			{RU, u8"Загрузить"},
			{IT, u8"Carica"}
		}
	},
	{
		"Common.Save",
		{
			{EN, u8"Save"},
			{RU, u8"Сохранить"},
			{JA, u8"保存"},
			{IT, u8"Salva"}
		}
	},
	{
		"Common.Add",
		{
			{EN, u8"Add"},
			{RU, u8"Добавить"},
			{IT, u8"Aggiungi"}
		}
	},
	{
		"Common.Remove",
		{
			{EN, u8"Remove"},
			{RU, u8"Удалить"},
			{IT, u8"Rimuovi"}
		}
	},
	{
		"Common.Delete",
		{
			{EN, u8"Delete"},
			{RU, u8"Удалить"},
			{IT, u8"Cancella"}
		}
	},
	{
		"Common.Rename",
		{
			{EN, u8"Rename"},
			{RU, u8"Переименовать"},
			{IT, u8"Rinomina"}
		}
	},
	{
		"Common.Reset",
		{
			{EN, u8"Reset"},
			{RU, u8"Сброс"},
			{JA, u8"リセット"},
			{IT, u8"Resetta"}
		}
	},
	{
		"Common.Clear",
		{
			{EN, u8"Clear"},
			{RU, u8"Очистить"},
			{IT, u8"Pulisci"}
		}
	},
	{
		"Common.None",
		{
			{EN, u8"None"},
			{RU, u8"Нет"},
			{JA, u8"なし"},
			{IT, u8"Niente"}
		}
	},
	{
		"Common.Disabled",
		{
			{EN, u8"Disabled"},
			{RU, u8"Отключено"},
			{IT, u8"Disabilita"}
		}
	},
	{
		"Common.Default",
		{
			{EN, u8"Default"},
			{RU, u8"По умолчанию"},
			{IT, u8"Predefinito"}
		}
	},
	{
		"Common.Name",
		{
			{EN, u8"Name"},
			{RU, u8"Название"},
			{IT, u8"Nome"}
		}
	},
	{
		"Common.Date",
		{
			{EN, u8"Date"},
			{RU, u8"Дата"},
			{IT, u8"Data"}
		}
	},
	{
		"Common.Success",
		{
			{EN, u8"Success"},
			{RU, u8"Успех"},
			{IT, u8"Successo"}
		}
	},
	{
		"Common.Failure",
		{
			{EN, u8"Failure"},
			{RU, u8"Неудача"},
			{IT, u8"Fallito"}
		}
	},
	{
		"Common.Error",
		{
			{EN, u8"Error"},
			{RU, u8"Ошибка"},
			{IT, u8"Errore"}
		}
	},
	{
		"Common.Warning",
		{
			{EN, u8"Warning"},
			{RU, u8"Внимание"},
			{IT, u8"Attenzione"}
		}
	},
	{
		"Common.Auto",
		{
			{EN, u8"Auto"},
			{RU, u8"Авто"},
			{IT, u8"Automatico"}
		}
	},
	{
		"Common.Video",
		{
			{EN, u8"Video"},
			{RU, u8"Видео"},
			{IT, u8"Video"}
		}
	},
	{
		"Common.Audio",
		{
			{EN, u8"Audio"},
			{RU, u8"Звук"},
			{IT, u8"Audio"}
		}
	},
	{
		"Common.Fps", // Frames per second (frame-rate unit).
		{
			{EN, u8"FPS"},
			{RU, u8"к/с"},
			{IT, u8"FPS"}
		}
	},
	{
		"Common.Hz",
		{
			{EN, u8"Hz"},
			{RU, u8"Гц"},
			{IT, u8"Hz"}
		}
	},
	{
		"Common.number",
		{
			{EN, u8"#"},
			{RU, u8"№"},
			{IT, u8"#"}
		}
	},

	{
		"Menu.File",
		{
			{EN, u8"File"},
			{RU, u8"Файл"},
			{IT, u8"File"}
		}
	},
	{
		"Menu.File.OpenGame",
		{
			{EN, u8"Open Game"},
			{RU, u8"Открыть игру"},
			{JA, u8"ゲームを読み込み"},
			{IT, u8"Apri un Gioco"}
		}
	},
	{
		"Menu.File.OpenRecentGame",
		{
			{EN, u8"Open Recent Game"},
			{RU, u8"Открыть недавнюю игру"},
			{JA, u8"最新ゲームを読み込み"},
			{IT, u8"Apri un gioco lanciato di recente"}
		}
	},
	{
		"Menu.File.OpenRecentGame.ClearList",
		{
			{EN, u8"Clear List"},
			{RU, u8"Очистить список"},
			{JA, u8"全部を消す"},
			{IT, u8"Pulisci Lista"}
		}
	},
	{
		"Menu.File.OpenRecentGame.NoRecentGames",
		{
			{EN, u8"No Recent Games"},
			{RU, u8"Нет недавних игр"},
			{IT, u8"Nessun Gioco Recente"}
		}
	},
	{
		"Menu.File.CloseGame",
		{
			{EN, u8"Close Game"},
			{RU, u8"Закрыть игру"},
			{JA, u8"ゲームをアンロード"},
			{IT, u8"Chiudi Gioco"}
		}
	},
	{
		"Menu.File.Exit",
		{
			{EN, u8"Exit"},
			{RU, u8"Выход"},
			{JA, u8"終了"},
			{IT, u8"Esci"}
		}
	},

	{
		"Menu.System",
		{
			{EN, u8"System"},
			{RU, u8"Система"},
			{JA, u8"システム"},
			{IT, u8"Sistema"}
		}
	},
	{
		"Menu.System.ControllerPort",
		{
			{EN, u8"Controller Port"},
			{RU, u8"Порт контроллера"},
			{JA, u8"コントローラポート"},
			{IT, u8"Porta del Controller"}
		}
	},
	{
		"Menu.System.ExpansionPort",
		{
			{EN, u8"Expansion Port"},
			{RU, u8"Порт расширения"},
			{JA, u8"拡張ポート"},
			{IT, u8"Espansione della Porta"}
		}
	},

	{
		"Menu.Settings.Size",
		{
			{EN, u8"Size"},
			{RU, u8"Размер"},
			{IT, u8"Dimensione"}
		}
	},
	{
		"Menu.Settings.Size.ShrinkWindowToSize",
		{
			{EN, u8"Shrink Window to Size"},
			{RU, u8"Подогнать окно под размер"},
			{IT, u8"Riduci la finestra alle dimensioni"}
		}
	},
	{
		"Menu.Settings.Size.CenterWindow",
		{
			{EN, u8"Center Window"},
			{RU, u8"Центрировать окно"},
			{IT, u8"Finestra centrata"}
		}
	},
	{
		"Menu.Settings.Size.FullScreenMode",
		{
			{EN, u8"Full-Screen Mode"},
			{RU, u8"Полноэкранный режим"},
			{IT, u8"Modalità Schermo intero"}
		}
	},
	{
		"Menu.Settings.Size.PseudoFullScreenMode",
		{
			{EN, u8"Pseudo-Full-Screen Mode"},
			{RU, u8"Псевдополноэкранный режим"},
			{IT, u8"Modalità Pseudo schermo intero"}
		}
	},
	{
		"Menu.Settings.Output",
		{
			{EN, u8"Output"},
			{RU, u8"Изображение"},
			{IT, u8"Output"}
		}
	},
	{
		"Menu.Settings.Output.Center",
		{
			{EN, u8"Center"},
			{RU, u8"По центру"}
		}
	},
	{
		"Menu.Settings.Output.PixelPerfect",
		{
			{EN, u8"Pixel-Perfect"},
			{RU, u8"Целочисленное масштабирование"}
		}
	},
	{
		"Menu.Settings.Output.Scale",
		{
			{EN, u8"Scale"},
			{RU, u8"Масштабирование с сохранением пропорций"}
		}
	},
	{
		"Menu.Settings.Output.Stretch",
		{
			{EN, u8"Stretch"},
			{RU, u8"Растяжение без сохранения пропорций"}
		}
	},
	{
		"Menu.Settings.Output.AspectRatioCorrection",
		{
			{EN, u8"Aspect-Ratio Correction"},
			{RU, u8"Коррекция соотношения сторон"}
		}
	},
	{
		"Menu.Settings.Output.ShowOverscanArea",
		{
			{EN, u8"Show Overscan Area"},
			{RU, u8"Показать область «overscan»"}
		}
	},
	{
		"Menu.Settings.Output.scalingInfo",
		{
			{EN, u8"Scaling Info in Status Bar"},
			{RU, u8"Информация о масштабировании в строке состояния"}
		}
	},
	{
		"Menu.Settings.Output.HiresBlurEmulation",
		{
			{EN, u8"Hires Blur Emulation"},
			{RU, u8"Эмуляция размытия в режиме высокого разрешения"}
		}
	},
	{
		"Menu.Settings.Filter",
		{
			{EN, u8"Filter"},
			{RU, u8"Фильтр"}
		}
	},
	{
		"Menu.Settings.Shader",
		{
			{EN, u8"Shader"},
			{RU, u8"Шейдер"}
		}
	},
	{
		"Menu.Settings.Shader.Blur",
		{
			{EN, u8"Blur"},
			{RU, u8"Размытие"}
		}
	},
	{
		"Menu.Settings.MuteAudio",
		{
			{EN, u8"Mute Audio"},
			{RU, u8"Выключить звук"}
		}
	},
	{
		"Menu.Settings.ShowStatusBar",
		{
			{EN, u8"Show Status Bar"},
			{RU, u8"Показать строку состояния"}
		}
	},
	// For settings-sections' menu-items, see "Settings.*".
	{
		"Menu.Settings.OpenSettingsFolder",
		{
			{EN, u8"Open Settings Folder"},
			{RU, u8"Открыть папку настроек"}
		}
	},

	{
		"Menu.Help",
		{
			{EN, u8"Help"},
			{RU, u8"Справка"},
			{JA, u8"ヘルプ"}
		}
	},
	{
		"Menu.Help.About",
		{
			{EN, u8"About |"},
			{RU, u8"О программе |"},
			{JA, u8"| について"}
		}
	},

	{
		"Settings",
		{
			{EN, u8"Settings"},
			{RU, u8"Настройки"},
			{JA, u8"設定"}
		}
	},

	// Used in "Hotkeys", "Input" and "Paths" settings.
	{
		"Settings.Common.Assign",
		{
			{EN, u8"Assign"},
			{RU, u8"Задать"}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.AssignLowercase",
		{
			{EN, u8"assign"},
			{RU, u8"задать"}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.Mapping",
		{
			{EN, u8"Mapping"},
			{RU, u8"Соответствие"}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.MappingAssigned",
		{
			{EN, u8"Mapping assigned."},
			{RU, u8"Соответствие задано."}
		}
	},
	// Used in "Hotkeys" and "Input" settings.
	{
		"Settings.Common.PressKeyOrButtonForMapping",
		{
			{EN, u8"Press a key or button for mapping"},
			{RU, u8"Нажмите клавишу или кнопку для привязки"}
		}
	},
	// Used in "Emulator" and "Enhancements" settings.
	{
		"Settings.Common.FrameLowercase",
		{
			{EN, u8"frame"},
			{RU, u8"кадр"}
		}
	},

	// "Settings.Video" -- see "Common.Video".
	{
		"Settings.Video.ColorAdjustment",
		{
			{EN, u8"Color Adjustment"},
			{RU, u8"Настройка цвета"}
		}
	},
	{
		"Settings.Video.Luminance",
		{
			{EN, u8"Luminance"},
			{RU, u8"Яркость"}
		}
	},
	{
		"Settings.Video.Saturation",
		{
			{EN, u8"Saturation"},
			{RU, u8"Насыщенность"}
		}
	},
	{
		"Settings.Video.Gamma",
		{
			{EN, u8"Gamma"},
			{RU, u8"Контрастность"}
		}
	},
	{
		"Settings.Video.DimVideoWhenIdle",
		{
			{EN, u8"Dim video when idle"},
			{RU, u8"Затемнять изображение при простое"}
		}
	},
	{
		"Settings.Video.DimVideoWhenIdle.tooltip",
		{
			{EN, u8"Darkens the video to indicate that the emulation is not running."},
			{RU, u8"Затемняет изображение, чтобы показать, что эмуляция приостановлена."}
		}
	},
	{
		"Settings.Video.DrawSnowEffectWhenIdle",
		{
			{EN, u8"Draw snow effect when idle"},
			{RU, u8"Применять эффект снега при простое"}
		}
	},

	// "Settings.Audio" -- see "Common.Audio".
	{
		"Settings.Audio.Effects",
		{
			{EN, u8"Effects"},
			{RU, u8"Эффекты"}
		}
	},
	{
		"Settings.Audio.Skew",
		{
			{EN, u8"Skew"},
			{RU, u8"Частота"}
		}
	},
	{
		"Settings.Audio.Skew.tooltip",
		{
			{
				EN,
				u8"Adjusts the audio frequency by the skew amount (in Hz).\n\n"
				u8"This is essentially static rate control.\n"
				u8"First, enable both video and audio sync.\n"
				u8"Then, raise or lower this value to try to reduce errors.\n"
				u8"One direction will help video, but hurt audio.\n"
				u8"The other direction will do the reverse.\n"
				u8"The idea is to find the best middle ground.\n\n"
				u8"You should leave this at 0 when using dynamic rate control."
			},
			{
				RU,
				u8"Изменяет частоту дискретизации на заданную величину (в Гц).\n\n"
				u8"По сути это статическое управление частотой.\n"
				u8"Сначала включите синхронизацию как для видео, так и для звука.\n"
				u8"Затем попробуйте увеличить или уменьшить это значение для уменьшения ошибок.\n"
				u8"Изменение в одном направлении положительно скажется на видео, но отрицательно — на звуке.\n"
				u8"Изменение в другом направлении приведёт к обратному результату.\n"
				u8"Смысл в том, чтобы найти наилучший компромисс.\n\n"
				u8"При динамическом управлении частотой используйте значение 0."
			}
		}
	},
	{
		"Settings.Audio.Volume",
		{
			{EN, u8"Volume"},
			{RU, u8"Громкость"}
		}
	},
	{
		"Settings.Audio.Volume.tooltip",
		{
			{
				EN,
				u8"Adjusts the audio output volume.\n\n"
				u8"You should not use values above 100%, if possible!\n"
				u8"If you do, audio clipping distortion can occur."
			},
			{
				RU,
				u8"Изменяет громкость звука.\n\n"
				u8"По возможности не следует использовать значения выше 100%!\n"
				u8"В противном случае возможны искажения из-за превышения максимально возможного уровня."
			}
		}
	},
	{
		"Settings.Audio.Balance",
		{
			{EN, u8"Balance"},
			{RU, u8"Панорама"}
		}
	},
	{
		"Settings.Audio.Balance.tooltip",
		{
			{
				EN,
				u8"Pans audio to the left (lower values) or right (higher values).\n\n"
				u8"50% (centered) is the recommended setting."
			},
			{
				RU,
				u8"Панорамирует звук влево (меньшие значения) или вправо (более высокие значения).\n\n"
				u8"Рекомендуемое значение — 50% (по центру)."
			}
		}
	},
	{
		"Settings.Audio.MuteWhenUnfocused",
		{
			{EN, u8"Mute when unfocused"},
			{RU, u8"Отключать звук при неактивном окне программы"}
		}
	},

	{
		"Settings.Input",
		{
			{EN, u8"Input"},
			{RU, u8"Устройства ввода"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost",
		{
			{EN, u8"When focus is lost"},
			{RU, u8"При неактивном окне программы"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost.PauseEmulation",
		{
			{EN, u8"Pause emulation"},
			{RU, u8"Приостановить эмуляцию"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost.BlockInput",
		{
			{EN, u8"Block input"},
			{RU, u8"Блокировать ввод"}
		}
	},
	{
		"Settings.Input.WhenFocusIsLost.AllowInput",
		{
			{EN, u8"Allow input"},
			{RU, u8"Разрешить ввод"}
		}
	},
	{
		"Settings.Input.Port",
		{
			{EN, u8"Port"},
			{RU, u8"Порт"}
		}
	},
	{
		"Settings.Input.Device",
		{
			{EN, u8"Device"},
			{RU, u8"Устройство"}
		}
	},
	{
		"Settings.Input.TurboRate",
		{
			{EN, u8"Turbo rate"},
			{RU, u8"Частота турбо"}
		}
	},
	{
		"Settings.Input.TurboRate.tooltip",
		{
			{EN, u8"The number of frames to wait between toggling turbo buttons."},
			{RU, u8"Количество кадров между срабатываниями турбо-кнопок."}
		}
	},
	{
		"Settings.Input.MouseLeft",
		{
			{EN, u8"Mouse Left"},
			{RU, u8"Левая кнопка мыши"}
		}
	},
	{
		"Settings.Input.MouseMiddle",
		{
			{EN, u8"Mouse Middle"},
			{RU, u8"Средняя кнопка мыши"}
		}
	},
	{
		"Settings.Input.MouseRight",
		{
			{EN, u8"Mouse Right"},
			{RU, u8"Правая кнопка мыши"}
		}
	},
	{
		"Settings.Input.MouseXAxis",
		{
			{EN, u8"Mouse X-axis"},
			{RU, u8"Мышь по оси X"}
		}
	},
	{
		"Settings.Input.MouseYAxis",
		{
			{EN, u8"Mouse Y-axis"},
			{RU, u8"Мышь по оси Y"}
		}
	},

	{
		"Settings.Hotkeys",
		{
			{EN, u8"Hotkeys"},
			{RU, u8"Горячие клавиши"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic",
		{
			{EN, u8"Combinational logic"},
			{RU, u8"Комбинационная логика"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.tooltip",
		{
			{
				EN,
				u8"Determines whether all or any mappings must be pressed to activate hotkeys.\n"
				u8"Use “AND” logic if you want keyboard combinations such as Ctrl+F to trigger a hotkey.\n"
				u8"Use “OR” logic if you want both a keyboard and joypad to trigger the same hotkey."
			},
			{
				RU,
				u8"Определяет, все или любое из соответствий требуется нажать для активации горячих клавиш.\n"
				u8"Используйте логику «И», если для активации горячих клавиш вам нужны такие сочетания клавиш, как Ctrl+F.\n"
				u8"Используйте логику «ИЛИ», если для активации одних и тех же горячих клавиш вы хотите использовать как клавиатуру, так и геймпад."
			}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.And",
		{
			{EN, u8"AND"},
			{RU, u8"И"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.And.tooltip",
		{
			{EN, u8"Every mapping must be pressed to activate a given hotkey."},
			{RU, u8"Для активации заданных горячих клавиш требуется нажать все соответствия."}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.Or",
		{
			{EN, u8"OR"},
			{RU, u8"ИЛИ"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.Or.tooltip",
		{
			{EN, u8"Any mapping can be pressed to activate a given hotkey."},
			{RU, u8"Для активации заданных горячих клавиш можно нажать любое из соответствий."}
		}
	},
	{
		"Settings.Hotkeys.Rewind.enableFirst",
		{
			{EN, u8"Please enable rewind support in “Settings” → “Emulator” first"},
			{RU, u8"Пожалуйста, сначала включите поддержку перемотки: «Настройки» → «Эмулятор»"}
		}
	},

	{
		"Settings.Paths",
		{
			{EN, u8"Paths"},
			{RU, u8"Пути"}
		}
	},
	{
		"Settings.Paths.Games",
		{
			{EN, u8"Games"},
			{RU, u8"Игры"}
		}
	},
	{
		"Settings.Paths.Patches",
		{
			{EN, u8"Patches"},
			{RU, u8"Патчи"}
		}
	},
	{
		"Settings.Paths.Saves",
		{
			{EN, u8"Saves"},
			{RU, u8"Сохранения"}
		}
	},
	{
		"Settings.Paths.Cheats",
		{
			{EN, u8"Cheats"},
			{RU, u8"Читы"}
		}
	},
	{
		"Settings.Paths.States",
		{
			{EN, u8"States"},
			{RU, u8"Быстрые сохранения"}
		}
	},
	{
		"Settings.Paths.Screenshots",
		{
			{EN, u8"Screenshots"},
			{RU, u8"Скриншоты"}
		}
	},
	{
		"Settings.Paths.LastRecentlyUsed",
		{
			{EN, u8"last recently used"},
			{RU, u8"последняя использованная папка"}
		}
	},
	{
		"Settings.Paths.SameAsLoadedGame",
		{
			{EN, u8"same as loaded game"},
			{RU, u8"папка текущей игры"}
		}
	},

	{
		"Settings.Emulator",
		{
			{EN, u8"Emulator"},
			{RU, u8"Эмулятор"}
		}
	},
	{
		"Settings.Emulator.General",
		{
			{EN, u8"General"},
			{RU, u8"Общие"}
		}
	},
	{
		"Settings.Emulator.General.warnOnUnverifiedGames",
		{
			{EN, u8"Warn when opening games that have not been verified"},
			{RU, u8"Предупреждать при открытии непроверенных игр"}
		}
	},
	{
		"Settings.Emulator.General.autoSaveMemory",
		{
			{EN, u8"Auto-save memory periodically"},
			{RU, u8"Периодически автоматически сохранять память"}
		}
	},
	{
		"Settings.Emulator.General.autoSaveStateOnUnload",
		{
			{EN, u8"Auto-save undo state when unloading games"},
			{RU, u8"Автоматически сохранять состояние отмены действия при закрытии игр"}
		}
	},
	{
		"Settings.Emulator.General.AutoResumeOnLoad",
		{
			{EN, u8"Auto-resume on load"},
			{RU, u8"Автоматически возобновлять при загрузке"}
		}
	},
	{
		"Settings.Emulator.General.UseNativeFileDialogs",
		{
			{EN, u8"Use native file dialogs"},
			{RU, u8"Использовать стандартные окна открытия/сохранения файлов"}
		}
	},
	{
		"Settings.Emulator.FastForward",
		{
			{EN, u8"Fast Forward"},
			{RU, u8"Перемотка вперёд (Fast Forward)"}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip",
		{
			{EN, u8"Frame skip"},
			{RU, u8"Пропуск кадров"}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip.tooltip",
		{
			{
				EN,
				u8"Sets how many frames to skip while fast forwarding.\n"
				u8"Frame skipping allows a higher maximum fast forwarding frame rate."
			},
			{
				RU,
				u8"Задаёт, сколько кадров пропускать при перемотке вперёд.\n"
				u8"Пропуск кадров позволяет увеличить скорость перемотки."
			}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip.Frames2to4", // 2-4
		{
			{EN, u8"| frames"},
			{RU, u8"| кадра"}
		}
	},
	{
		"Settings.Emulator.FastForward.FrameSkip.Frames", // 4+
		{
			{EN, u8"| frames"},
			{RU, u8"| кадров"}
		}
	},
	{
		"Settings.Emulator.FastForward.Limiter",
		{
			{EN, u8"Limiter"},
			{RU, u8"Ограничение"}
		}
	},
	{
		"Settings.Emulator.FastForward.Limiter.tooltip",
		{
			{EN, u8"Sets the maximum speed when fast forwarding."},
			{RU, u8"Задаёт максимальную скорость при перемотке вперёд."}
		}
	},
	{
		"Settings.Emulator.FastForward.mute",
		{
			{EN, u8"Mute while fast forwarding"},
			{RU, u8"Отключать звук при перемотке вперёд"}
		}
	},
	{
		"Settings.Emulator.Rewind",
		{
			{EN, u8"Rewind"},
			{RU, u8"Перемотка назад (Rewind)"}
		}
	},
	{
		"Settings.Emulator.Rewind.Frequency",
		{
			{EN, u8"Frequency"},
			{RU, u8"Частота"}
		}
	},
	{
		"Settings.Emulator.Rewind.Frequency.everyFrames",
		{
			{EN, u8"Every | frames"},
			{RU, u8"Каждые | кадров"}
		}
	},
	{
		"Settings.Emulator.Rewind.Length",
		{
			{EN, u8"Length"},
			{RU, u8"Длина"}
		}
	},
	{
		"Settings.Emulator.Rewind.Length.states",
		{
			{EN, u8"| states"},
			{RU, u8"| состояний"}
		}
	},
	{
		"Settings.Emulator.Rewind.mute",
		{
			{EN, u8"Mute while rewinding"},
			{RU, u8"Отключать звук при перемотке назад"}
		}
	},

	{
		"Settings.Enhancements",
		{
			{EN, u8"Enhancements"},
			{RU, u8"Улучшения"}
		}
	},
	{
		"Settings.Enhancements.FastMode",
		{
			{EN, u8"Fast mode"},
			{RU, u8"Быстрый режим"}
		}
	},
	{
		"Settings.Enhancements.RunAhead",
		{
			{EN, u8"Run-Ahead"},
			{RU, u8"Опережающая эмуляция (Run-Ahead)"}
		}
	},
	{
		// "Two-four frames"
		"Settings.Enhancements.RunAhead.Frames",
		{
			{EN, u8"frames"},
			{RU, u8"кадра"}
		}
	},
	{
		// "One frame"
		"Settings.Enhancements.RunAhead.One",
		{
			{EN, u8"One"},
			{RU, u8"Один"}
		}
	},
	{
		// "Two frames"
		"Settings.Enhancements.RunAhead.Two",
		{
			{EN, u8"Two"},
			{RU, u8"Два"}
		}
	},
	{
		"Settings.Enhancements.RunAhead.Three",
		{
			{EN, u8"Three"},
			{RU, u8"Три"}
		}
	},
	{
		"Settings.Enhancements.RunAhead.Four",
		{
			{EN, u8"Four"},
			{RU, u8"Четыре"}
		}
	},
	{
		"Settings.Enhancements.Overclocking",
		{
			{EN, u8"Overclocking"},
			{RU, u8"Разгон"}
		}
	},
	{
		"Settings.Enhancements.Ppu.Video",
		{
			{EN, u8"video"},
			{RU, u8"видео"}
		}
	},
	{
		"Settings.Enhancements.Ppu.Deinterlace",
		{
			{EN, u8"Deinterlace"},
			{RU, u8"Устранение чересстрочности"}
		}
	},
	{
		"Settings.Enhancements.Ppu.NoSpriteLimit",
		{
			{EN, u8"No sprite limit"},
			{RU, u8"Не ограничивать количество спрайтов"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.FastPpuOnly",
		{
			{EN, u8"fast PPU only"},
			{RU, u8"только в быстром режиме PPU"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.Scale",
		{
			{EN, u8"Scale"},
			{RU, u8"Масштаб"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.PerspectiveCorrection",
		{
			{EN, u8"Perspective correction"},
			{RU, u8"Коррекция перспективы"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.Supersampling",
		{
			{EN, u8"Supersampling"},
			{RU, u8"Избыточная выборка"}
		}
	},
	{
		"Settings.Enhancements.hdMode7.HdToSdMosaic",
		{
			{EN, u8"HD→SD Mosaic"},
			{RU, u8"Мозаичность HD→SD"}
		}
	},
	{
		"Settings.Enhancements.Dsp.Audio",
		{
			{EN, u8"audio"},
			{RU, u8"звук"}
		}
	},
	{
		"Settings.Enhancements.Dsp.CubicInterpolation",
		{
			{EN, u8"Cubic interpolation"},
			{RU, u8"Кубическая интерполяция"}
		}
	},
	{
		"Settings.Enhancements.Coprocessors",
		{
			{EN, u8"Coprocessors"},
			{RU, u8"Сопроцессоры"}
		}
	},
	{
		"Settings.Enhancements.Coprocessors.PreferHle",
		{
			{EN, u8"Prefer high-level emulation (HLE)"},
			{RU, u8"Предпочитать высокоуровневую эмуляцию (HLE)"}
		}
	},
	{
		"Settings.Enhancements.Coprocessors.PreferHle.tooltip",
		{
			{
				EN,
				u8"When checked, less accurate HLE emulation will always be used when available.\n"
				u8"When unchecked, HLE will only be used when low-level-emulation (LLE) firmware is missing."
			},
			{
				RU,
				u8"Когда включено, менее точная высокоуровневая эмуляция будет использоваться всегда, когда возможно.\n"
				u8"Когда выключено, высокоуровневая эмуляция будет использоваться только при отсутствии низкоуровневой (LLE) прошивки."
			}
		}
	},
	{
		"Settings.Enhancements.GameEnhancements",
		{
			{EN, u8"Game Enhancements"},
			{RU, u8"Улучшения игр"}
		}
	},
	{
		"Settings.Enhancements.GameEnhancements.Hotfixes",
		{
			{EN, u8"Hotfixes"},
			{RU, u8"Исправления ошибок"}
		}
	},
	{
		"Settings.Enhancements.GameEnhancements.Hotfixes.tooltip",
		{
			{
				EN,
				u8"Even commercially licensed and officially released software sometimes shipped with bugs.\n"
				u8"This option will correct certain issues that occurred even on real hardware."
			},
			{  
				RU,
				u8"Даже в коммерчески лицензированных и официально выпущенных программах иногда есть ошибки.\n"
				u8"Этот параметр исправит определённые проблемы, которые имели место на реальном оборудовании."
			}
		}
	},

	{
		"Settings.Compatibility",
		{
			{EN, u8"Compatibility"},
			{RU, u8"Совместимость"}
		}
	},
	{
		"Settings.Compatibility.entropy",
		{
			{EN, u8"Entropy (randomization)"},
			{RU, u8"Энтропия (степень случайности)"}
		}
	},
	{
		"Settings.Compatibility.entropy.None.tooltip",
		{
			{
				EN,
				u8"All memory and registers are initialized to constant values at startup.\n"
				u8"Use this for compatibility with very old demoscene homebrew games."
			},
			{
				RU,
				u8"При запуске вся память и регистры устанавливаются в постоянные значения.\n"
				u8"Используйте этот вариант для совместимости с очень старыми самодельными играми демосцены."
			}
		}
	},
	{
		"Settings.Compatibility.entropy.Low",
		{
			{EN, u8"Low"},
			{RU, u8"Низкая"}
		}
	},
	{
		"Settings.Compatibility.entropy.Low.tooltip",
		{
			{
				EN,
				u8"All memory is randomized with repeating patterns, all registers are randomized at startup.\n"
				u8"Use this for the most accurate representation of a real SNES."
			},
			{
				RU,
				u8"При запуске вся память заполняется повторяющимися случайными значениями, все регистры устанавливаются в случайные значения.\n"
				u8"Используйте этот вариант для наиболее точного соответствия реальной SNES."
			}
		}
	},
	{
		"Settings.Compatibility.entropy.High",
		{
			{EN, u8"High"},
			{RU, u8"Высокая"}
		}
	},
	{
		"Settings.Compatibility.entropy.High.tooltip",
		{
			{
				EN,
				u8"All memory and registers are randomized as much as possible.\n"
				u8"Use this when developing new SNES software to ensure maximum compatibility with real hardware."
			},
			{
				RU,
				u8"Вся память и регистры устанавливаются в максимально случайные значения.\n"
				u8"Используйте этот вариант при разработке новых программ для SNES,\n"
				u8"чтобы гарантировать максимальную совместимость с реальным оборудованием."
			}
		}
	},
	{
		"Settings.Compatibility.cpu.Processor",
		{
			{EN, u8"processor"},
			{RU, u8"процессор"}
		}
	},
	{
		"Settings.Compatibility.cpu.FastMath",
		{
			{EN, u8"Fast math"},
			{RU, u8"Быстрая математика"}
		}
	},
	{
		"Settings.Compatibility.cpu.FastMath.tooltip",
		{
			{
				EN,
				u8"CPU multiplication and division take time to complete on a real SNES.\n"
				u8"Older emulators did not simulate these delays, and provided results immediately.\n"
				u8"Some older ROM hacks do not wait for math operations to complete and need this hack."
			},
			{
				RU,
				u8"На реальной SNES умножение и деление средствами процессора занимает время.\n"
				u8"Старые эмуляторы не учитывали эти задержки и возвращали результат сразу.\n"
				u8"Этот параметр нужен некоторым старым ROM-хакам, которые не ждали завершения математических операций."
			}
		}
	},
	{
		"Settings.Compatibility.ppu.Video",
		{
			{EN, u8"video"},
			{RU, u8"видео"}
		}
	},
	{
		"Settings.Compatibility.ppu.NoVramBlocking",
		{
			{EN, u8"No video-memory (VRAM) blocking"},
			{RU, u8"Не блокировать видеопамять (VRAM)"}
		}
	},
	{
		"Settings.Compatibility.ppu.NoVramBlocking.tooltip",
		{
			{
				EN,
				u8"This option enables emulating a bug in older releases of ZSNES and Snes9x where VRAM blocking was not emulated.\n"
				u8"A few older ROM hacks relied on this behavior, and will render graphics incorrectly if not enabled.\n"
				u8"Not only is this extremely inaccurate to real hardware, it also hurts the speed of the fast PPU.\n"
				u8"Do not enable this option unless you need to play a game that works incorrectly otherwise."
			},
			{
				RU,
				u8"Этот параметр включает эмуляцию ошибки старых версий ZSNES and Snes9x, где не было эмуляции блокировки видеопамяти.\n"
				u8"Некоторые старые ROM-хаки рассчитывали на это поведение и будут отрисовываться неправильно, если этот параметр не включить.\n"
				u8"Это не только сильно отличается от поведения реального оборудования, но и снижает быстродействие быстрого PPU.\n"
				u8"Не включайте этот параметр, если вам не требуется поиграть в игру, в противном случае работающую неправильно."
			}
		}
	},
	{
		"Settings.Compatibility.dsp.Audio",
		{
			{EN, u8"audio"},
			{RU, u8"звук"}
		}
	},
	{
		"Settings.Compatibility.dsp.EchoShadowRam",
		{
			{EN, u8"Echo shadow RAM"},
			{RU, u8"Отображать теневую память (echo shadow RAM)"}
		}
	},
	{
		"Settings.Compatibility.dsp.EchoShadowRam.tooltip",
		{
			{
				EN,
				u8"This option enables emulating a bug in ZSNES where echo RAM was treated as separate from APU RAM.\n"
				u8"Many older ROM hacks for “Super Mario World” relied on this behavior, and will crash without enabling this.\n"
				u8"It is, however, extremely inaccurate to real hardware and should not be enabled unless required."
			},
			{
				RU,
				u8"Этот параметр включает эмуляцию ошибки ZSNES, где отображаемая память (echo RAM) рассматривалась отдельно от памяти APU.\n"
				u8"Многие старые ROM-хаки «Super Mario World» рассчитывали на это поведение и не будут работать без включения этого параметра.\n"
				u8"Однако это сильно отличается от поведения реального оборудования, и не следует включать этот параметр без необходимости."
			}
		}
	},

	{
		"Settings.Drivers",
		{
			{EN, u8"Drivers"},
			{RU, u8"Драйверы"}
		}
	},
	{
		"Settings.Drivers.Driver",
		{
			{EN, u8"Driver"},
			{RU, u8"Драйвер"}
		}
	},
	{
		"Settings.Drivers.Change",
		{
			{EN, u8"Change"},
			{RU, u8"Изменить"}
		}
	},
	{
		"Settings.Drivers.Reload",
		{
			{EN, u8"Reload"},
			{RU, u8"Перезагрузить"}
		}
	},
	{
		"Settings.Drivers.ExclusiveMode",
		{
			{EN, u8"Exclusive mode"},
			{RU, u8"Эксклюзивный режим"}
		}
	},
	{
		"Settings.Drivers.Synchronize",
		{
			{EN, u8"Synchronize"},
			{RU, u8"Синхронизация"}
		}
	},
	{
		"Settings.Drivers.ActiveDriver",
		{
			{EN, u8"Active driver"},
			{RU, u8"Активный драйвер"}
		}
	},
	{
		"Settings.Drivers.changeConfirm.title",
		{
			{EN, u8"Change driver?"},
			{RU, u8"Изменить драйвер?"}
		}
	},
	{
		"Settings.Drivers.changeConfirm",
		{
			{
				EN,
				u8"Warning: incompatible drivers may cause the application to crash.\n"
				u8"It is highly recommended you unload your game first to be safe.\n"
				u8"Do you wish to proceed with the driver change now anyway?"
			},
			{
				RU,
				u8"Внимание: несовместимые драйверы могут привести к невозможности работы программы.\n"
				u8"Для безопасности настоятельно рекомендуется сначала закрыть вашу игру.\n"
				u8"Хотите ли вы изменить драйвер в любом случае?"
			}
		}
	},
	{
		"Settings.noteGameRestart",
		{
			{EN, u8"Note: some settings do not take effect until reloading the game."},
			{RU, u8"Примечание: некоторые настройки применяются только после перезагрузки игры."}
		}
	},
	{
		"Settings.Drivers.Video.failedToInitialize",
		{
			{EN, u8"Failed to initialize [|] video driver"},
			{RU, u8"Не удалось инициализировать видеодрайвер [|]"}
		}
	},
	{
		"Settings.Drivers.Video.FullScreenMonitor",
		{
			{EN, u8"Full-screen monitor"},
			{RU, u8"Монитор для полноэкранного режима"}
		}
	},
	{
		"Settings.Drivers.Video.FullScreenMonitor.tooltip",
		{
			{EN, u8"Sets which monitor video is sent to in full-screen mode."},
			{RU, u8"Задаёт, на какой монитор выводится изображение в полноэкранном режиме."}
		}
	},
	{
		"Settings.Drivers.Video.Format",
		{
			{EN, u8"Format"},
			{RU, u8"Формат"}
		}
	},
	{
		"Settings.Drivers.Video.ExclusiveMode.tooltip",
		{
			{
				EN,
				u8"Causes full-screen mode to take over all monitors.\n"
				u8"This allows adaptive sync to work better and reduces input latency.\n"
				u8"However, multi-monitor users should turn this option off.\n"
				u8"Note: Direct3D exclusive mode also does not honor the requested monitor."
			},
			{
				RU,
				u8"Приводит к тому, что в полноэкранном режиме изображение занимает все мониторы.\n"
				u8"Улучшает работу адаптивной синхронизации (adaptive sync) и уменьшает задержку ввода.\n"
				u8"Однако пользователям многомониторных конфигураций имеет смысл отключить этот параметр.\n"
				u8"Примечание: для Direct3D в эксклюзивном режиме также не учитывается выбранный монитор."
			}
		}
	},
	{
		"Settings.Drivers.Video.Synchronize.tooltip",
		{
			{
				EN,
				u8"Waits for the video card to be ready before rendering frames.\n"
				u8"Eliminates dropped or duplicated frames, but can distort audio.\n\n"
				u8"With this option, it’s recommended to disable audio sync,\n"
				u8"and enable dynamic rate control. Or alternatively, adjust\n"
				u8"the audio skew option to reduce buffer under/overflows."
			},
			{
				RU,
				u8"Ожидает готовности видеокарты перед отрисовкой кадров.\n"
				u8"Устраняет пропуск или повторение кадров, но может искажать звук.\n\n"
				u8"При использовании этого параметра рекомендуется отключить синхронизацию\n"
				u8"звука и включить динамическое управление частотой. Как вариант,\n"
				u8"подстройте звуковой параметр «Частота» для снижения вероятности\n"
				u8"опустошения/переполнения буфера."
			}
		}
	},
	{
		"Settings.Drivers.Video.GpuSync",
		{
			{EN, u8"GPU sync"},
			{RU, u8"Синхронизация GPU"}
		}
	},
	{
		"Settings.Drivers.Video.GpuSync.tooltip",
		{
			{
				EN,
				u8"(OpenGL driver only)\n\n"
				u8"Causes the GPU to wait until frames are fully rendered.\n"
				u8"In the best case, this can remove up to one frame of input lag.\n"
				u8"However, it incurs a roughly 20% performance penalty.\n\n"
				u8"You should disable this option unless you find it necessary."
			},
			{
				RU,
				u8"(Только для драйвера OpenGL)\n\n"
				u8"Заставляет видеокарту ожидать, пока кадры не будут полностью отрисованы.\n"
				u8"В лучшем случае это может устранить до одного кадра задержки ввода.\n"
				u8"Однако при этом быстродействие снижается примерно на 20%.\n\n"
				u8"Следует отключить этот параметр, если он вам не требуется."
			}
		}
	},
	{
		"Settings.Drivers.Audio.failedToInitialize",
		{
			{EN, u8"Failed to initialize [|] audio driver"},
			{RU, u8"Не удалось инициализировать аудиодрайвер [|]"}
		}
	},
	{
		"Settings.Drivers.Audio.OutputDevice",
		{
			{EN, u8"Output device"},
			{RU, u8"Устройство вывода"}
		}
	},
	{
		"Settings.Drivers.Audio.SampleRate",
		{
			{EN, u8"Sample Rate"},
			{RU, u8"Частота дискретизации"}
		}
	},
	{
		"Settings.Drivers.Audio.Latency",
		{
			{EN, u8"Latency"},
			{RU, u8"Задержка"}
		}
	},
	{
		"Settings.Drivers.Audio.ExclusiveMode.tooltip",
		{
			{
				EN,
				u8"(WASAPI driver only)\n\n"
				u8"Acquires exclusive control of the sound card device.\n"
				u8"This can significantly reduce audio latency.\n"
				u8"However, it will block sounds from all other applications."
			},
			{
				RU,
				u8"(Только для драйвера WASAPI)\n\n"
				u8"Включает исключительный доступ к звуковой карте.\n"
				u8"Это может существенно снизить задержку вывода звука.\n"
				u8"Однако звуки от всех других приложений заблокируются."
			}
		}
	},
	{
		"Settings.Drivers.Audio.Synchronize.tooltip",
		{
			{
				EN,
				u8"Waits for the audio card to be ready before outputting samples.\n"
				u8"Eliminates audio distortion, but can distort video.\n\n"
				u8"With this option, it’s recommended to disable video sync.\n"
				u8"For best results, use this with an adaptive sync monitor."
			},
			{
				RU,
				u8"Ожидает готовности звуковой карты перед выводом звука.\n"
				u8"Устраняет искажения звука, но может искажать видео.\n\n"
				u8"При использовании этого параметра рекомендуется отключить синхронизацию видео.\n"
				u8"Для наилучших результатов используйте этот параметр\n"
				u8"с монитором, поддерживающим адаптивную синхронизацию."
			}
		}
	},
	{
		"Settings.Drivers.Audio.DynamicRate",
		{
			{EN, u8"Dynamic rate"},
			{RU, u8"Динамическая частота"}
		}
	},
	{
		"Settings.Drivers.Audio.DynamicRate.tooltip",
		{
			{
				EN,
				u8"(OSS, XAudio2, waveOut drivers only)\n\n"
				u8"Dynamically adjusts the audio frequency by tiny amounts.\n"
				u8"Use this with video sync enabled, and audio sync disabled.\n\n"
				u8"This can produce perfectly smooth video and clean audio,\n"
				u8"but only if your monitor refresh rate is set correctly:\n"
				u8"60 Hz for NTSC games, and 50 Hz for PAL games."
			},
			{
				RU,
				u8"(Только для драйверов OSS, XAudio2, waveOut)\n\n"
				u8"Динамически подстраивает частоту звука на небольшие величины.\n"
				u8"Используйте при включённой синхронизации видео\n"
				u8"и отключённой синхронизации звука.\n\n"
				u8"Может обеспечить идеально плавное видео и чистый звук,\n"
				u8"но только при правильно установленной частоте обновления монитора:\n"
				u8"60 Гц для игр NTSC и 50 Гц для игр PAL."
			}
		}
	},
	{
		"Settings.Drivers.Input.failedToInitialize",
		{
			{EN, u8"Failed to initialize [|] input driver"},
			{RU, u8"Не удалось инициализировать драйвер устройства ввода [|]"}
		}
	},
	{
		"Settings.Drivers.Input.Reload.tooltip",
		{
			{
				EN, 
				u8"A driver reload can be used to detect hotplugged devices.\n"
				u8"This is useful for APIs that lack auto-hotplug support,\n"
				u8"such as DirectInput and SDL."
			},
			{
				RU,
				u8"Перезагрузку драйвера можно использовать для обнаружения\n"
				u8"устройств, подключённых в «горячем» режиме.\n"
				u8"Полезно для программных интерфейсов (API), не поддерживающих\n"
				u8"«горячее» подключение, таких как DirectInput и SDL."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets",
		{
			{EN, u8"Synchronization Mode Presets"},
			{RU, u8"Предустановки режимов синхронизации"}
		}
	},
	{
		"Settings.Drivers.syncModePresets.requirements",
		{
			{
				EN,
				u8"Adaptive Sync: requires G-Sync or FreeSync monitor.\n"
				u8"Dynamic Rate Control: requires monitor and SNES refresh rates to match."
			},
			{
				RU,
				u8"Адаптивная синхронизация: требуется монитор с поддержкой G-Sync или FreeSync.\n"
				u8"Динамическое управление частотой: частоты обновления монитора и SNES должны совпадать."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync",
		{
			{EN, u8"Adaptive Sync"},
			{RU, u8"Адаптивная синхронизация"}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync.failure",
		{
			{
				EN,
				u8"Sorry, the current driver configuration is not compatible with adaptive sync mode.\n"
				u8"Adaptive sync requires audio-synchronization support."
			},
			{
				RU,
				u8"Извините, текущая конфигурация драйверов несовместима с режимом адаптивной синхронизации.\n"
				u8"Для адаптивной синхронизации требуется поддержка синхронизации звука."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync.success",
		{
			{
				EN,
				u8"Adaptive sync works best in exclusive full-screen mode.\n"
				u8"Use the lowest audio latency setting your system can manage.\n"
				u8"A G-Sync or FreeSync monitor is required.\n"
				u8"Adaptive sync must be enabled in your driver settings panel."
			},
			{
				RU,
				u8"Адаптивная синхронизация лучше всего работает в эксклюзивном полноэкранном режиме.\n"
				u8"Используйте минимальную задержку звука, которая возможна на вашей системе.\n"
				u8"Требуется монитор с поддержкой G-Sync или FreeSync.\n"
				u8"Требуется включить адаптивную синхронизацию в панели управления вашего видеодрайвера."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl",
		{
			{EN, u8"Dynamic Rate Control"},
			{RU, u8"Динамическое управление частотой"}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl.failure",
		{
			{
				EN,
				u8"Sorry, the current driver configuration is "
				u8"not compatible with the dynamic-rate-control mode.\n"
				u8"Dynamic rate control requires video synchronization "
				u8"and audio-dynamic-rate support."
			},
			{
				RU,
				u8"Извините, текущая конфигруация драйверов несовместима "
				u8"с режимом динамического управления частотой.\n"
				u8"Для динамического управления частотой требуется "
				u8"поддержка вертикальной синхронизации "
				u8"и динамического изменения частоты звука."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl.success",
		{
			{
				EN,
				u8"Dynamic rate control requires your monitor to be running at:\n"
				u8"60 Hz refresh rate for NTSC games, 50 Hz refresh rate for PAL games.\n"
				u8"Use the lowest audio latency setting your system can manage."
			},
			{
				RU,
				u8"Для динамического управления частотой требуется, "
				u8"чтобы частота обновления вашего монитора была:\n"
				u8"60 Гц для игр NTSC, 50 Гц для игр PAL.\n"
				u8"Используйте минимальную задержку звука, которая возможна на вашей системе."
			}
		}
	},

	{
		"Tools",
		{
			{EN, u8"Tools"},
			{RU, u8"Инструменты"},
			{JA, u8"ツール"}
		}
	},

	{
		"Tools.SaveState",
		{
			{EN, u8"Save State"},
			{RU, u8"Сохранить состояние"}
		}
	},
	{
		"Tools.SaveState.Slot",
		{
			{EN, u8"Slot"},
			{RU, u8"Слот"}
		}
	},
	{
		"Tools.SaveState.Slot.Empty",
		{
			{EN, u8"empty"},
			{RU, u8"пусто"},
			{JA, u8"なし"}
		}
	},

	{
		"Tools.LoadState",
		{
			{EN, u8"Load State"},
			{RU, u8"Загрузить состояние"}
		}
	},
	{
		"Tools.LoadState.SelectedStateSlot",
		{
			{EN, u8"Selected state slot"},
			{RU, u8"Выбран слот быстрого сохранения"}
		}
	},
	{
		"Tools.LoadState.UndoLastSave",
		{
			{EN, u8"Undo Last Save"},
			{RU, u8"Отменить последнее сохранение"}
		}
	},
	{
		"Tools.LoadState.RedoLastUndo",
		{
			{EN, u8"Redo Last Undo"},
			{RU, u8"Вернуть последнее отменённое сохранение"}
		}
	},
	{
		"Tools.LoadState.RemoveAllStates",
		{
			{EN, u8"Remove All States"},
			{RU, u8"Удалить все сохранения"}
		}
	},
	{
		"Tools.LoadState.RemoveAllStates.confirm.title",
		{
			{EN, u8"Remove quick states?"},
			{RU, u8"Удалить быстрые сохранения?"}
		}
	},
	{
		"Tools.LoadState.RemoveAllStates.confirm",
		{
			{EN, u8"Are you sure you want to permanently remove all quick states for this game?"},
			{RU, u8"Вы уверены, что хотите навсегда удалить все быстрые сохранения для этой игры?"}
		}
	},

	{
		"Tools.Speed",
		{
			{EN, u8"Speed"},
			{RU, u8"Скорость"}
		}
	},
	{
		"Tools.Speed.Slowest",
		{
			{EN, u8"Slowest"},
			{RU, u8"Очень медленно"}
		}
	},
	{
		"Tools.Speed.Slow",
		{
			{EN, u8"Slow"},
			{RU, u8"Медленно"}
		}
	},
	{
		"Tools.Speed.Normal",
		{
			{EN, u8"Normal"},
			{RU, u8"Обычная скорость"}
		}
	},
	{
		"Tools.Speed.Fast",
		{
			{EN, u8"Fast"},
			{RU, u8"Быстро"}
		}
	},
	{
		"Tools.Speed.Fastest",
		{
			{EN, u8"Fastest"},
			{RU, u8"Очень быстро"}
		}
	},

	{
		"Tools.RunMode",
		{
			{EN, u8"Run Mode"},
			{RU, u8"Режим исполнения"}
		}
	},
	{
		"Tools.RunMode.Normal",
		{
			{EN, u8"Normal"},
			{RU, u8"Обычный"}
		}
	},
	{
		"Tools.RunMode.PauseEmulation",
		{
			{EN, u8"Pause Emulation"},
			{RU, u8"Приостановить эмуляцию"}
		}
	},
	{
		"Tools.RunMode.FrameAdvance",
		{
			{EN, u8"Frame Advance"},
			{RU, u8"Покадрово (Frame Advance)"}
		}
	},

	{
		"Tools.Movie",
		{
			{EN, u8"Movie"},
			{RU, u8"Видеозапись"}
		}
	},
	{
		"Tools.Movie.Play",
		{
			{EN, u8"Play"},
			{RU, u8"Воспроизведение"}
		}
	},
	{
		"Tools.Movie.Record",
		{
			{EN, u8"Record"},
			{RU, u8"Запись"}
		}
	},
	{
		"Tools.Movie.ResetAndRecord",
		{
			{EN, u8"Reset and Record"},
			{RU, u8"Сброс и запись"}
		}
	},
	{
		"Tools.Movie.Stop",
		{
			{EN, u8"Stop"},
			{RU, u8"Стоп"}
		}
	},

	{
		"Tools.TakeScreenshot",
		{
			{EN, u8"Take Screenshot"},
			{RU, u8"Снять скриншот"}
		}
	},

	{
		"Tools.CheatFinder",
		{
			{EN, u8"Cheat Finder"},
			{RU, u8"Поиск читов"}
		}
	},
	{
		"Tools.CheatFinder.Address",
		{
			{EN, u8"Address"},
			{RU, u8"Адрес"}
		}
	},
	{
		"Tools.CheatFinder.Value",
		{
			{EN, u8"Value"},
			{RU, u8"Значение"}
		}
	},
	{
		"Tools.CheatFinder.Scan",
		{
			{EN, u8"Scan"},
			{RU, u8"Сканировать"}
		}
	},
	{
		"Tools.CheatFinder.All",
		{
			{EN, u8"All"},
			{RU, u8"Все"}
		}
	},

	{
		"Tools.CheatEditor",
		{
			{EN, u8"Cheat Editor"},
			{RU, u8"Редактор читов"}
		}
	},
	{
		"Tools.CheatEditor.remove.confirm.title",
		{
			{EN, u8"Remove cheat(s)?"},
			{RU, u8"Удалить читы?"}
		}
	},
	{
		"Tools.CheatEditor.remove.confirm",
		{
			{EN, u8"Are you sure you want to permanently remove the selected cheat(s)?"},
			{RU, u8"Вы уверены, что хотите навсегда удалить выделенные читы?"}
		}
	},
	{
		"Tools.CheatEditor.Codes",
		{
			{EN, u8"Code(s)"},
			{RU, u8"Код(ы)"}
		}
	},
	{
		"Tools.CheatEditor.Enable",
		{
			{EN, u8"Enable"},
			{RU, u8"Включить"}
		}
	},
	{
		"Tools.CheatEditor.SelectAll",
		{
			{EN, u8"Select All"},
			{RU, u8"Выделить всё"}
		}
	},
	{
		"Tools.CheatEditor.UnselectAll",
		{
			{EN, u8"Unselect All"},
			{RU, u8"Снять выделение"}
		}
	},
	{
		"Tools.CheatEditor.AddCheats",
		{
			{EN, u8"Add Cheats"},
			{RU, u8"Добавить читы"}
		}
	},
	{
		"Tools.CheatEditor.AddCheat",
		{
			{EN, u8"Add Cheat"},
			{RU, u8"Добавить чит"}
		}
	},
	{
		"Tools.CheatEditor.EditCheat",
		{
			{EN, u8"Edit Cheat"},
			{RU, u8"Изменить чит"}
		}
	},
	{
		"Tools.CheatEditor.Edit",
		{
			{EN, u8"Edit"},
			{RU, u8"Изменить"}
		}
	},
	{
		"Tools.CheatEditor.FindCheats",
		{
			{EN, u8"Find Cheats"},
			{RU, u8"Найти читы"}
		}
	},
	{
		"Tools.CheatEditor.noCheats",
		{
			{EN, u8"Sorry, no cheats were found for this game."},
			{RU, u8"К сожалению, читы для этой игры не найдены."}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats",
		{
			{EN, u8"Enable Cheats"},
			{RU, u8"Включить читы"}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats.tooltip",
		{
			{
				EN,
				u8"Master enable for all cheat codes.\n"
				u8"When unchecked, no cheat codes will be active.\n\n"
				u8"Use this to bypass game areas that have problems with cheats."
			},
			{
				RU,
				u8"Включает все чит-коды.\n"
				u8"Когда выключено, ни один чит-код не будет активен.\n\n"
				u8"Используйте при прохождении частей игр, где читы приводят к проблемам."
			}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats.disabled",
		{
			{EN, u8"All cheat codes are disabled"},
			{RU, u8"Все чит-коды выключены"}
		}
	},
	{
		"Tools.CheatEditor.EnableCheats.enabled",
		{
			{EN, u8"Active cheat codes are enabled"},
			{RU, u8"Активные чит-коды включены"}
		}
	},
	{
		"Tools.CheatEditor.invalidFormat",
		{
			{EN, u8"Invalid code(s), please only use codes in the following format"},
			{RU, u8"Некорректный код(ы), пожалуста, используйте следующий формат"}
		}
	},

	{
		"Tools.StateManager",
		{
			{EN, u8"State Manager"},
			{RU, u8"Менеджер сохранений"}
		}
	},
	{
		"Tools.StateManager.Category",
		{
			{EN, u8"Category"},
			{RU, u8"Категория"}
		}
	},
	{
		"Tools.StateManager.Category.ManagedStates",
		{
			{EN, u8"Managed States"},
			{RU, u8"Управляемые состояния"}
		}
	},
	{
		"Tools.StateManager.Category.QuickStates",
		{
			{EN, u8"Quick States"},
			{RU, u8"Быстрые сохранения"}
		}
	},
	{
		"Tools.StateManager.QuickStates.Redo",
		{
			{EN, u8"Redo"},
			{RU, u8"Вернуть"}
		}
	},
	{
		"Tools.StateManager.QuickStates.Undo",
		{
			{EN, u8"Undo"},
			{RU, u8"Отменить"}
		}
	},
	{
		"Tools.StateManager.Preview",
		{
			{EN, u8"Preview"},
			{RU, u8"Предпросмотр"}
		}
	},
	{
		"Tools.StateManager.AddState",
		{
			{EN, u8"Add State"},
			{RU, u8"Добавить состояние"}
		}
	},
	{
		"Tools.StateManager.RenameState",
		{
			{EN, u8"Rename State"},
			{RU, u8"Переименовать состояние"}
		}
	},
	{
		"Tools.StateManager.remove.confirm.title",
		{
			{EN, u8"Remove state(s)?"},
			{RU, u8"Удалить сохранения?"}
		}
	},
	{
		"Tools.StateManager.remove.confirm",
		{
			{EN, u8"Are you sure you want to permanently remove the selected state(s)?"},
			{RU, u8"Вы уверены, что хотите навсегда удалить выделенные сохранения?"}
		}
	},

	{
		"Tools.ManifestViewer",
		{
			{EN, u8"Manifest Viewer"},
			{RU, u8"Просмотр манифеста"}
		}
	},
	{
		"Tools.ManifestViewer.Manifest",
		{
			{EN, u8"Manifest"},
			{RU, u8"Манифест"}
		}
	},

	{
		"Game.VerifiedGameOpened",
		{
			{EN, u8"Verified game opened"},
			{RU, u8"Открыта проверенная игра"}
		}
	},
	{
		"Game.GameOpened",
		{
			{EN, u8"Game opened"},
			{RU, u8"Открыта игра"}
		}
	},
	{
		"Game.GameClosed",
		{
			{EN, u8"Game closed"},
			{RU, u8"Закрыта игра"}
		}
	},
	{
		"Game.GameReset",
		{
			{EN, u8"Game reset"},
			{RU, u8"Игра сброшена"}
		}
	},
	{
		"Game.AndPatchApplied",
		{
			{EN, u8" and patch applied"},
			{RU, u8", и применён патч"}
		}
	},
	{
		"Game.GameOpeningCancelled",
		{
			{EN, u8"Game opening cancelled"},
			{RU, u8"Открытие игры отменено"}
		}
	},
	{
		"Game.unverifiedGameWarning.title",
		{
			{EN, u8"Unverified game image"},
			{RU, u8"Непроверенный образ игры"}
		}
	},
	{
		"Game.unverifiedGameWarning",
		{
			{
				EN,
				u8"Warning: this game image is unverified.\n"
				u8"Running it *may* be a security risk.\n\n"
				u8"Do you wish to run the game anyway?"
			},
			{
				RU,
				u8"Внимание: этот образ игры не проверен.\n"
				u8"Запуск игры *может* быть небезопасным.\n\n"
				u8"Хотите ли вы запустить игру в любом случае?"
			}
		}
	},
	{
		"Game.unverifiedGameWarning.alwaysQuestion.title",
		{
			{EN, u8"Disable warning?"},
			{RU, u8"Отключить предупреждение?"}
		}
	},
	{
		"Game.unverifiedGameWarning.alwaysQuestion",
		{
			{EN, u8"Do you wish to disable warning when trying to run unverified games?"},
			{RU, u8"Отключить предупреждение при запуске непроверенных игр?"}
		}
	},

	{
		"Program.Paused",
		{
			{EN, u8"Paused"},
			{RU, u8"Пауза"},
			{JA, u8"ポーズ"}
		}
	},
	{
		"Program.Unloaded",
		{
			{EN, u8"Unloaded"},
			{RU, u8"Простой"},
			{JA, u8"アンロードされる"}
		}
	},
	{
		"Program.CapturedScreenshot",
		{
			{EN, u8"Captured screenshot"},
			{RU, u8"Снят скриншот"}
		}
	},
	{
		"Program.Open.MissingRequiredData",
		{
			{EN, u8"Missing required data"},
			{RU, u8"Отсутствуют необходимые данные"}
		}
	},
	{
		"Program.Load.LoadGameBoyRom",
		{
			{EN, u8"Load Game Boy ROM"},
			{RU, u8"Загрузить игру Game Boy"}
		}
	},
	{
		"Program.Load.GameBoyRoms",
		{
			{EN, u8"Game Boy ROMs"},
			{RU, u8"Игры Game Boy"}
		}
	},
	{
		"Program.Load.LoadBsMemoryRom",
		{
			{EN, u8"Load BS Memory ROM"},
			{RU, u8"Загрузить образ BS-памяти"}
		}
	},
	{
		"Program.Load.BsMemoryRoms",
		{
			{EN, u8"BS Memory ROMs"},
			{RU, u8"Образы BS-памяти"}
		}
	},
	{
		"Program.Load.LoadSufamiTurboRomSlot",
		{
			{EN, u8"Load Sufami Turbo ROM – Slot"},
			{RU, u8"Загрузить игру Sufami Turbo — слот"}
		}
	},
	{
		"Program.Load.SufamiTurboRoms",
		{
			{EN, u8"Sufami Turbo ROMs"},
			{RU, u8"Игры Sufami Turbo"}
		}
	},

	{
		"About.Version",
		{
			{EN, u8"Version"},
			{RU, u8"Версия"},
			{JA, u8"バージョン"}
		}
	},
	{
		"About.Copyright",
		{
			{EN, u8"Copyright"},
			{RU, u8"Авторские права"}
		}
	},
	{
		"About.License",
		{
			{EN, u8"License"},
			{RU, u8"Лицензия"},
			{JA, u8"ライセンス"}
		}
	},
	{
		"About.Website",
		{
			{EN, u8"Website"},
			{RU, u8"Сайт"},
			{JA, u8"公式サイト"}
		}
	},

	{
		"About.SameBoy.description",
		{
			{EN, u8"Super Game Boy emulator"},
			{RU, u8"Эмулятор Super Game Boy"}
		}
	},

	{
		"About.Bsnes.description",
		{
			{EN, u8"Super Nintendo emulator"},
			{RU, u8"Эмулятор Super Nintendo"}
		}
	},
	{
		"About.Bsnes.copyright",
		{
			{EN, u8"byuu et al"},
			{RU, u8"byuu и другие"}
		}
	},
	{
		"About.Bsnes.license",
		{
			{EN, u8"GPLv3 or later"},
			{RU, u8"GPLv3 или новее"}
		}
	},

	{
		"Browser.OpenSnesRom",
		{
			{EN, u8"Open SNES ROM"},
			{RU, u8"Открыть игру SNES"}
		}
	},
	{
		"Browser.SnesRoms",
		{
			{EN, u8"SNES ROMs"},
			{RU, u8"Игры SNES"}
		}
	},
	{
		"Browser.AllFiles",
		{
			{EN, u8"All Files"},
			{RU, u8"Все файлы"}
		}
	},
	{
		"Browser.Select",
		{
			{EN, u8"Select"},
			{RU, u8"Выбрать"},
			{JA, u8"選択"}
		}
	},
	{
		"Browser.SelectFolder",
		{
			{EN, u8"Select Folder"},
			{RU, u8"Выбрать папку"}
		}
	},
	{
		"Browser.ChooseFolder",
		{
			{EN, u8"Choose a folder"},
			{RU, u8"Выберите папку"}
		}
	},
	{
		"Browser.Rename.EnterNewFolderName",
		{
			{EN, u8"Enter the new folder name"},
			{RU, u8"Введите новое имя папки"}
		}
	},
	{
		"Browser.Rename.EnterNewFileName",
		{
			{EN, u8"Enter the new file name"},
			{RU, u8"Введите новое имя файла"}
		}
	},
	{
		"Browser.Rename.FailedToRenameFolder",
		{
			{EN, u8"Failed to rename folder."},
			{RU, u8"Не удалось переименовать папку."}
		}
	},
	{
		"Browser.Rename.FailedToRenameFile",
		{
			{EN, u8"Failed to rename file."},
			{RU, u8"Не удалось переименовать файл."}
		}
	},
	{
		"Browser.Create",
		{
			{EN, u8"Create"},
			{RU, u8"Создать"}
		}
	},
	{
		"Browser.Create.EnterName",
		{
			{EN, u8"Enter a name"},
			{RU, u8"Введите имя"}
		}
	},
	{
		"Browser.CreateFolder",
		{
			{EN, u8"Create Folder"},
			{RU, u8"Создать папку"}
		}
	},
	{
		"Browser.CreateFolder.EnterNewFolderName",
		{
			{EN, u8"Enter a new-folder name"},
			{RU, u8"Введите имя новой папки"}
		}
	},
	{
		"Browser.Delete.DeleteSelected",
		{
			{EN, u8"Delete Selected"},
			{RU, u8"Удалить выделенные"}
		}
	},
	{
		"Browser.Delete.FailedToDelete",
		{
			{EN, u8"Failed to delete |. Continue trying to remove remaining items?"},
			{RU, u8"Не удалось удалить |. Попытаться удалить остальные элементы?"}
		}
	},
	{
		"Browser.Delete.confirm",
		{
			{EN, u8"Are you sure you want to permanently delete the |"},
			{RU, u8"Вы уверены, что хотите навсегда удалить |"}
		}
	},
	{
		"Browser.Delete.confirm.item",
		{
			{EN, u8"selected item"},
			{RU, u8"выделенный элемент"}
		}
	},
	{
		"Browser.Delete.confirm.items",
		{
			{EN, u8"selected items"},
			{RU, u8"выделенные элементы"}
		}
	},
	{
		"Browser.ShowHidden",
		{
			{EN, u8"Show Hidden"},
			{RU, u8"Показать скрытые"}
		}
	},
	{
		"Browser.OpenFile",
		{
			{EN, u8"Open File"},
			{RU, u8"Открыть файл"}
		}
	},
	{
		"Browser.OpenFiles",
		{
			{EN, u8"Open Files"},
			{RU, u8"Открыть файлы"}
		}
	},
	{
		"Browser.OpenFolder",
		{
			{EN, u8"Open Folder"},
			{RU, u8"Открыть папку"}
		}
	},
	{
		"Browser.OpenObject",
		{
			{EN, u8"Open Object"},
			{RU, u8"Открыть объект"}
		}
	},
	{
		"Browser.SaveFile",
		{
			{EN, u8"Save File"},
			{RU, u8"Сохранить файл"}
		}
	},
	{
		"Browser.SaveFile.fileExists.title",
		{
			{EN, u8"Overwrite file?"},
			{RU, u8"Заменить файл?"}
		}
	},
	{
		"Browser.SaveFile.fileExists",
		{
			{EN, u8"File already exists. Overwrite it?"},
			{RU, u8"Файл уже существует. Заменить его?"}
		}
	},

	{
		"StatusIcon.verifiedRom.tooltip",
		{
			{
				EN,
				u8"This is a known clean game image.\n"
				u8"PCB emulation is 100% accurate."
			},
			{
				RU,
				u8"Это известный качественный образ игры.\n"
				u8"Эмуляция платы (PCB) на 100% точная."
			}
		}
	},
	{
		"StatusIcon.unverifiedRom.tooltip",
		{
			{
				EN,
				u8"This is not a verified game image.\n"
				u8"PCB emulation is relying on heuristics."
			},
			{
				RU,
				u8"Этот образ игры не проверен.\n"
				u8"При эмуляции платы (PCB) будет использоваться эвристика."
			}
		}
	},

	{
		"ResetDrivers.message.title",
		{
			{EN, u8"Reset drivers"},
			{RU, u8"Сброс драйверов"}
		}
	},
	{
		"ResetDrivers.message",
		{
			{
				EN,
				u8"Hardware drivers have been reset according "
				u8"to the `--resetdrivers` command-line option.\n\n"
				u8"Please reconfigure drivers in the “Settings” → “Drivers” "
				u8"window that will now open."
			},
			{
				RU,
				u8"Драйверы оборудования были сброшены согласно "
				u8"параметру командной строки `--resetdrivers`.\n\n"
				u8"Пожалуйста, выберите новые настройки драйверов в окне "
				u8"«Настройки» → «Драйверы», которое сейчас откроется."
			}
		}
	},

	{
		"Rewind.HistoryExhausted",
		{
			{EN, u8"Rewind history exhausted"},
			{RU, u8"История перемотки исчерпана"}
		}
	},

	{
		"States.incompatibleFormat",
		{
			{EN, u8"[|] is in incompatible format"},
			{RU, u8"[|] имеет несовместимый формат"}
		}
	},
	{
		"States.Loaded",
		{
			{EN, u8"Loaded"},
			{RU, u8"Загружено"}
		}
	},
	{
		"States.NotFound",
		{
			{EN, u8"[|] not found"},
			{RU, u8"[|] не найдено"}
		}
	},
	{
		"States.FailedToSave",
		{
			{EN, u8"Failed to save [|]"},
			{RU, u8"Не удалось сохранить [|]"}
		}
	},
	{
		"States.UnableToWriteToDisk",
		{
			{EN, u8"Unable to write [|] to disk"},
			{RU, u8"Не удаётся записать [|] на диск"}
		}
	},
	{
		"States.Saved",
		{
			{EN, u8"Saved [|]"},
			{RU, u8"Сохранено [|]"}
		}
	},

	{
		"Patch.ipsWarning",
		{
			{
				EN,
				u8"(You’re seeing this prompt because IPS is a terrible patch-file format, "
				u8"and nobody can agree on whether SNES ROMs should be headered or not.\n"
				u8"Please consider asking the patch author to use BPS patches instead.)\n\n"
				u8"Does this IPS patch expect to be applied to a headered ROM?\n"
				u8"If you’re not sure, try “No”, and if it fails to work, try again with “Yes”."
			},
			{
				RU,
				u8"(Вы видите этот запрос потому, что IPS — ужасный формат файлов патчей, "
				u8"и нет единого мнения, должны ли SNES-игры снабжаться заголовками.\n"
				u8"Пожалуйста, попробуйте попросить автора патча использовать формат BPS.)\n\n"
				u8"Предусмотрена ли в этом IPS-патче возможность применения к игре с заголовком?\n"
				u8"Если вы не уверены, попробуйте «Нет», а если не сработает, попробуйте "
				u8"снова с ответом «Да»."
			}
		}
	},
	{
		"Patch.ensureHeaderless",
		{
			{EN, u8"Please ensure you are using the correct (headerless) ROM for this patch."},
			{RU, u8"Пожалуйста, удостоверьтесь, что используете для этого патча правильный (без заголовка) образ."}
		}
	},

	{
		"Movies.PlayMovie",
		{
			{EN, u8"Play Movie"},
			{RU, u8"Воспроизвести видео"}
		}
	},
	{
		"Movies.Movies",
		{
			{EN, u8"Movies"},
			{RU, u8"Видеозаписи"}
		}
	},
	{
		"Movies.playbackStarted",
		{
			{EN, u8"Movie playback started"},
			{RU, u8"Началось воспроизведение видео"}
		}
	},
	{
		"Movies.playbackStopped",
		{
			{EN, u8"Movie playback stopped"},
			{RU, u8"Воспроизведение видео остановлено"}
		}
	},
	{
		"Movies.formatNotSupported",
		{
			{EN, u8"Movie format is not supported"},
			{RU, u8"Формат видео не поддерживается"}
		}
	},
	{
		"Movies.recordingStarted",
		{
			{EN, u8"Movie recording started"},
			{RU, u8"Началась запись видео"}
		}
	},
	{
		"Movies.SaveMovie",
		{
			{EN, u8"Save Movie"},
			{RU, u8"Сохранить видео"}
		}
	},
	{
		"Movies.MovieRecorded",
		{
			{EN, u8"Movie recorded"},
			{RU, u8"Видео записано"}
		}
	},
	{
		"Movies.MovieNotRecorded",
		{
			{EN, u8"Movie not recorded"},
			{RU, u8"Видео не записано"}
		}
	},
	{
		"Movies.cantRecord",
		{
			{EN, u8"Movie could not be recorded"},
			{RU, u8"Не удаётся записать видео"}
		}
	}
	/*{
		"",
		{
			{EN, u8""},
			{RU, u8""}
		}
	}*/
};

static map<string, map<uint8_t, string>> deviceStrings = {
	{
		"Gamepad",
		{
			{RU, u8"Геймпад"},
			{JA, u8"ゲームパッド"}
		}
	},
	{
		"Mouse",
		{
			{RU, u8"Мышь"},
			{JA, u8"マウス"}
		}
	},
	{
		"Super Multitap",
		{
			{JA, u8"スーパーマルチタップ"}
		}
	},
	{
		"Super Scope",
		{
			{JA, u8"スーパースコップ"}
		}
	},
	{
		"Justifier",
		{
			{JA, u8"1挺のジャスティファイアー"}
		}
	},
	{
		"Justifiers",
		{
			{JA, u8"2挺のジャスティファイアー"}
		}
	},
	{
		"Satellaview",
		{
			{JA, u8"サテラビュー"}
		}
	}
};

static map<string, map<uint8_t, string>> hotkeyStrings = {
	{
		"Toggle Mouse Capture",
		{
			{RU, u8"Захватить указатель мыши"}
		}
	},
	{
		"Toggle Cheat Codes",
		{
			{RU, u8"Включить чит-коды"}
		}
	},
	{
		"Rewind",
		{
			{RU, u8"Перемотать назад (Rewind)"}
		}
	},
	{
		"Load Undo State",
		{
			{RU, u8"Загрузить состояние отмены действия"}
		}
	},
	{
		"Load Redo State",
		{
			{RU, u8"Загрузить состояния повтора действия"}
		}
	},
	{
		"Decrement State Slot",
		{
			{RU, u8"Предыдущий слот быстрого сохранения"}
		}
	},
	{
		"Increment State Slot",
		{
			{RU, u8"Следующий слот быстрого сохранения"}
		}
	},
	{
		"Fast Forward",
		{
			{RU, u8"Перемотать вперёд (Fast Forward)"}
		}
	},
	{
		"Frame Advance",
		{
			{EN, u8"Next frame in Frame Advance mode"},
			{RU, u8"Следующий кадр в покадровом режиме"}
		}
	},
	{
		"Decrease HD Mode 7",
		{
			{RU, u8"Уменьшить разрешение HD Mode 7"}
		}
	},
	{
		"Increase HD Mode 7",
		{
			{RU, u8"Увеличить разрешение HD Mode 7"}
		}
	},
	{
		"Toggle Supersampling",
		{
			{RU, u8"Включить избыточную выборку (supersampling)"}
		}
	},
	{
		"Reset Emulation",
		{
			{RU, u8"Сбросить эмуляцию"}
		}
	},
	{
		"Quit Emulator",
		{
			{RU, u8"Выйти из эмулятора"}
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

} // namespace bsnesMt::strings