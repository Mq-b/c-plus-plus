cmake_minimum_required (VERSION 3.8)

project ("list")

# 将源代码添加到此项目的可执行文件。
add_executable (list "list.hpp" "test.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET list PROPERTY CXX_STANDARD 20)
endif()
