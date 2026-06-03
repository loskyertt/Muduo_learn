cmake_minimum_required(VERSION 3.20.0)

# 导出编译命令（用于 clangd）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Moduo_learn VERSION 0.0.1 LANGUAGES C CXX)

# 设置标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

# 开启 gtest_discover_tests 注册测试用例依赖
enable_testing()

# 脚本
# include(cmake/check_arch.cmake)
include(cmake/set_muduo.cmake)
include(cmake/set_g3log.cmake)

# 添加第三方库
find_package(GTest REQUIRED)
find_package(Boost REQUIRED CONFIG)

add_subdirectory(3rdparty/muduo-2.0.2)
add_subdirectory(3rdparty/g3log-2.6)

# 子模块
add_subdirectory(src/utility)
# add_subdirectory(tests)
add_subdirectory(examples)
