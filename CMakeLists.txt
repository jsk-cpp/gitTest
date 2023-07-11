cmake_minimum_required(VERSION 3.14)
project(gtest_gmock)

set(CMAKE_CXX_STANDARD 14)
set(GOOGLETEST_VERSION 1.13.0)

# 引入头文件
include_directories(./include DIR_INC)

# 指定外部引用文件的搜索路径
link_directories(./lib)

# 需要编译的源文件
add_executable(gtest_gmock src/main.cpp src/User.h src/MockUser.h)

# 链接外部库，在链接阶段引入静态库文件
target_link_libraries(gtest_gmock libgtest.a libgtest_main.a libgmock.a libgmock_main.a)