/**
 * @File    :   src/utility/include/base/singleton.h
 * @Time    :   2026/04/17 15:27:31
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :   构建通用的单例模式模板
 */

#pragma once

namespace sky::utility {

/**
 * @brief 单例模板，基类需要自己实现删除拷贝构造函数和赋值构造函数
 * @tparam T 基类
 *
 * @details 使用时需要在基类中声明友元：friend class Singleton<ClassName>;
 */
template <typename T>
class Singleton {
public:
  static T &instance() {
    static T s_instance;
    return s_instance;
  }
};

}  // namespace sky::utility
