cmake_minimum_required(VERSION 3.31)

project(GraphicsTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.c")

add_executable(out ${SOURCES}) #add WIN32 to create the windows application w/out console


include_directories("${CMAKE_SOURCE_DIR}/include/")


target_link_libraries(out "${CMAKE_SOURCE_DIR}/statLib/libglfw3.a")
