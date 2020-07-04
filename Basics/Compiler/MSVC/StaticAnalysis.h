
#pragma once

#undef MO_MSVC_ANALYSIS_WARNING_PUSH
#undef MO_MSVC_ANALYSIS_WARNING_POP
#undef MO_MSVC_ANALYSIS_WARNING_DISABLE
#undef MO_MSVC_ANALYSIS_ASSUME

// These use the __pragma version to control the warnings so that they can be used within other macros etc.
#define MO_MSVC_ANALYSIS_WARNING_PUSH __pragma(warning(push))
#define MO_MSVC_ANALYSIS_WARNING_POP __pragma(warning(pop))
#define MO_MSVC_ANALYSIS_WARNING_DISABLE(warningNumber) __pragma(warning(disable : warningNumber))
#define MO_MSVC_ANALYSIS_ASSUME(expression) __assume(expression)
