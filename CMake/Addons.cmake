
list(APPEND INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src_addon)

include("CMake/Editor.cmake")
include("CMake/Navigation.cmake")

message("_________________ ADDONS CMAKE ${INCLUDE_DIRS}")

