cmake_minimum_required(VERSION 3.31)

project(GraphicsTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.c")

add_executable(out ${SOURCES})


include_directories("./include/") #I think this is the only one needed for all include

target_link_libraries(out "./statLib/libglfw3.a")