
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

file(GLOB_RECURSE CODINGKATASOURCES *.cpp)
file(GLOB_RECURSE CODINGKATAHEADERS *.h)

list(REMOVE_ITEM CODINGKATASOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

include_directories("../" ${CMAKE_CURRENT_BINARY_DIR})

add_library(libcodingkatas STATIC ${CODINGKATASOURCES} ${CODINGKATAHEADERS})

add_executable(codingkatas main.cpp)
target_link_libraries(codingkatas -Wl,--whole-archive libcodingkatas -Wl,--no-whole-archive)
add_dependencies(codingkatas libcodingkatas)
