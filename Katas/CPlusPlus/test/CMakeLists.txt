
include_directories(${CMAKE_SOURCE_DIR}/google-test/googletest/include
                    ${CMAKE_SOURCE_DIR}/google-test/googlemock/include
                    ${CMAKE_BINARY_DIR}/src)

file(GLOB_RECURSE TESTCODINGKATASOURCES *.cpp)
file(GLOB_RECURSE TESTCODINGKATAHEADERS *.h)

add_executable(testcodingkatas ${TESTCODINGKATASOURCES} ${TESTCODINGKATAHEADERS})
add_dependencies(testcodingkatas gtest gmock)
target_link_libraries(testcodingkatas gtest gmock libcodingkatas)

