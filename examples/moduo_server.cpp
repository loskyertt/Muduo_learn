/**
 * @File    :   examples/moduo_server.cpp
 * @Time    :   2026/05/10 21:18:17
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :   基于 muduo 网络库开发服务器程序
 */

#include "muduo/net/TcpServer.h"
#include "muduo/net/Callbacks.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/InetAddress.h"

#include <functional>

class ChatServer {
 private:
  muduo::net::TcpServer m_server;           // 创建 tcp_server 对象
  muduo::net::EventLoop *m_loop = nullptr;  // 创建 EventLoop 事件循环的指针

 public:
  ChatServer(muduo::net::EventLoop *loop,         // 事件循环
      const muduo::net::InetAddress &listenAddr,  // IP + Port
      const std::string &nameArg                  // 服务器名称
      )
      : m_server(loop, listenAddr, nameArg) {
    m_server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, std::placeholders::_1));
  }

 private:
  // 专门处理用户的连接和断开
  void onConnection(const muduo::net::TcpConnectionPtr &) {}
};

int main() {}
