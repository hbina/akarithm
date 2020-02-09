#pragma once

#include <string>
#include <iostream>

template <typename ValueTy = int>
struct ListNode
{
  ValueTy val;
  ListNode *next;

  constexpr ListNode(const ValueTy &x)
      : val(x),
        next(nullptr) {}
  constexpr ListNode(const ValueTy &x,
                     ListNode *next)
      : val(x),
        next(next) {}

  ~ListNode()
  {
    if (next)
      delete next;
  }

  template <typename T2>
  friend std::ostream &operator<<(std::ostream &os, const ListNode<T2> &rhs);
  template <typename T2>
  constexpr friend bool operator==(const ListNode<T2> &lhs, const ListNode<T2> &rhs);
};

template <typename ValueTy>
std::ostream &operator<<(std::ostream &os, const ListNode<ValueTy> &rhs)
{
  os << "ListNode val:" << rhs.val;
  return os;
}

template <typename ValueTy>
constexpr bool operator==(const ListNode<ValueTy> &lhs, const ListNode<ValueTy> &rhs)
{
  bool value_equal = (lhs.val == rhs.val);
  if (lhs.next && rhs.next)
  {
    return value_equal && (*lhs.next == *rhs.next);
  }
  else if (!lhs.next && !rhs.next)
  {
    return value_equal;
  }
  else
  {
    return false;
  }
}
