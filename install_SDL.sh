# Download and build SDL2 from source
wget http://libsdl.org/release/SDL2-2.0.9.tar.gz
tar -xvf SDL2-2.0.9.tar.gz
pushd SDL2-2.0.9/
./configure --prefix=/usr && make && sudo make install
popd

# Run sdl2-config for debugging -- protentially remove this
sdl2-config --cflags --libs

# Download and build SDL2_net as well from source
wget https://www.libsdl.org/projects/SDL_net/release/SDL2_net-2.0.1.tar.gz
tar -xvf SDL2_net-2.0.1.tar.gz
pushd SDL2_net-2.0.1/
./configure --prefix=/usr && make && sudo make install
popd