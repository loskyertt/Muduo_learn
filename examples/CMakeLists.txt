# examples/CMakeLists.txt

add_executable(moduo_server moduo_server.cpp)

target_link_libraries(moduo_server
  PRIVATE
    muduo::net
    muduo::base
    pthread        # muduo 依赖线程库
    rt             # 部分 Linux 系统需要链接实时库
    Boost::headers
)
