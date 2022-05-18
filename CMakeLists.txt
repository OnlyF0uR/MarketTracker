cmake_minimum_required(VERSION 3.10)

project(MarketTracker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MarketTracker src/tracker.cpp "src/shell.cpp" "src/commands.cpp")