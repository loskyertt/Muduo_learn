/**
 * @File    :   src/mymoduo/tests/test_timestamp
 * @Time    :   2026/7/23 22:37
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :
 */

#include "../include/base/timestamp.h"

#include <iostream>

using namespace sky::utility;

int main(int argc, char* argv[]) {
  std::cout << timestamp::now().to_string() << std::endl;
}
