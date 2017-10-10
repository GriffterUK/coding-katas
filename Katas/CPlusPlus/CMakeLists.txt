cmake_minimum_required (VERSION 3.1)
project (CodingKatas)

enable_testing()

set(CMAKE_CXX_STANDARD 11)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-missing-braces -std=c++11")
endif()


set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(google-test)

if(WIN32)
    add_definitions(-DWINDOWS)
endif()

add_subdirectory(src)
add_subdirectory(test)

