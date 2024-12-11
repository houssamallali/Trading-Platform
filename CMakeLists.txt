cmake_minimum_required(VERSION 3.10)
# Use vcpkg as a package manager
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
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

# Add spdlog support (from vcpkg)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(TradingPlatform PRIVATE spdlog::spdlog)

