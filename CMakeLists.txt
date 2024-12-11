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

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/third_party)

# Add spdlog support (from vcpkg)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(TradingPlatform PRIVATE spdlog::spdlog)

# Add Google Test for unit testing
find_package(GTest CONFIG REQUIRED)
enable_testing()

# A# Add test executable
add_executable(UnitTests tests/test_trade.cpp src/trade.cpp)

# Link test executable with GTest and the necessary sources
target_link_libraries(UnitTests PRIVATE GTest::gtest GTest::gtest_main spdlog::spdlog)





