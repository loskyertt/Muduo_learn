/**
 * @File    :   src/mymoduo/include/mymuduo/inet_address.h
 * @Time    :   2026/7/23 23:32
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :    封装 socket 地址类型
 */

#pragma once

#include <string>
#include <netinet/in.h>

namespace sky::mymuduo {
class INetAddress {
public:
  explicit INetAddress(uint16_t port, std::string ip = "127.0.0.1");
  explicit INetAddress(const sockaddr_in& addr);

  std::string to_ip() const;
  std::string to_ip_port() const;
  uint16_t to_port() const;

  const sockaddr_in* get_sockaddr() const { return &m_addr; };

private:
  sockaddr_in m_addr;
};
}  // namespace sky::mymuduo
