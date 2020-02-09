#pragma once

#include "data_structure/tree_node.hpp"

namespace akarithm
{

template <typename ValueTy>
bool isMirror(const TreeNode<ValueTy> *lhs, const TreeNode<ValueTy> *rhs)
{
    if (lhs == nullptr && rhs == nullptr)
        return true;
    if (lhs == nullptr || rhs == nullptr)
        return false;
    return lhs->val == rhs->val &&
           isMirror(lhs->right, rhs->left) &&
           isMirror(lhs->left, rhs->right);
}

template <typename ValueTy>
bool isSymmetric(const TreeNode<ValueTy> *root)
{
    return isMirror(root, root);
}

} // namespace akarithm
