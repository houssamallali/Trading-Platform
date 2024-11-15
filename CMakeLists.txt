cmake_minimum_required(VERSION 3.10)
project(TradingPlatform)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source files
set(SOURCES
    src/main.cpp
    src/trade.cpp
)

# Add executable
add_executable(TradingPlatform ${SOURCES})

# Include nlohmann/json library
include_directories(third_party/)