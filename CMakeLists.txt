cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Werror -Wshadow -Wnon-virtual-dtor
                    -Wold-style-cast -Wcast-align -Wunused
                    -Woverloaded-virtual -Wnull-dereference -Wdouble-promotion
                    -fno-rtti -fno-exceptions)

project(libgetoptpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(src)

install(DIRECTORY include
        DESTINATION .
        COMPONENT devel
        FILES_MATCHING PATTERN *)
