
#pragma once

#if !defined(__clang__) && (defined(__GNUC__) || defined(__GNUG__))

#  undef MO_COMPILER_GCC
#  define MO_COMPILER_GCC MO_ON

/// \todo re-investigate: attribute(always inline) does not work for some reason
#  define MO_ALWAYS_INLINE inline
#  define MO_FORCE_INLINE inline

#  define MO_ALIGN(decl, alignment) __attribute__((aligned(alignment))) decl
#  define MO_ALIGN_VARIABLE(decl, alignment) decl __attribute__((aligned(alignment)))
#  define MO_ALIGNMENT_OF(type) EZ_COMPILE_TIME_MAX(__alignof(type), MO_ALIGNMENT_MINIMUM)

#  define MO_DEBUG_BREAK \
    {                    \
      __builtin_trap();  \
    }

#  define MO_SOURCE_FUNCTION __PRETTY_FUNCTION__
#  define MO_SOURCE_LINE __LINE__
#  define MO_SOURCE_FILE __FILE__

#endif
