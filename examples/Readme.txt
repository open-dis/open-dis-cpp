This is an example usage of the DIS implementation.
It shows how to send/receive data to a DIS network.

The main idea is to use the library to pack and send/receive data.
The example socket implementation is outside the scope
of the DIS implementation, but provided so that the
testing is complete.  This socket implementation depends upon the the SDL2_net
library. Please visit https://www.libsdl.org/ for information about how to
 download, build, and install the Libraries.

SDL2 also provides timing functionality. I.e. calculating delta between frames
and for sleep delays.

The current `#include` are written with the prefix "SDL2/" because the
contributor was unfamiliar with premake5.
Normally it is recommended to add the output of `sdl2-config --cflags` and
`sdl2-config --libs` to the build process, however it was unclear if this
work across different systems.

Build instructions:
1. cd to the repo root
2. run `premake5 gmake` (If not done already)
3. run `make`
Files will be located in ./Build/lib/Debug
Running instructions: 
1. open up 2 terminals in the git repo root:
2. Run `./Build/lib/Debug/ExampleReciever` in one terminal
3. Run `./Build/lib/Debug/ExampleSender` in the other terminal
