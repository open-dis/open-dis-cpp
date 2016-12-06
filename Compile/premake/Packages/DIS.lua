-- graphics DLL
-- project level
--package = newpackage()
package.name = "DIS"
-- print( target )
package.path = "../../" .. options["target"] --.. "/" .. package.name

-- project resulting build name
package.config.Release.target = package.name
package.config.Debug.target = package.name .. "_debug"

package.config.Release.objdir = "obj_" .. options["target"] .. "_" .. package.name
package.config.Debug.objdir = "obj_" .. options["target"] .. "_" .. package.name .. "_debug"

-- project build type
package.kind = "dll"
package.language = "c++"

-- project preprocessors
if(windows) then
	exportenabler = "EXPORT_LIBRARY"
	debugpkg = package.config.Debug
	debugpkg.defines = { "WIN32", "_DEBUG" , exportenabler }

	releasepkg = package.config.Release
	releasepkg.defines = { "WIN32", exportenabler }
else
	debugpkg = package.config.Debug
	debugpkg.defines = { "_DEBUG" }
end

-- project sources, relative to the project file's directory, a.k.a. the package path
package.files = {
  matchrecursive("../../cpp/DIS/*.h", "../../cpp/DIS/*.cpp"),
  matchrecursive("../../CppUtils/DIS/*.h", "../../CppUtils/DIS/*.cpp")
}

-- project dependencies
  -- project include dependencies.  again, relative to the package path
dis_inc_dir = "../../cpp"
dis_ext_dir = "../../CppUtils"
package.includepaths = { dis_inc_dir , dis_ext_dir }

