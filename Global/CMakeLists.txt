cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME GlobalCore)
# Set project
project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    DESCRIPTION "GlobalCore - Core with Configs, Network, Log"
)
# Set include directories
include_directories(./inc)
# Set source files
set(SOURCE_FILES
    ./src/Config/client_config.cpp
    ./src/Config/log_config.cpp
    ./src/Config/srv_config.cpp
    ./src/Config/app_config.cpp
    ./src/Config/config.cpp

    ./src/Network/net_helper.cpp
    ./src/Package/package.cpp
    ./src/Log/logger.cpp
)
# Add library
add_library(${PROJECT_NAME} ${SOURCE_FILES})