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

Build instructions:
See project README.md, in repo root directory.

Running instructions: 
Run `ExampleReceiver` and `ExampleSender` in seperate terminals
