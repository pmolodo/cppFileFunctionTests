cmake_minimum_required(VERSION 3.4.1 FATAL_ERROR)
project(cppFileFunctionTests)

add_executable(findFirstFile findFirstFileMain.cpp)
add_executable(pathIsDirectory pathIsDirectory.cpp)
target_link_libraries(pathIsDirectory shlwapi)