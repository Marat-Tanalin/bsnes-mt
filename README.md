# bsnes-mt by Marat Tanalin

bsnes version with image-quality, user-experience and other improvements:

* Pixel-perfect integer-ratio scaling.
* Precise 4:3 in the “Center” and “Scale” modes.
* Compressed PNG screenshots.
* User interface in both English and Russian, and more.

See the project [webpage](http://tanalin.com/en/projects/bsnes-mt/) for details.

## Contributing translations

Feel free to contribute user-interface translations. That’s easy even if you are not a programmer.

The app is already available in English and Russian, and partially Japanese. English and Russian translations are complete and don’t need contributions.

Translations are in the [`bsnes-mt/translations.h`](https://github.com/Marat-Tanalin/bsnes-mt/blob/master/bsnes-mt/translations.h) file (uses UTF-8 character encoding).

Partial translations are possible: if a string is not translated, just the original English-language string is automatically used instead.

Start with translating menus (`Menu.*`), then settings (`Settings.*`) and common strings (`Common.*`) — they form the main part of the user interface.

## How to compile/build

[Install MinGW](https://github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2), then execute the following command inside the folder with bsnes-mt source code:

```
mingw32-make -C bsnes target=bsnes
```

Like original bsnes, bsnes-mt cannot be built with Visual Studio for now.

bsnes-mt is Windows-only.