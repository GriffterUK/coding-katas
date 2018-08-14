cmake_minimum_required(VERSION 2.8.11)
project(Checkout)

file(GLOB PROJECT_INCLUDES "include/*.h")
file(GLOB PROJECT_SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${PROJECT_INCLUDES} ${PROJECT_SOURCES})
