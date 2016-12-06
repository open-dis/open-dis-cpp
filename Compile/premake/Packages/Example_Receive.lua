-- example of graphics DLL
-- project level
package.name = "Example_Receive"
package.path = "../../" .. options["target"] --.. "/" .. package.name

-- project resulting build name
package.config.Release.target = package.name
package.config.Debug.target = package.name .. "_debug"

package.config.Release.objdir = "obj_" .. options["target"] .. "_" .. package.name
package.config.Debug.objdir = "obj_" .. options["target"] .. "_" .. package.name .. "_debug"

-- project build type
package.kind = "exe"
package.language = "c++"

-- project preprocessors
debugpkg = package.config.Debug
debugpkg.defines = { "_DEBUG" }
releasepkg = package.config.Release
releasepkg.defines = { }
if( windows ) then
debugpkg.defines = { "WIN32", "_DEBUG", "_CONSOLE" }
releasepkg.defines = { "WIN32", "_CONSOLE" }
end

-- project sources, relative to the project file's directory, a.k.a. the package path
package.files = {
  "../../Example/main_receive.cpp",
  "../../Example/Connection.h",
  "../../Example/Connection.cpp",
  "../../Example/Utils.h",
  "../../Example/Utils.cpp",
  "../../Example/EntityStatePduProcessor.h",
  "../../Example/EntityStatePduProcessor.cpp"
}

-- project dependencies
  -- project include dependencies.  again, relative to the package path
dis_inc_dir = "../../cpp"
dis_ext_dir = "../../CppUtils"
example_inc_dir = "../.."
hawk_inc_dir = os.getenv("HAWKNL_INC_DIR")
if( hawk_inc_dir ) then
package.includepaths = { example_inc_dir, dis_inc_dir , dis_ext_dir, "$(HAWKNL_INC_DIR)" }
else
package.includepaths = { example_inc_dir, dis_inc_dir , dis_ext_dir }
end

  -- project library dependencies
dis_pkg_name = "DIS"
hawknl_lib_name = "NL"
if( windows ) then
  hawknl_lib_name = "HawkNL"
end
if( linux ) then
  pthreads_name = "pthread"
  stdlib_name = "stdc++"
  package.links = { hawknl_lib_name, dis_pkg_name, pthreads_name, stdlib_name }
else
  package.links = { hawknl_lib_name, dis_pkg_name }
end

hawk_lib_dir = os.getenv("HAWKNL_LIB_DIR")
if( hawk_lib_dir ) then
package.libpaths = { "$(HAWKNL_LIB_DIR)" }
else
package.libpaths = {}
end
