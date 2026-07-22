/**
 * @File    :   examples/moduo_server.cpp
 * @Time    :   2026/05/10 21:18:17
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :   基于 muduo 网络库开发服务器程序
 */

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>

#include <functional>
#include <iostream>

class ChatServer {
public:
  ChatServer(muduo::net::EventLoop *loop,                 // 事件循环
             const muduo::net::InetAddress &listen_addr,  // IP + Port
             const std::string &name_arg                  // 服务器名称
             )
      : m_server(loop, listen_addr, name_arg) {
    m_server.setConnectionCallback([this](const muduo::net::TcpConnectionPtr &conn) { this->on_connection(conn); });

    m_server.setMessageCallback([this](const muduo::net::TcpConnectionPtr &conn,
                                       muduo::net::Buffer *buffer,
                                       muduo::Timestamp time) { this->on_message(conn, buffer, time); });

    // 设置服务端的线程数：1 IO 线程 + 3 worker 线程
    m_server.setThreadNum(4);
  }

  // 开启事件循环
  void start() { m_server.start(); }

private:
  // 专门处理用户的连接和断开
  void on_connection(const muduo::net::TcpConnectionPtr &conn) {
    if (conn->connected()) {
      std::cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << " state: online"
                << std::endl;
    } else {
      std::cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << " state: offline"
                << std::endl;
      conn->shutdown();
    }
  }

  // 专门处理用户的读写事件
  void on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp time) {
    std::string buf = buffer->retrieveAllAsString();
    std::cout << "recv data: " << buf << " time: " << time.toString() << std::endl;
    conn->send(buf);
  }

private:
  muduo::net::TcpServer m_server;           // 创建 tcp_server 对象
  muduo::net::EventLoop *m_loop = nullptr;  // 创建 EventLoop 事件循环的指针
};

int main() {
  muduo::net::EventLoop loop;
  muduo::net::InetAddress addr("127.0.0.1", 6000);
  ChatServer server(&loop, addr, "ChatServer");
  server.start();
  loop.loop();  // epoll_wait 以阻塞方式等待新用户连接或者已连接用户的读写事件等
}
