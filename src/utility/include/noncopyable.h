/**
 * @File    :   src/utility/include/noncopyable.h
 * @Time    :   2026/7/22 23:31
 * @Author  :   loskyertt
 * @Github  :   https://github.com/loskyertt
 * @Desc    :   禁止拷贝和赋值的基类
 */

#pragma once

/**
 * @brief NonCopyable 被继承后，派生类对象可以正常的构造和析构，但是派生类无法进行拷贝构造和赋值操作
 */
class NonCopyable {
public:
  NonCopyable(const NonCopyable &)            = delete;
  NonCopyable &operator=(const NonCopyable &) = delete;

protected:
  NonCopyable()  = default;
  ~NonCopyable() = default;
};