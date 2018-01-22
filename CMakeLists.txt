cmake_minimum_required(VERSION 3.10.1)


project(licp C)

set(SOURCE_NAME   "licp_source")
set(TEST_NAME     "licp_test")
set(PATH_BUILD    "${PROJECT_SOURCE_DIR}/build")
set(PATH_INCLUDE  "${PROJECT_SOURCE_DIR}/include")
set(PATH_SOURCE   "${PROJECT_SOURCE_DIR}/src")
set(PATH_TEST     "${PROJECT_SOURCE_DIR}/test")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

file(GLOB SOURCES_LIB "${PATH_SOURCE}/*.c")
file(GLOB SOURCES_TEST "${PATH_TEST}/*.c")
file(GLOB HEADER_FILES "${PATH_INCLUDE}/*.h")

include_directories(${PATH_INCLUDE})

add_library(${SOURCE_NAME} "${SOURCES_LIB}")
target_link_libraries(${SOURCE_NAME} readline m)

enable_testing()

set(tests
  "vector_test"
  "concat_test"
  "parser_test"
  "tree_test"
  )

list(LENGTH tests temp_len)
math(EXPR test_len "${temp_len} - 1")

foreach(index RANGE ${test_len})
  list(GET tests ${index} test)
  add_executable(${test} ${PATH_TEST}/${test}.c)
  target_link_libraries(${test} ${SOURCE_NAME})
  add_test(${test} ${test})
endforeach()


add_executable(${PROJECT_NAME} ${PATH_SOURCE}/main.c)
target_link_libraries(${PROJECT_NAME} ${SOURCE_NAME} readline m)
