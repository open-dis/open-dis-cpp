#ifndef MSLIBMACRO_H
#define MSLIBMACRO_H
#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#  ifdef EXPORT_LIBRARY
#    define EXPORT_MACRO __declspec(dllexport)
#  else
#    define EXPORT_MACRO  __declspec(dllimport)
#  endif
#else
#  define EXPORT_MACRO
#endif
#endif
