# bsnes-mt by Marat Tanalin

bsnes version with image-quality, user-experience and other improvements:

* Pixel-perfect integer-ratio scaling.
* Precise 4:3 in the “Center” and “Scale” modes.
* Compressed PNG screenshots.
* Multilanguage user interface.
* Built-in hotkeys for common actions, and more.

See the project [webpage](http://tanalin.com/en/projects/bsnes-mt/) for details.

## Contributing translations

Feel free to contribute user-interface translations. That’s easy even if you are not a programmer. Translations are regular text files with simple `key="value"` syntax.

The canonical translation is [English](https://github.com/Marat-Tanalin/bsnes-mt/blob/master/bsnes-mt/translations/en.txt), other translations should be based on&nbsp;it. Partial translations are possible: if a string is not translated, just the original English-language string is automatically used instead.

The app comes with multiple translations. The default English translation is built into the executable, other translations are loaded dynamically from text files when starting the application. The English and Russian translations are complete and don’t need contributions.

Each translation is in a text file in the [`bsnes-mt/translations`](https://github.com/Marat-Tanalin/bsnes-mt/blob/master/bsnes-mt/translations) folder. The files use the UTF-8 character encoding. The files have lowercase names and are named according to two-letter language codes defined in the [ISO 639-1](https://en.wikipedia.org/wiki/List_of_ISO_639-1_codes) standard with optional subtags according to [BCP&nbsp;47](https://tools.ietf.org/html/bcp47), for example:

* `en.txt` for English;
* `ru.txt` for Russian;
* `pt-br.txt` for Brazilian Portuguese.

Start with translating menus (`Menu.*`), then settings (`Settings.*`) and common strings (`Common.*`) — they form the main part of the user interface.

Don’t bother translating `Browser.*` strings — they are related to non-native file dialogs that are disabled by default and going to be removed from both bsnes and bsnes-mt.

Please ignore capitalization (uppercased first letter of each word) and don’t try to maintain it when translating. For example, translate “Open **R**ecent **G**ame” as if it was “Open **r**ecent **g**ame” with lowercase “r” and “g”.

The “|” character in strings is a placeholder meant to be replaced with a number or word(s) — don’t capitalize words after that character.

## How to compile/build

[Install MinGW](https://github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2), then execute the following command inside the folder with bsnes-mt source code:

```
mingw32-make -C bsnes target=bsnes
```

Like original bsnes, bsnes-mt cannot be built with Visual Studio for now.

bsnes-mt is Windows-only.