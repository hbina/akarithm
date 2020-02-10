#pragma once

#include "data_structure/tree_node.hpp"

namespace akarithm
{

template <typename ValueTy>
std::size_t maxDepth(const akarithm::TreeNode<ValueTy> *root)
{
    if (!root)
    {
        return 0;
    }
    std::size_t left = 1 + maxDepth(root->left);
    std::size_t right = 1 + maxDepth(root->right);
    return left > right ? left : right;
}

} // namespace akarithm