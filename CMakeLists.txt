cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

project(libgetoptpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(src)

install(DIRECTORY include
        DESTINATION .
        COMPONENT devel
        FILES_MATCHING PATTERN *)
