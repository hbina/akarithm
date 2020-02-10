#pragma once

#include <iostream>

namespace akarithm
{

template <typename ValueTy = int>
struct TreeNode
{
  using value_type = ValueTy;
  ValueTy val;
  TreeNode<ValueTy> *left;
  TreeNode<ValueTy> *right;

  constexpr TreeNode() = delete;

  constexpr TreeNode(const ValueTy &x)
      : val(x),
        left(nullptr),
        right(nullptr) {}

  constexpr TreeNode(const ValueTy &val,
                     TreeNode *left,
                     TreeNode *right)
      : val(val),
        left(left),
        right(right) {}

  ~TreeNode()
  {
    if (left)
      delete left;
    if (right)
      delete right;
  }

  friend std::ostream &operator<<(std::ostream &os, const TreeNode<ValueTy> &rhs)
  {
    os << " " << rhs.val;
    if (rhs.left)
    {
      os << " " << *rhs.left;
    }
    if (rhs.right)
    {
      os << " " << *rhs.right;
    }
    return os;
  }

  constexpr friend bool operator==(const TreeNode<ValueTy> &lhs, const TreeNode<ValueTy> &rhs)
  {
    bool value_equal = (lhs.val == rhs.val);
    bool left_equal = false;
    if (lhs.left && rhs.left)
    {
      left_equal = (*lhs.left == *rhs.left);
    }
    else if (!lhs.left && !rhs.left)
    {
      left_equal = true;
    }
    bool right_equal = false;
    if (lhs.right && rhs.right)
    {
      right_equal = (*lhs.right == *rhs.right);
    }
    else if (!lhs.right && !rhs.right)
    {
      right_equal = true;
    }
    return value_equal && left_equal && right_equal;
  }
};

} // namespace akarithm
