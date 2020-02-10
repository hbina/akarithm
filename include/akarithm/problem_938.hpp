#pragma once

#include "data_structure/tree_node.hpp"

namespace akarithm
{

template <typename ValueTy>
static constexpr int rangeSumBST_recursion(
    const akarithm::TreeNode<ValueTy> *root, const ValueTy &L, const ValueTy &R)
{
    if (root == nullptr)
    {
        return 0;
    }
    else if (root->val < L)
    {
        return rangeSumBST_recursion(root->right, L, R);
    }
    else if (root->val > R)
    {
        return rangeSumBST_recursion(root->left, L, R);
    }
    else
    {
        return root->val + rangeSumBST_recursion(root->left, L, R) + rangeSumBST_recursion(root->right, L, R);
    }
}

} // namespace akarithm
