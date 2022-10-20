cmake_minimum_required (VERSION 3.8)

project ("vector")

# 将源代码添加到此项目的可执行文件。
add_executable (array  "vector.hpp" "test.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET array PROPERTY CXX_STANDARD 20)
endif()
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)