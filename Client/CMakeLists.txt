cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME Client)
# Set project
project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "Client - Network Client"
)
# Add compile definitions
add_compile_definitions(CLIENT_CONFIG)
# Set include directories
include_directories(./inc)
include_directories(../Global/inc)
# Set source files
set(SOURCE_FILES
    ./src/client.cpp
    ./src/core.cpp
)
# Add library
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} GlobalCore)