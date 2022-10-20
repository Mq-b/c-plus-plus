cmake_minimum_required (VERSION 3.8)

project ("array")

# 将源代码添加到此项目的可执行文件。
add_executable (array  "array.hpp" "test.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET array PROPERTY CXX_STANDARD 20)
endif()
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


set(INC_DIR C:/str/vcpkg/packages/fmt_x64-windows/include)

set(LINK_DIR C:/str/vcpkg/packages/fmt_x64-windows/lib)

#引入头文件
include_directories(${INC_DIR})

#引入库文件
link_directories(${LINK_DIR})

target_link_libraries(array "C:/str/vcpkg/packages/fmt_x64-windows/lib/fmt.lib")