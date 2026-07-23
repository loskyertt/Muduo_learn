/**
 * @File    :   src/mymoduo/impl/inet_address.cpp
 * @Time    :   2026/7/23 23:32
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :
 */

#include "mymuduo/inet_address.h"

#include <cstring>
#include <strings.h>
#include <arpa/inet.h>

using namespace sky::mymuduo;

INetAddress::INetAddress(uint16_t port, std::string ip) {
  bzero(&m_addr, sizeof(m_addr));  // 清零
  m_addr.sin_family      = AF_INET;
  m_addr.sin_port        = htons(port);
  m_addr.sin_addr.s_addr = inet_addr(ip.c_str());
}

INetAddress::INetAddress(const sockaddr_in& addr) : m_addr(addr) {}

std::string INetAddress::to_ip() const {
  char buf[64] = {0};
  ::inet_ntop(AF_INET, &m_addr.sin_addr, buf, sizeof(buf));

  return buf;
}

std::string INetAddress::to_ip_port() const {
  // ip:port
  char buf[64] = {0};
  ::inet_ntop(AF_INET, &m_addr.sin_addr, buf, sizeof(buf));

  std::size_t end = strlen(buf);
  uint16_t port   = ntohs(m_addr.sin_port);
  sprintf(buf + end, ":%u", port);
  return buf;
}

uint16_t INetAddress::to_port() const {
  return ntohs(m_addr.sin_port);
}