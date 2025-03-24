cmake_minimum_required(VERSION 3.31)

project(GraphicsTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.c")

add_executable(out ${SOURCES})


include_directories("${CMAKE_SOURCE_DIR}/include/") #I think this is the only one needed for all include


target_link_libraries(out
    "-framework CoreFoundation"
    "-framework IOKit"
    "-framework Cocoa"
)
target_link_libraries(out "${CMAKE_SOURCE_DIR}/statLib/libglfw3.a")