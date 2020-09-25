target := bsnes
binary := application
build := performance
openmp := true
local := false
flags += -I. -I..

# in order for this to work, obj/lzma.o must be omitted or bsnes will hang on startup.
# further, only the X-Video driver works reliably. OpenGL 3.2, OpenGL 2.0, and XShm crash bsnes.
ifeq ($(profile),true)
  flags += -pg
  options += -pg
endif

# binaries built with this flag are faster, but are not portable to multiple machines.
ifeq ($(local),true)
  flags += -march=native
endif

nall.path := ../nall
include $(nall.path)/GNUmakefile

ifeq ($(platform),windows)
  ifeq ($(binary),application)
    # `-lgdiplus` is added by MT.
    options += -luuid -lkernel32 -luser32 -lgdi32 -lcomctl32 -lcomdlg32 -lshell32 -lgdiplus
    options += -Wl,-enable-auto-import
    options += -Wl,-enable-runtime-pseudo-reloc
    options += -s # MT.
  else ifeq ($(binary),library)
    options += -shared
  endif
else ifeq ($(platform),macos)
  ifeq ($(binary),application)
  else ifeq ($(binary),library)
    flags += -fPIC
    options += -dynamiclib
  endif
else ifneq ($(filter $(platform),linux bsd),)
  ifeq ($(binary),application)
    options += -Wl,-export-dynamic
    options += -lX11 -lXext
  else ifeq ($(binary),library)
    flags += -fPIC
    options += -shared
  endif
endif

# `bsnes-mt-*` are added by MT.
objects := libco emulator filter lzma bsnes-mt-scaling bsnes-mt-windows bsnes-mt-messagebox bsnes-mt-is bsnes-mt-png-pixel bsnes-mt-png-chunk bsnes-mt-png-image bsnes-mt-strings bsnes-mt-translations bsnes-mt-utils bsnes-mt-kb bsnes-mt-files

obj/bsnes-mt-scaling.o: ../bsnes-mt/scaling.cpp # MT.
obj/bsnes-mt-windows.o: ../bsnes-mt/windows.cpp # MT.
obj/bsnes-mt-messagebox.o: ../bsnes-mt/messagebox.cpp # MT.
obj/bsnes-mt-is.o: ../bsnes-mt/integer-scaling/IntegerScaling.cpp # MT.
obj/bsnes-mt-png-pixel.o: ../bsnes-mt/pizza-png/src/Pixel.cpp # MT.
obj/bsnes-mt-png-chunk.o: ../bsnes-mt/pizza-png/src/Chunk.cpp # MT.
obj/bsnes-mt-png-image.o: ../bsnes-mt/pizza-png/src/Image.cpp # MT.
obj/bsnes-mt-strings.o: ../bsnes-mt/strings.cpp # MT.
obj/bsnes-mt-translations.o: ../bsnes-mt/translations.cpp # MT.
obj/bsnes-mt-utils.o: ../bsnes-mt/utils.cpp # MT.
obj/bsnes-mt-kb.o: ../bsnes-mt/keyboard.cpp # MT.
obj/bsnes-mt-files.o: ../bsnes-mt/files.cpp # MT.
obj/libco.o: ../libco/libco.c
obj/emulator.o: emulator/emulator.cpp
obj/filter.o: filter/filter.cpp
obj/lzma.o: lzma/lzma.cpp

include sfc/GNUmakefile
include gb/GNUmakefile
include processor/GNUmakefile

ui := target-$(target)
include $(ui)/GNUmakefile
-include obj/*.d

clean:
	$(call delete,obj/*)
	$(call delete,out/*)
