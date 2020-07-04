#pragma once

#if defined(_MSC_VER) && !defined(__clang__)

#  undef MO_COMPILER_MSVC
#  define MO_COMPILER_MSVC MO_ON

#  ifdef __clang__
#    undef MO_COMPILER_MSVC_CLANG
#    define MO_COMPILER_MSVC_CLANG MO_ON
#  else
#    undef MO_COMPILER_MSVC_PURE
#    define MO_COMPILER_MSVC_PURE MO_ON
#  endif

#  ifdef _DEBUG
#    undef MO_COMPILE_FOR_DEBUG
#    define MO_COMPILE_FOR_DEBUG MO_ON
#  endif


// Functions marked as MO_ALWAYS_INLINE will be inlined even in Debug builds, which means you will step over them in a debugger
#  define MO_ALWAYS_INLINE __forceinline

#  if MO_ENABLED(MO_COMPILE_FOR_DEBUG)
#    define MO_FORCE_INLINE inline
#  else
#    define MO_FORCE_INLINE __forceinline
#  endif

#  ifdef __INTELLISENSE__
#    define MO_ALIGN(decl, alignment) decl
#    define MO_ALIGN_VARIABLE(decl, alignment) decl
#  else
#    define MO_ALIGN(decl, alignment) __declspec(align(alignment)) decl
#    define MO_ALIGN_VARIABLE(decl, alignment) __declspec(align(alignment)) decl
#  endif

// workaround for msvc compiler issue with alignment determination of dependent types
#  define MO_ALIGNMENT_OF(type) MO_COMPILE_TIME_MAX(MO_ALIGNMENT_MINIMUM, MO_COMPILE_TIME_MIN(sizeof(type), __alignof(type)))

#  define MO_DEBUG_BREAK \
    {                    \
      __debugbreak();    \
    }

#  if MO_ENABLED(MO_COMPILER_MSVC_CLANG)
#    define MO_SOURCE_FUNCTION __PRETTY_FUNCTION__
#  else
#    define MO_SOURCE_FUNCTION __FUNCTION__
#  endif

#  define MO_SOURCE_LINE __LINE__
#  define MO_SOURCE_FILE __FILE__

// MO_VA_NUM_ARGS() is a very nifty macro to retrieve the number of arguments handed to a variable-argument macro
// unfortunately, VS 2010 still has this compiler bug which treats a __VA_ARGS__ argument as being one single parameter:
// https://connect.microsoft.com/VisualStudio/feedback/details/521844/variadic-macro-treating-va-args-as-a-single-parameter-for-other-macros#details
#  if _MSC_VER >= 1400 && MO_DISABLED(MO_COMPILER_MSVC_CLANG)
#    define MO_VA_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...) N
#    define MO_VA_NUM_ARGS_REVERSE_SEQUENCE 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
#    define MO_LEFT_PARENTHESIS (
#    define MO_RIGHT_PARENTHESIS )
#    define MO_VA_NUM_ARGS(...) MO_VA_NUM_ARGS_HELPER MO_LEFT_PARENTHESIS __VA_ARGS__, MO_VA_NUM_ARGS_REVERSE_SEQUENCE MO_RIGHT_PARENTHESIS
#  endif

#endif
