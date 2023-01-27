#pragma once
#ifdef OpenDIS7_STATIC_DEFINE
#  define EXPORT_MACRO
#else
#  if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#    ifndef EXPORT_MACRO
#      ifdef OpenDIS7_EXPORTS
#        define EXPORT_MACRO __declspec(dllexport)
#      else
#        define EXPORT_MACRO  __declspec(dllimport)
#      endif
#    endif
#  else
#    define EXPORT_MACRO
#  endif
#endif
