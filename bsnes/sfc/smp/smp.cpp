#include <sfc/sfc.hpp>

namespace SuperFamicom {

SMP smp;

#include "_memory.cpp"
#include "_io.cpp"
#include "_timing.cpp"
#include "_serialization.cpp"

auto SMP::synchronizeCPU() -> void {
  if(clock >= 0) scheduler.resume(cpu.thread);
}

auto SMP::synchronizeDSP() -> void {
  while(dsp.clock < 0) dsp.main();
}

auto SMP::Enter() -> void {
  while(true) {
    scheduler.synchronize();
    smp.main();
  }
}

auto SMP::main() -> void {
  if(r.wait) return instructionWait();
  if(r.stop) return instructionStop();
  instruction();
}

auto SMP::load() -> bool {
  if(auto fp = platform->open(ID::System, "ipl.rom", File::Read, File::Required)) {
    fp->read(iplrom, 64);
    return true;
  }
  return false;
}

auto SMP::power(bool reset) -> void {
  SPC700::power();
  create(Enter, system.apuFrequency() / 12.0);

  r.pc.byte.l = iplrom[62];
  r.pc.byte.h = iplrom[63];

  io = {};
  timer0 = {};
  timer1 = {};
  timer2 = {};
}

}
