#include <emulator/emulator.hpp>

#undef register
#define register
#include "sai/_sai.cpp"

uint32_t* colortable;
#include "snes_ntsc/snes_ntsc.h"
#include "snes_ntsc/_snes_ntsc.c"

#include "_none.cpp"
#include "_scanlines-light.cpp"
#include "_scanlines-dark.cpp"
#include "_scanlines-black.cpp"
#include "_pixellate2x.cpp"
#include "_scale2x.cpp"
#include "_2xsai.cpp"
#include "_super-2xsai.cpp"
#include "_super-eagle.cpp"
#include "_lq2x.cpp"
#include "_hq2x.cpp"
#include "_ntsc-rf.cpp"
#include "_ntsc-composite.cpp"
#include "_ntsc-svideo.cpp"
#include "_ntsc-rgb.cpp"
