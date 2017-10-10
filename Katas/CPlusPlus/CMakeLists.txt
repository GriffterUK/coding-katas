cmake_minimum_required (VERSION 3.1)
project (CodingKatas)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(google-test)

if(WIN32)
    add_definitions(-DWINDOWS)
endif()

add_subdirectory(src)
add_subdirectory(test)

