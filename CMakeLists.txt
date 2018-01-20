cmake_minimum_required(VERSION 3.10.1)

project(liCp C)

file(GLOB SOURCES "src/*.c")

file(GLOB HEADER_FILES "src/*.h")

include_directories(include)

add_executable(liCp ${SOURCES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

target_link_libraries(liCp readline)
