This is an example usage of the DIS implementation.
It shows how to send/receive data to a DIS network.

The main idea is to use the library to pack and send/receive data.
The example socket implementation is outside the scope
of the DIS implementation, but provided so that the
testing is complete.  This socket implementation depends
upon the HawkNL library.  Please visit
http://www.hawksoft.com/hawknl/
for information about how to download, build, and install the SDK.
I am using version 1.68 of HawkNL.

When compiling, the project files reference the following environment variables:
HAWKNL_INC_DIR
HAWKNL_LIB_DIR

For example, if the package was located at the following:
C:\hawknl1.68
Then the environment variables could be defined as such:
HAWKNL_INC_DIR=C:\hawknl1.68\include
HAWKNL_LIB_DIR=C:\hawknl1.68\lib
