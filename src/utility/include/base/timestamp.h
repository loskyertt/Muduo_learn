/**
 * @File    :   src/utility/include/base/timestamp.h
 * @Time    :   2026/7/23 21:57
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :
 */

#pragma once

#include <string>

namespace sky::utility {
class timestamp {
public:
  timestamp();
  explicit timestamp(int64_t microseconds_epoch);

  static timestamp now();

  std::string to_string() const;

private:
  int64_t m_microseconds_epoch = 0;
};

}  // namespace sky::utility
