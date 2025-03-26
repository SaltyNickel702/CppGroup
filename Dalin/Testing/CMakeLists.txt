cmake_minimum_required(VERSION 3.31)

project(GraphicsTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SRC_DIR "${CMAKE_SOURCE_DIR}/Libraries")
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.c")

add_executable(out ${SOURCES})


include_directories("${CMAKE_SOURCE_DIR}/Libraries/include/") #I think this is the only one needed for all include


target_link_libraries(out
    "-framework CoreFoundation"
    "-framework IOKit"
    "-framework Cocoa"
)
target_link_libraries(out "${CMAKE_SOURCE_DIR}/Libraries/lib/libglfw3.a")