cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME ClientServer)

project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "ClientServer Solution"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(./Global)
add_subdirectory(./Server)
add_subdirectory(./Client)