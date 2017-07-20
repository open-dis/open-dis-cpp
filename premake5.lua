--
-- premake5 file to build open-dis-cpp
-- http://premake.github.io/
--

workspace "open-dis-cpp"
  configurations { 
    "Debug",
    "Release"
  }
  targetdir "Build/lib/%{cfg.buildcfg}"
  configuration "Debug*"
    defines { "DEBUG" }
 
  configuration "Release*"
    defines { "NDEBUG" }
    optimize "On"

  configuration "windows"
    defines { "WIN32" }

  configuration { "linux", "gmake" }
    buildoptions {
      "-Wall",
      "-Werror"
    }

project "OpenDIS"
  language "C++"
  kind "StaticLib"
  includedirs { 
    "cpp",
    "CppUtils"
  }
  files { 
    "cpp/DIS/*.h",
    "cpp/DIS/*.cpp",
    "CppUtils/DIS/*.h",
    "CppUtils/DIS/*.cpp"
  }
