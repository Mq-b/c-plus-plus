# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)#需要最低的cmake版本

project ("Test1")#项目名称
message("Hello Word")#cmake的输出，到输出窗口

# 将源代码添加到此项目的可执行文件,下面的文件有多少决定项目生成会运行多少个源文件
add_executable (Test1 "src/c++练习.ixx"   "src/424父类对象使用子类初始化.cpp")
#include_directories(CMakeProject01)

if (CMAKE_VERSION VERSION_GREATER 3.12)#如果cmake的版本大于3.12 也就是cmake自己支持让编译器启用 c++20，cmake低于3.12是无法支持c++20
  set_property(TARGET Test1 PROPERTY CXX_STANDARD 20)#设置Hello可执行文件c++版本为20
  message("20")#打印
endif()

#设置exe的输出目录${PROJECT_SOURCE_DIR}就是当前顶级目录，然后创建bin文件夹里生成exe
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#find_package(OpenCV REQUIRED)

#include_directories(${OPENCV_INCLUDE_DIRS})    
#target_link_libraries(Test1 ${OpenCV_LIBS})

# TODO: 如有需要，请添加测试并安装目标。
