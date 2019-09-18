# Get premake5
mkdir tmp
cd tmp/
wget https://github.com/premake/premake-core/releases/download/v5.0.0-alpha6/premake-5.0.0-alpha6-src.zip -O premake.zip
unzip premake.zip
cd premake-5.0.0-alpha6/build/gmake.unix
make -j8 config=release
cd ../../..
mv premake-5.0.0-alpha6/bin/release/premake5 ~/premake5 # Move premake5 to lib dir