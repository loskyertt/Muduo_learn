/**
 * @File    :   src/mymoduo/tests/test_inet_address
 * @Time    :   2026/7/24 00:38
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :
 */

#include "mymuduo/inet_address.h"

#include <iostream>

using namespace sky::mymuduo;

int main(int argc, char* argv[]) {
  INetAddress addr(8080);
  std::cout << addr.to_ip_port() << std::endl;
}
