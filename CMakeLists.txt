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

# 添加第三方库
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/3rdparty/g3log-2.6")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/3rdparty/muduo-2.0.2")

find_package(GTest REQUIRED CONFIG)
find_package(Boost REQUIRED CONFIG)
find_package(g3log REQUIRED CONFIG)
find_package(muduo REQUIRED CONFIG)

include(cmake/find_target.cmake)

# 子模块
add_subdirectory(src/utility)
add_subdirectory(examples)
