# bsnes-mt by Marat Tanalin

bsnes version with image-quality, user-experience and other improvements:

* Pixel-perfect integer-ratio scaling.
* Precise 4:3 in the “Center” and “Scale” modes.
* Compressed PNG screenshots.
* Multilanguage user interface.
* Built-in hotkeys for common actions, and more.

See the project [webpage](http://tanalin.com/en/projects/bsnes-mt/) for details.

## Contributing translations

Feel free to contribute user-interface translations. That’s easy even if you are not a programmer.

The app is already available in English and Russian, and partially Italian and Japanese. English and Russian translations are complete and don’t need contributions. The English translation is built into the executable, other translations are loaded from text files when starting the application.

Each translation is in a text file in the [`bsnes-mt/translations`](https://github.com/Marat-Tanalin/bsnes-mt/blob/master/bsnes-mt/translations) folder. The files use the UTF-8 character encoding. The files are named according to two-letter codes defined in the ISO 639-1 standard:

* `en.txt` for English;
* `ru.txt` for Russian;
* `it.txt` for Italian;
* `ja.txt` for Japanese.

Partial translations are possible: if a string is not translated, just the original English-language string is automatically used instead.

Start with translating menus (`Menu.*`), then settings (`Settings.*`) and common strings (`Common.*`) — they form the main part of the user interface.

## How to compile/build

[Install MinGW](https://github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2), then execute the following command inside the folder with bsnes-mt source code:

```
mingw32-make -C bsnes target=bsnes
```

Like original bsnes, bsnes-mt cannot be built with Visual Studio for now.

bsnes-mt is Windows-only.