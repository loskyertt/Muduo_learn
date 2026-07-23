/**
 * @File    :   src/utility/impl/base/timestamp.cpp
 * @Time    :   2026/7/23 21:57
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :   获取系统当前时刻
 */

#include "base/timestamp.h"

#include <ctime>

using namespace sky::utility;

timestamp::timestamp() {}

timestamp::timestamp(int64_t microseconds_epoch) : m_microseconds_epoch(microseconds_epoch) {}

timestamp timestamp::now() {
  return timestamp(time(nullptr));
}

std::string timestamp::to_string() const {
  char buf[128] = {0};
  tm* tm_time      = localtime(&m_microseconds_epoch);
  snprintf(buf,
           sizeof(buf),
           "%4d/%02d/%02d %02d:%02d:%02d",
           tm_time->tm_year + 1900,
           tm_time->tm_mon + 1,
           tm_time->tm_mday,
           tm_time->tm_hour,
           tm_time->tm_min,
           tm_time->tm_sec);

  return buf;
}
