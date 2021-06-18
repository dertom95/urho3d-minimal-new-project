include(cmake/CPM.cmake)

CPMAddPackage(
    NAME CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    VERSION 1.9.1
    DOWNLOAD_ONLY YES
)

if (CLI11_ADDED)
    add_library(CLI11 INTERFACE)
    target_include_directories(CLI11 SYSTEM INTERFACE ${CLI11_SOURCE_DIR}/include)
endif()
