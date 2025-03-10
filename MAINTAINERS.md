# Release Process

1. Update the version number in `CMakeLists.txt` on line 2. Commit the change to master.
2. Create a git tag on the above commit, with the same version number.
3. Create a GitHub [release](https://github.com/open-dis/open-dis-cpp/releases) by clicking "Draft a new Release" button, select the tag, click "Generate release notes", click "Publish release".
4. Make the release available on Conan by updating the [conandata.yml for open-dis-cpp](https://github.com/conan-io/conan-center-index/blob/master/recipes/open-dis-cpp/all/conandata.yml). Create a PR with a change that adds another three lines; `version`, `url`, and `sha256` .
