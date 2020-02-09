

file( GLOB_RECURSE EDITOR_SOURCE_FILES FOLLOW_SYMLINKS ${CMAKE_CURRENT_SOURCE_DIR} src_addon/Editor/*.cpp src_addon/Editor/*.h )

message("_________________ This is the editor cmake: ${EDITOR_SOURCE_FILES}")

list(APPEND SOURCE_FILES ${EDITOR_SOURCE_FILES})
