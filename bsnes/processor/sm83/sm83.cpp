#include <processor/processor.hpp>
#include "sm83.hpp"

namespace Processor {

#include "_registers.cpp"
#include "_memory.cpp"
#include "_algorithms.cpp"
#include "_instruction.cpp"
#include "_instructions.cpp"
#include "_serialization.cpp"
#include "_disassembler.cpp"

auto SM83::power() -> void {
  r = {};
}

}
