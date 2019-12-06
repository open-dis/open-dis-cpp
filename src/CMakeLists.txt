include_directories(./)

# Only go into specific sub directories
add_subdirectory(dis6)
add_subdirectory(dis7) # premake script does not build this, and anyway it has build errors
add_subdirectory(utils)

set(PROJECT_LIBS ${PROJECT_LIBS} PARENT_SCOPE)

