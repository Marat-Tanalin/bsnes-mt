/*! bsnes-mt by Marat Tanalin | http://tanalin.com/en/projects/bsnes-mt/ */

#pragma once

#include <cstdint>
#include <map>
#include <string>

namespace bsnesMt::strings {

using std::map, std::string;

const uint8_t RU = 1,
              EN = 2,
              JP = 3;

auto getLocale() -> uint8_t;

static uint8_t locale = getLocale();

auto genericHas(const map<string, map<uint8_t, string>> &strings, const string &name) -> bool;

auto has(const string &name) -> bool;

auto valueHasLocale(const map<uint8_t, string> &value, uint8_t locale) -> bool;

auto get(const map<uint8_t, string> &value) -> string;
auto get(const string &name) -> string;

auto hasDeviceString(const string &name) -> bool;
auto getDeviceString(const string &name) -> string;

auto hasHotkeyString(const string &name) -> bool;
auto getHotkeyString(const string &name) -> string;

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
			{RU, "Всегда"},
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
		"Common.Reset",
		{
			{EN, "Reset"},
			{RU, "Сброс"}
		}
	},
	{
		"Common.Number",
		{
			{EN, "#"},
			{RU, "№"}
		}
	},
	{
		"Common.Assign",
		{
			{EN, "Assign"},
			{RU, "Задать"}
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
		"Common.Name",
		{
			{EN, "Name"},
			{RU, "Название"}
		}
	},
	{
		"Common.Mapping",
		{
			{EN, "Mapping"},
			{RU, "Соответствие"}
		}
	},
	{
		"Common.MappingAssigned",
		{
			{EN, "Mapping assigned."},
			{RU, "Соответствие назначено."}
		}
	},
	{
		"Common.PressAKeyOrButtonForMapping",
		{
			{EN, "Press a key or button for mapping"},
			{RU, "Нажмите клавишу или кнопку для соответствия"}
		}
	},
	{
		"Common.AssignAwaiting",
		{
			{EN, "assign"},
			{RU, "задать"}
		}
	},
	{
		"Common.Frame",
		{
			{EN, "frame"},
			{RU, "кадр"}
		}
	},
	{
		"Common.Frames",
		{
			{EN, "frames"},
			{RU, "кадров"}
		}
	},
	{
		"Common.FramesFew",
		{
			{EN, "frames"},
			{RU, "кадра"}
		}
	},
	{
		"Common.FastMode",
		{
			{EN, "Fast mode"},
			{RU, "Быстрый режим"}
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
		"Menu.File",
		{
			{EN, "File"},
			{RU, "Файл"}
		}
	},
	{
		"Menu.File.LoadGame",
		{
			{EN, "Open Game"},
			{RU, "Открыть игру"},
			{JP, "ゲームを読み込み"},
		}
	},
	{
		"Menu.File.LoadRecentGame",
		{
			{EN, "Open Recent Game"},
			{RU, "Открыть недавнюю игру"},
			{JP, "最新ゲームを読み込み"}
		}
	},
	{
		"Menu.File.LoadRecentGame.ClearList",
		{
			{EN, "Clear List"},
			{RU, "Очистить список"},
			{JP, "全部を消す"},
		}
	},
	{
		"Menu.File.LoadRecentGame.NoRecentGames",
		{
			{EN, "No Recent Games"},
			{RU, "Нет недавних игр"}
		}
	},
	{
		"Menu.File.UnloadGame",
		{
			{EN, "Close Game"},
			{RU, "Закрыть игру"},
			{JP, "ゲームをアンロード"}
		}
	},
	{
		"Menu.File.Quit",
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
			{JP, "システム"},
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
			{EN, "Shrink Window To Size"},
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
			{RU, "Показать overscan-область"}
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
			{RU, "Отключить звук"}
		}
	},
	{
		"Menu.Settings.ShowStatusBar",
		{
			{EN, "Show Status Bar"},
			{RU, "Показать строку состояния"}
		}
	},
	{
		"Menu.Settings.ShowStatusBar",
		{
			{EN, "Show Status Bar"},
			{RU, "Показать строку состояния"}
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
	{
		"Settings.Video",
		{
			{EN, "Video"},
			{RU, "Видео"}
		}
	},
	{
		"Settings.Audio",
		{
			{EN, "Audio"},
			{RU, "Звук"}
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
		"Settings.Hotkeys",
		{
			{EN, "Hotkeys"},
			{RU, "Горячие клавиши"}
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
		"Settings.Emulator",
		{
			{EN, "Emulator"},
			{RU, "Эмулятор"}
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
		"Settings.Compatibility",
		{
			{EN, "Compatibility"},
			{RU, "Совместимость"}
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
		"Menu.Settings.OpenSettingsFolder",
		{
			{EN, "Open Settings Folder"},
			{RU, "Открыть папку настроек"}
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
		"Tools.SaveState.Empty",
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
		"Tools.Speed",
		{
			{EN, "Speed"},
			{RU, "Скорость"}
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
			{EN, "Переход к следующему кадру"},
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
		"Tools.CaptureScreenshot",
		{
			{EN, "Capture Screenshot"},
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
		"Tools.CheatFinder",
		{
			{EN, "Cheat Finder"},
			{RU, "Поиск читов"}
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
		"Tools.StateManager",
		{
			{EN, "State Manager"},
			{RU, "Менеджер сохранений"}
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
		"Menu.Help",
		{
			{EN, "Help"},
			{RU, "Справка"},
			{JP, "ヘルプ"}
		}
	},
	{
		"Help.About",
		{
			{EN, "About"},
			{RU, "О программе"},
			{JP, "情報"}
		}
	},
	{
		"Paths.Games",
		{
			{EN, "Games"},
			{RU, "Игры"}
		}
	},
	{
		"Paths.Patches",
		{
			{EN, "Patches"},
			{RU, "Патчи"}
		}
	},
	{
		"Paths.Saves",
		{
			{EN, "Saves"},
			{RU, "Сохранения"}
		}
	},
	{
		"Paths.Cheats",
		{
			{EN, "Cheats"},
			{RU, "Читы"}
		}
	},
	{
		"Paths.States",
		{
			{EN, "States"},
			{RU, "Быстрые сохранения"}
		}
	},
	{
		"Paths.Screenshots",
		{
			{EN, "Screenshots"},
			{RU, "Скриншоты"}
		}
	},
	{
		"Paths.Assign",
		{
			{EN, "Assign"},
			{RU, "Задать"}
		}
	},
	{
		"Paths.LastRecentlyUsed",
		{
			{EN, "last recently used"},
			{RU, "последняя использованная папка"}
		}
	},
	{
		"Paths.SameAsLoadedGame",
		{
			{EN, "same as loaded game"},
			{RU, "папка текущей игры"}
		}
	},
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
			{RU, "Затемнять изображение в состоянии простоя"}
		}
	},
	{
		"Settings.Video.DrawSnowEffectWhenIdle",
		{
			{EN, "Draw snow effect when idle"},
			{RU, "Применять эффект снега в состоянии простоя"}
		}
	},
	{
		"Settings.Video.DrawSnowEffectWhenIdle.tooltip",
		{
			{EN, "Darkens the video to indicate that the emulation is not running."},
			{RU, "Затемняет изображение, чтобы показать, что эмуляция приостановлена."}
		}
	},
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
				"Не следует изменять это значение при использовании динамического управления частотой."
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
		"Settings.Input.WhenFocusIsLost",
		{
			{EN, "When focus is lost"},
			{RU, "При потере фокуса"}
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
		"Settings.Input.Name",
		{
			{EN, "Name"},
			{RU, "Название"}
		}
	},
	{
		"Settings.Input.Mapping",
		{
			{EN, "Mapping"},
			{RU, "Соответствие"}
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
				"Use 'and' logic if you want keyboard combinations such as Ctrl+F to trigger a hotkey.\n"
				"Use 'or' logic if you want both a keyboard and joypad to trigger the same hotkey."
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
			{EN, "And"},
			{RU, "И"}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.And.tooltip",
		{
			{EN, "Every mapping must be pressed to activate a given hotkey."},
			{RU, "Для активации заданных горячих клавиш требуется нажать каждое соответствие."}
		}
	},
	{
		"Settings.Hotkeys.CombinationalLogic.Or",
		{
			{EN, "Or"},
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
		"Settings.Emulator.Options",
		{
			{EN, "Options"},
			{RU, "Общие"}
		}
	},
	{
		"Settings.Emulator.warnOnUnverifiedGames",
		{
			{EN, "Warn when loading games that have not been verified"},
			{RU, "Предупреждать при открытии непроверенных игр"}
		}
	},
	{
		"Settings.Emulator.autoSaveMemory",
		{
			{EN, "Auto-save memory periodically"},
			{RU, "Периодически автоматически сохранять память"}
		}
	},
	{
		"Settings.Emulator.autoSaveStateOnUnload",
		{
			{EN, "Auto-save undo state when unloading games"},
			{RU, "Автоматически сохранять состояние отмены действия при закрытии игр"}
		}
	},
	{
		"Settings.Emulator.AutoResumeOnLoad",
		{
			{EN, "Auto-resume on load"},
			{RU, "Автоматически возобновлять при загрузке"}
		}
	},
	{
		"Settings.Emulator.UseNativeFileFialogs",
		{
			{EN, "Use native file dialogs"},
			{RU, "Использовать стандартные диалоги открытия файлов"}
		}
	},
	{
		"Settings.Emulator.FastForward",
		{
			{EN, "Fast Forward"},
			{RU, "Перемотка вперёд"}
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
				"Set how many frames to skip while fast forwarding.\n"
				"Frame skipping allows a higher maximum fast forwarding frame rate."
			},
			{
				RU,
				"Устанавливает, сколько кадров пропускать при перемотке вперёд.\n"
				"Пропуск кадров позволяет увеличить скорость перемотки."
			}
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
			{EN, "Set the maximum speed when fast forwarding."},
			{RU, "Установить максимальную скорость при перемотке вперёд."}
		}
	},
	{
		"Settings.Emulator.FastForward.fastForwardMute",
		{
			{EN, "Mute while fast forwarding"},
			{RU, "Отключать звук при перемотке вперёд"}
		}
	},
	{
		"Settings.Emulator.Rewind",
		{
			{EN, "Rewind"},
			{RU, "Перемотка назад"}
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
		"Settings.Emulator.Rewind.Frequency.Every",
		{
			{EN, "Every"},
			{RU, "Каждые"}
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
		"Settings.Emulator.Rewind.States",
		{
			{EN, "states"},
			{RU, "состояний"}
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
		"Settings.Enhancements.RunAhead",
		{
			{EN, "Run-Ahead"},
			{RU, "Опережающая эмуляция (Run-Ahead)"}
		}
	},
	{
		"Settings.Enhancements.RunAhead.One",
		{
			{EN, "One"},
			{RU, "Один"}
		}
	},
	{
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
		"Settings.Enhancements.Video",
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
		"Settings.Enhancements.hdMode7.fastPpuOnly",
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
		"Settings.Enhancements.hdMode7.HdSdMosaic",
		{
			{EN, "HD→SD Mosaic"},
			{RU, "Мозаичность HD→SD"}
		}
	},
	{
		"Settings.Enhancements.Dsp.audio",
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
			{EN, "Prefer HLE"},
			{RU, "Предпочитать высокоуровневую эмуляцию (HLE)"}
		}
	},
	{
		"Settings.Enhancements.Coprocessors.PreferHle.tooltip",
		{
			{
				EN,
				"When checked, less accurate HLE emulation will always be used when available.\n"
				"When unchecked, HLE will only be used when LLE firmware is missing."
			},
			{
				RU,
				"Когда включено, менее точная высокоуровневая эмуляция будет использоваться всегда, когда возможно.\n"
				"Когда выключено, высокоуровневая эмуляция будет использоваться только при отсутствии низкоуровневой прошивки."
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
		"Settings.noteGameRestart",
		{
			{EN, "Note: some settings do not take effect until after reloading games."},
			{RU, "Примечание: некоторые настройки применяются только после перезапуска игры."}
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
				"Используйте этот вариант при разработке новых программ для SNES, чтобы гарантировать максимальную совместимость с реальным оборудованием."
			}
		}
	},
	{
		"Settings.Compatibility.cpu.processor",
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
		"Settings.Compatibility.ppu.video",
		{
			{EN, "video"},
			{RU, "видео"}
		}
	},
	{
		"Settings.Compatibility.ppu.NoVramBlocking",
		{
			{EN, "No VRAM blocking"},
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
				"Этот параметр включает эмуляцию ошибки старых версий ZSNES and Snes9x, где блокировка видеопамяти не эмулировалась.\n"
				"Некоторые старые ROM-хаки рассчитывали на это поведение и будут отрисовываться неправильно, если этот параметр не включить.\n"
				"Это не только сильно отличается от поведения реального оборудования, но и снижает быстродействие быстрого PPU.\n"
				"Не включайте этот параметр, если вам не требуется поиграть в игру, в противном случае работающую неправильно."
			}
		}
	},
	{
		"Settings.Compatibility.dsp.audio",
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
				"Этот параметр включает эмуляцию ошибки ZSNES, из-за которой отображаемая память (echo RAM) рассматривалась отдельно от памяти APU.\n"
				"Многие старые ROM-хаки «Super Mario World» рассчитывали на это поведение и не будут работать без включения этого параметра.\n"
				"Однако это сильно отличается от поведения реального оборудования, и не следует включать этот параметр без необходимости."
			}
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
		"Settings.Drivers.Synchronize",
		{
			{EN, "Synchronize"},
			{RU, "Синхронизация"}
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
		"Settings.Drivers.ActiveDriver",
		{
			{EN, "Active driver"},
			{RU, "Активный драйвер"}
		}
	},
	{
		"Settings.Drivers.Video",
		{
			{EN, "Video"},
			{RU, "Видео"}
		}
	},
	{
		"Settings.Drivers.Video.FullscreenMonitor",
		{
			{EN, "Fullscreen monitor"},
			{RU, "Полноэкранный монитор"}
		}
	},
	{
		"Settings.Drivers.Video.FullscreenMonitor.tooltip",
		{
			{EN, "Sets which monitor video is sent to in fullscreen mode."},
			{RU, "Устанавливает, на какой монитор отправляется видео в полноэкранном режиме."}
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
				"Causes fullscreen mode to take over all monitors.\n"
				"This allows adaptive sync to work better and reduces input latency.\n"
				"However, multi-monitor users should turn this option off.\n"
				"Note: Direct3D exclusive mode also does not honor the requested monitor."
			},
			{
				RU,
				"Приводит к тому, что в полноэкранном режиме изображение занимает все мониторы.\n"
				"Позволяет адаптивной синхронизации (adaptive sync) работать лучше и уменьшает задержку ввода.\n"
				"Однако пользователям многомониторных конфигураций имеет смысл отключить этот параметр.\n"
				"Примечание: эксклюзивный режим Direct3D также не учитывает выбранный монитор."
			}
		}
	},
	{
		"Settings.Drivers.Video.Synchronize.tooltip",
		{
			{
				EN,
				"Waits for the video card to be ready before rendering frames.\n"
				"Eliminates dropped or duplicated frames; but can distort audio.\n\n"
				"With this option, it's recommended to disable audio sync,\n"
				"and enable dynamic rate control. Or alternatively, adjust the\n"
				"audio skew option to reduce buffer under/overflows."
			},
			{
				RU,
				"Ожидает готовности видеокарты перед отрисовкой кадров.\n"
				"Устраняет пропуск или повторение кадррв, но может искажать звук.\n\n"
				"При использовании этого параметра рекомендуется отключить синхронизацию\n"
				"звука и включить динамическое управление частотой. Как вариант, подстройте\n"
				"звуковой параметр «Частота» для уменьшения опустошения/переполнения буфера."
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
		"Settings.Drivers.Audio",
		{
			{EN, "Audio"},
			{RU, "Звук"}
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
		"Settings.Drivers.Audio.Frequency",
		{
			{EN, "Frequency"},
			{RU, "Частота"}
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
				"Даёт исключительный доступ к звуковой карте.\n"
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
				"With this option, it's recommended to disable video sync.\n"
				"For best results, use this with an adaptive sync monitor."
			},
			{
				RU,
				"Ожидает готовности звуковой карты перед выводом звука.\n"
				"Устраняет искажения звука, но может искажать видео.\n\n"
				"При использовании этого параметра рекомендуется отключить синхронизацию видео.\n"
				"Для наилучших результатов используйте с монитором с поддержкой адаптивной синхронизации."
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
				"Используйте совместно со включённой синхронизацией видео \n"
				"и отключённой синхронизацией звука.\n\n"
				"Результатом могут быть идеально плавное видео и чистый звук,\n"
				"но только при правильно установленной частоте обновления монитора:\n"
				"60 Гц для игр NTSC, и 50 Гц для игр PAL."
			}
		}
	},
	{
		"Settings.Drivers.Input",
		{
			{EN, "Input"},
			{RU, "Устройства ввода"}
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
				"Перезагрузку драйвера можно использовать для обнаружения устройств,\n"
				"подключённых в «горячем» режиме.\n"
				"Полезно для программных интерфейсов (API), не поддерживающих горячее\n"
				"подключение, таких как DirectInput и SDL."
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
		"Settings.Drivers.syncModePresets.DynamicRateControl",
		{
			{EN, "Dynamic Rate Control"},
			{RU, "Динамическое управление частотой"}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync.Failure.tooltip",
		{
			{
				EN,
				"Sorry, the current driver configuration is\n"
				"not compatible with adaptive sync mode.\n"
				"Adaptive sync requires audio synchronization support."
			},
			{
				RU,
				"Извините, текущая конфигруация драйверов несовместима\n"
				"с режимом адаптивной синхронизации.\n"
				"Для адаптивной синхронизации требуется поддержка синхронизации звука."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.AdaptiveSync.Success.tooltip",
		{
			{
				EN,
				"Adaptive sync works best in exclusive fullscreen mode.\n"
				"Use the lowest audio latency setting your system can manage.\n"
				"A G-Sync or FreeSync monitor is required.\n"
				"Adaptive sync must be enabled in your driver settings panel."
			},
			{
				RU,
				"Адаптивная синхронизация лучше всего работает\n"
				"в эксклюзивном полноэкранном режиме.\n"
				"Используйте минимальную задержку звука,\n"
				"которая возможна на вашей системе.\n"
				"Требуется монитор с поддержкой G-Sync или FreeSync.\n"
				"Требуется включить адаптивную синхронизацию\n"
				"в панели управления вашего видеодрайвера."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl.Failure.tooltip",
		{
			{
				EN,
				"Sorry, the current driver configuration is\n"
				"not compatible with dynamic rate control mode.\n"
				"Dynamic rate control requires video synchronization\n"
				"and audio dynamic rate support."
			},
			{
				RU,
				"Извините, текущая конфигруация драйверов несовместима\n"
				"с режимом динамического управления частотой.\n"
				"Для динамического управления частотой требуется поддержка\n"
				"видеосинхронизации и динамического изменения частоты звука."
			}
		}
	},
	{
		"Settings.Drivers.syncModePresets.DynamicRateControl.Success.tooltip",
		{
			{
				EN,
				"Dynamic rate control requires your monitor to be running at:\n"
				"60 Hz refresh rate for NTSC games, 50 Hz refresh rate for PAL games.\n"
				"Use the lowest audio latency setting your system can manage."
			},
			{
				RU,
				"Для динамического управления частотой требуется,\n"
				"чтобы частота обновления вашего монитора была:\n"
				"60 Гц для игр NTSC, 50 Гц для игр PAL.\n"
				"Используйте минимальную задержку звука,\n"
				"которая возможна на вашей системе."
			}
		}
	},
	{
		"Settings.Drivers.changeConfirm",
		{
			{
				EN,
				"Warning: incompatible drivers may cause the application to crash.\n"
				"It is highly recommended you unload your game first to be safe.\n"
				"Do you wish to proceed with the video driver change now anyway?"
			},
			{
				RU,
				"Внимание: несовместимые драйверы могут привести\n"
				"к невозможности работы программы.\n"
				"Для безопасности настоятельно рекомендуется\n"
				"сначала закрыть вашу игру.\n"
				"Хотите ли вы изменить драйвер в любом случае?"
			}
		}
	},
	{
		"Game.VerifiedGameLoaded",
		{
			{EN, "Verified game loaded"},
			{RU, "Открыта проверенная игра"}
		}
	},
	{
		"Game.GameLoaded",
		{
			{EN, "Game loaded"},
			{RU, "Открыта игра"}
		}
	},
	{
		"Game.GameUnloaded",
		{
			{EN, "Game unloaded"},
			{RU, "Закрыта игра"}
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
		"Game.GameLoadedingCancelled",
		{
			{EN, "Game loading cancelled"},
			{RU, "Открытие игры отменено"}
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
			{EN, "Gamepad"},
			{RU, "Геймпад"},
			{JP, "ゲームパッド"}
		}
	},
	{
		"Mouse",
		{
			{EN, "Mouse"},
			{RU, "Мышь"},
			{JP, "マウス"}
		}
	},
	{
		"Super Multitap",
		{
			{EN, "Super Multitap"},
			{JP, "スーパーマルチタップ"}
		}
	},
	{
		"Super Scope",
		{
			{EN, "Super Scope"},
			{JP, "スーパースコップ"}
		}
	},
	{
		"Justifier",
		{
			{EN, "Justifier"},
			{JP, "1挺のジャスティファイアー"}
		}
	},
	{
		"Justifiers",
		{
			{EN, "Justifiers"},
			{JP, "2挺のジャスティファイアー"}
		}
	},
	{
		"Satellaview",
		{
			{EN, "Satellaview"},
			{JP, "サテラビュー"}
		}
	}
};

static map<string, map<uint8_t, string>> hotkeyStrings = {
	{
		"Toggle Fullscreen",
		{
			{EN, "Toggle Fullscreen"},
			{RU, "Полноэкранный режим"}
		}
	},
	{
		"Toggle Pseudo-Fullscreen",
		{
			{EN, "Toggle Pseudo-Fullscreen"},
			{RU, "Псевдополноэкранный режим"}
		}
	},
	{
		"Toggle Mouse Capture",
		{
			{EN, "Toggle Mouse Capture"},
			{RU, "Захват указателя мыши"}
		}
	},
	{
		"Toggle Cheat Codes",
		{
			{EN, "Toggle Cheat Codes"},
			{RU, "Применение чит-кодов"}
		}
	},
	{
		"Toggle Mute",
		{
			{EN, "Toggle Mute"},
			{RU, "Отключение звука"}
		}
	},
	{
		"Rewind",
		{
			{EN, "Rewind"},
			{RU, "Перемотка назад"}
		}
	},
	{
		"Save State",
		{
			{EN, "Save State"},
			{RU, "Сохранение состояния"}
		}
	},
	{
		"Load State",
		{
			{EN, "Load State"},
			{RU, "Загрузка состояния"}
		}
	},
	{
		"Load Undo State",
		{
			{EN, "Load Undo State"},
			{RU, "Загрузка состояния отмены действия"}
		}
	},
	{
		"Load Redo State",
		{
			{EN, "Load Redo State"},
			{RU, "Загрузка состояния повтора действия"}
		}
	},
	{
		"Decrement State Slot",
		{
			{EN, "Decrement State Slot"},
			{RU, "Предыдущий слот быстрого сохранения"}
		}
	},
	{
		"Increment State Slot",
		{
			{EN, "Increment State Slot"},
			{RU, "Следующий слот быстрого сохранения"}
		}
	},
	{
		"Capture Screenshot",
		{
			{EN, "Capture Screenshot"},
			{RU, "Скриншот"}
		}
	},
	{
		"Fast Forward",
		{
			{EN, "Fast Forward"},
			{RU, "Перемотка вперёд"}
		}
	},
	{
		"Pause Emulation",
		{
			{EN, "Pause Emulation"},
			{RU, "Приостановка эмуляции"}
		}
	},
	{
		"Frame Advance",
		{
			{EN, "Frame Advance"},
			{RU, "Переход к следующему кадру"}
		}
	},
	{
		"Decrease HD Mode 7",
		{
			{EN, "Decrease HD Mode 7"},
			{RU, "Уменьшение разрешения HD Mode 7"}
		}
	},
	{
		"Increase HD Mode 7",
		{
			{EN, "Increase HD Mode 7"},
			{RU, "Увеличение разрешения HD Mode 7"}
		}
	},
	{
		"Toggle Supersampling",
		{
			{EN, "Toggle Supersampling"},
			{RU, "Избыточная выборка"}
		}
	},
	{
		"Reset Emulation",
		{
			{EN, "Reset Emulation"},
			{RU, "Сброс эмуляции"}
		}
	},
	{
		"Quit Emulator",
		{
			{EN, "Quit Emulator"},
			{RU, "Выход из эмулятора"}
		}
	}
};

} // namespace bsnesMt::strings