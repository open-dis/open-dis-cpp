
-- solution level
project.name = "DIS"
project.configs = { "Debug", "Release" }

-- setup the output bin directory
install_bin_dir = os.getenv("DIS_BIN_INSTALL")
if( install_bin_dir ) then
  project.bindir = install_bin_dir
else
  project.bindir = "../../../bin"
end

-- setup the output lib directory
install_lib_dir = os.getenv("DIS_LIB_INSTALL")
if( install_bin_dir ) then
  project.bindir = install_lib_dir
else
  project.libdir = "../../../lib"
end

-- todo change to only, target, rather than options["target"], at the next premake release
project.path = "../../" .. options["target"]

-- assume the directory bug on linux
-- will be avoided when I create the target directory here:
if( linux ) then
  targetdir = "../../" .. options["target"]
  os.execute("mkdir -p " .. targetdir)
end

dopackage("../Packages/DIS")
dopackage("../Packages/UnitTest_DIS")
dopackage("../Packages/Example_Send")
dopackage("../Packages/Example_Receive")

