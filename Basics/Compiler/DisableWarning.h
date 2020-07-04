
// Does nothing when not on MSVC
#if MO_ENABLED(MO_COMPILER_MSVC) && defined(MO_MSVC_WARNING_NUMBER)
#include <Foundation/Basics/Compiler/MSVC/DisableWarning_MSVC.h>
#endif


#undef MO_MSVC_WARNING_NUMBER

