# Release Process

1. Update the version number in `CMakeLists.txt` on line 2. Commit the change to master.
2. Create a git tag on the above commit, with the same version number.
3. Create a GitHub [release](https://github.com/open-dis/open-dis-cpp/releases) by clicking "Draft a new Release" button, and selecting the tag
4. Make the release available on Conan, by updating the [conandata.yml for open-dis-cpp](https://github.com/conan-io/conan-center-index/blob/master/recipes/open-dis-cpp/all/conandata.yml) for this version and opening a PR.
