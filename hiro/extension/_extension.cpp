#include "extension.hpp"

/* MT. */
#include "bsnes-mt/translations.h"
#include "bsnes-mt/messagebox.h"

namespace bmt = bsnesMt::translations;
namespace bmw = bsnesMt::windows;
/* /MT. */

using namespace nall;

namespace hiro {
  #include "../resource/resource.cpp"
  #include "fixed-layout.cpp"
  #include "horizontal-layout.cpp"
  #include "vertical-layout.cpp"
  #include "table-layout.cpp"
  #include "horizontal-resize-grip.cpp"
  #include "vertical-resize-grip.cpp"
  #include "list-view.cpp"
  // #include "message-dialog.cpp" // Commented-out by MT.
  #include "name-dialog.cpp"
  #include "browser-dialog.cpp"
  #include "about-dialog.cpp"
}
