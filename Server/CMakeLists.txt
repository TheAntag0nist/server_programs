cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME Server)
# Set project
project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "Server - Network Server"
)
# Add compiler options
add_compile_options(-lpthread)
# Set include directories
include_directories(./inc)
include_directories(../Global/inc)
# Set source files
set(SOURCE_FILES
    ./src/server.cpp
    ./src/core.cpp
)
# Add library
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} GlobalCore)