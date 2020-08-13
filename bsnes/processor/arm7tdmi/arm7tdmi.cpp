#include <processor/processor.hpp>
#include "arm7tdmi.hpp"

namespace Processor {

#include "_registers.cpp"
#include "_memory.cpp"
#include "_algorithms.cpp"
#include "_instruction.cpp"
#include "_instructions-arm.cpp"
#include "_instructions-thumb.cpp"
#include "_serialization.cpp"
#include "_disassembler.cpp"

ARM7TDMI::ARM7TDMI() {
  armInitialize();
  thumbInitialize();
}

auto ARM7TDMI::power() -> void {
  processor = {};
  processor.r15.modify = [&] { pipeline.reload = true; };
  pipeline = {};
  carry = 0;
  irq = 0;
  cpsr().f = 1;
  exception(PSR::SVC, 0x00);
}

}
