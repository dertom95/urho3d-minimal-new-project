

file( GLOB_RECURSE NAVIGATION_SOURCE_FILES FOLLOW_SYMLINKS ${CMAKE_CURRENT_SOURCE_DIR} src_addon/Navigation/*.cpp src_addon/Navigation/*.h )

message("_________________ This is the navigation cmake: ${NAVIGATION_SOURCE_FILES}")

list(APPEND SOURCE_FILES ${NAVIGATION_SOURCE_FILES})
