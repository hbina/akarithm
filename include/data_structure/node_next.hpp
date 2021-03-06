#pragma once

#include <iostream>

namespace aka {

template<typename ValueTy = int>
class NodeNext
{
public:
  ValueTy val;
  NodeNext* left;
  NodeNext* right;
  NodeNext* next;

  constexpr NodeNext() = delete;

  constexpr NodeNext(const ValueTy& val)
    : val(val)
    , left(nullptr)
    , right(nullptr)
    , next(nullptr)
  {}

  constexpr NodeNext(const ValueTy& val,
                     NodeNext<ValueTy>* left,
                     NodeNext<ValueTy>* right,
                     NodeNext<ValueTy>* next)
    : val(val)
    , left(left)
    , right(right)
    , next(next)
  {}

  ~NodeNext()
  {
    delete left;
    delete right;
  }

  friend std::ostream& operator<<(std::ostream& os,
                                  const NodeNext<ValueTy>& rhs)
  {
    os << rhs.val << " ";
    if (rhs.left)
      os << *rhs.left << " ";
    else
      os << "null ";
    if (rhs.right)
      os << *rhs.right << " ";
    else
      os << "null ";
    if (rhs.next)
      os << *rhs.next << " ";
    else
      os << "null ";
    return os;
  };

  constexpr friend bool operator==(const NodeNext<ValueTy>& lhs,
                                   const NodeNext<ValueTy>& rhs)
  {
    bool value_equal = lhs.val == rhs.val;
    bool left_equal = false;
    if (lhs.left && rhs.left) {
      left_equal = (*lhs.left == *rhs.left);
    } else if (!lhs.left && !rhs.left) {
      left_equal = true;
    }

    bool right_equal = false;
    if (lhs.right && rhs.right) {
      right_equal = (*lhs.right == *rhs.right);
    } else if (!lhs.right && !rhs.right) {
      right_equal = true;
    }

    bool next_equal = false;
    if (lhs.next && rhs.next) {
      next_equal = (*lhs.next == *rhs.next);
    } else if (!lhs.next && !rhs.next) {
      next_equal = true;
    }

    return value_equal && left_equal && right_equal && next_equal;
  };
};

} // namespace akarithm
