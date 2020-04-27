#pragma once

#include <iostream>
#include <string>

namespace akarithm {

template<typename ValueTy = int>
struct ListNode
{
  ValueTy val;
  ListNode* next;

  constexpr ListNode(const ValueTy& x)
    : val(x)
    , next(nullptr)
  {}
  constexpr ListNode(const ValueTy& x, ListNode* next)
    : val(x)
    , next(next)
  {}

  ~ListNode()
  {
    if (next)
      delete next;
  }

  constexpr friend std::ostream& operator<<(std::ostream& os,
                                            const ListNode<ValueTy>& rhs)
  {
    os << "ListNode val:" << rhs.val;
    return os;
  }

  constexpr friend bool operator==(const akarithm::ListNode<ValueTy>& lhs,
                                   const akarithm::ListNode<ValueTy>& rhs)
  {
    bool value_equal = (lhs.val == rhs.val);
    if (lhs.next && rhs.next) {
      return value_equal && (*lhs.next == *rhs.next);
    } else if (!lhs.next && !rhs.next) {
      return value_equal;
    } else {
      return false;
    }
  }
};

} // namespace akarithm
