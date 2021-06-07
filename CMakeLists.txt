# Set CMake minimum version and CMake policy required by UrhoCommon module
cmake_minimum_required (VERSION 3.10.2)
if (COMMAND cmake_policy)
    # Libraries linked via full path no longer produce linker search paths
    cmake_policy (SET CMP0003 NEW)
    # INTERFACE_LINK_LIBRARIES defines the link interface
    cmake_policy (SET CMP0022 NEW)
    # Disallow use of the LOCATION target property - so we set to OLD as we still need it
    cmake_policy (SET CMP0026 OLD)
    # MACOSX_RPATH is enabled by default
    cmake_policy (SET CMP0042 NEW)
    # Honor the visibility properties for SHARED target types only
    cmake_policy (SET CMP0063 OLD)
endif ()

# Set project name
project (minimal-urho3d)

source_group("Source" ${PROJECT_SOURCE_DIR})

# Set CMake modules search path
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)
# Include UrhoCommon.cmake module after setting project name

# options
option(GAME_ENABLE_DEBUG_TOOLS "Enable Debug-Tools(Editor,Console,Profiler)" ON)
option(GAME_ENABLE_COMPONENT_EXPORTER "Enable Component-Export as JSON" ON)
option(GAME_RETRIEVE_GIT_HASH "Retrieve current-githash" ON)
# ANDROID: atm(04/2020) lua-scripting leads to an runtime-error (not sure why)
option(GAME_ENABLE_LUA_SCRIPTING "Enable LUA-Scripting" OFF)

if (GAME_ENABLE_DEBUG_TOOLS)
    set (URHO3D_PACKAGING 0 CACHE BOOL "")
else()
    set (URHO3D_PACKAGING 0 CACHE BOOL "")
endif()

set (URHO3D_DEPLOYMENT_TARGET generic CACHE STRING "") # it is important to set this before running thorugh UrhoCommon

include (UrhoCommon)

# Define source files
set (TARGET_NAME ${PROJECT_NAME})

set(GIT_HASH "unknown")

if (GAME_RETRIEVE_GIT_HASH)
    ## see: https://coderefinery.github.io/cmake/07-exercise/

    # find Git and if available set GIT_HASH variable
    find_package(Git QUIET)
    if(GIT_FOUND)
      execute_process(
        COMMAND ${GIT_EXECUTABLE} --no-pager show -s --pretty=format:%h -n 1
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
        WORKING_DIRECTORY
            ${PROJECT_SOURCE_DIR}
        ERROR_QUIET
        )
    endif()
endif()

add_definitions(-fpermissive)


# create configure file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/project_options.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/Generated/project_options.h @ONLY)

# hacky: since I generate in source-tree and I'm sure the files are there I can use a dummy as output
#        this is only to let qtcreator to still show the gnenerated files
if (UNIX)
    add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/src/Components/Generated/dummy.h
        DEPENDS ${CMAKE_SOURCE_DIR}/src/Components/Components.xml
        COMMAND ${CMAKE_SOURCE_DIR}/src/Components/generate_components.sh
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src/Components
    )
endif()

if (WIN32)
    add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/src/Components/Generated/dummy.h
        DEPENDS ${CMAKE_SOURCE_DIR}/src/Components/Components.xml
        COMMAND ${CMAKE_SOURCE_DIR}/src/Components/generate_components.bat
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src/Components
    )
endif()


# get all source files
file( GLOB_RECURSE SOURCE_FILES FOLLOW_SYMLINKS ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp src/*.h src/*.xml)

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src/Generated)

# include addons
include("cmake/Addons.cmake")

# Setup target with resource copying
setup_main_executable ()
