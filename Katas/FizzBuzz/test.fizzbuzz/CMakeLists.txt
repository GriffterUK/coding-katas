cmake_minimum_required(VERSION 2.8.11)
project(Test.FizzBuzz)

aux_source_directory(src PROJECT_SOURCE)
file(GLOB PROJECT_INCLUDES "include/*.h")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE} ${PROJECT_INCLUDES})

add_dependencies(${PROJECT_NAME} gmock)

target_link_libraries(${PROJECT_NAME} FizzBuzz gmock gmock_main)
