cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER "C:\\MINGW\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\MINGW\\bin\\g++.exe")

project(ZCode)

include_directories(
  ${PROJECT_SOURCE_DIR}/AST/headers
  ${PROJECT_SOURCE_DIR}/Checker/headers
  ${PROJECT_SOURCE_DIR}/Grammar
  ${PROJECT_SOURCE_DIR}/Grammar/atn
  ${PROJECT_SOURCE_DIR}/Grammar/dfa
  ${PROJECT_SOURCE_DIR}/Grammar/internal
  ${PROJECT_SOURCE_DIR}/Grammar/misc
  ${PROJECT_SOURCE_DIR}/Grammar/support
  ${PROJECT_SOURCE_DIR}/Grammar/tree
  ${PROJECT_SOURCE_DIR}/Grammar/tree/pattern
  ${PROJECT_SOURCE_DIR}/Grammar/tree/xpath
)

file(GLOB SOURCES
  "${PROJECT_SOURCE_DIR}/main.cpp"
  "${PROJECT_SOURCE_DIR}/AST/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/Checker/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/atn/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/dfa/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/internal/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/misc/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/support/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/tree/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/tree/pattern/*.cpp"
  "${PROJECT_SOURCE_DIR}/Grammar/tree/xpath/*.cpp"
)

add_executable(main ${SOURCES})
