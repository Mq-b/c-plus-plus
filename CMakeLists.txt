project ("Test1")#项目名称

set(CMAKE_CXX_STANDARD 23)

#设置exe的输出目录${PROJECT_SOURCE_DIR}就是当前顶级目录，然后创建bin文件夹里生成exe
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


#set(INC_DIR C:/str/vcpkg/packages/fmt_x64-windows/include)

#set(LINK_DIR C:/str/vcpkg/packages/fmt_x64-windows/lib)

#引入头文件
#include_directories(${INC_DIR})

#引入库文件
#link_directories(${LINK_DIR})

# 将源代码添加到此项目的可执行文件,下面的文件有多少决定项目生成会运行多少个源文件
add_executable (Test1 "src/c++练习.ixx")

# 告诉链接器共享库文件的位置，这样链接器就相当于知道了curl的实现
#target_link_libraries(Test1 "C:/str/vcpkg/packages/fmt_x64-windows/lib/fmt.lib")

#上面注释的是根据本地目录引入三方库fmt的方式，其实直接像下面这样直接使用vcpkg的也可以(但是必须都设置了环境变量)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(Test1 fmt::fmt-header-only)

find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(Test1 jsoncpp_lib)

find_package(xlnt CONFIG REQUIRED)
target_link_libraries(Test1 xlnt::xlnt)

#find_package(GTest CONFIG REQUIRED)
#target_link_libraries(Test1 PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

find_package(tinyxml CONFIG REQUIRED)
target_link_libraries(Test1 PRIVATE unofficial-tinyxml::unofficial-tinyxml)