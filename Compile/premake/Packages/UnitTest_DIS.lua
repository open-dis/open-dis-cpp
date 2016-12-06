-- example of graphics DLL
-- project level
package.name = "UnitTest_DIS"
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
if( windows ) then
debugpkg.defines = { "WIN32", "_DEBUG", "_CONSOLE" }
releasepkg.defines = { "WIN32", "_CONSOLE" }
end

-- project sources, relative to the project file's directory, a.k.a. the package path
package.files = {
  matchrecursive("../../UnitTestDIS/*.h", "../../UnitTestDIS/*.cpp")
}

-- project dependencies
  -- project include dependencies.  again, relative to the package path
dis_inc_dir = "../../cpp"
dis_ext_dir = "../../CppUtils"
cppunit_inc_dir = os.getenv("CPPUNIT_INC")
if( cppunit_inc_dir ) then
package.includepaths = { dis_inc_dir , dis_ext_dir, "$(CPPUNIT_INC)" }
else
package.includepaths = { dis_inc_dir , dis_ext_dir }
end

  -- project library dependencies
dis_pkg_name = "DIS"
cppunit_lib_name = "cppunit"
package.links = { dis_pkg_name, cppunit_lib_name }
cppunit_lib_dir = os.getenv("CPPUNIT_LIB")
if( cppunit_lib_dir ) then
package.libpaths = { "$(CPPUNIT_LIB)" }
else
package.libpaths = {}
end
