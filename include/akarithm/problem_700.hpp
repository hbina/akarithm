#pragma once

#include "data_structure/tree_node.hpp"

namespace akarithm
{

template <typename T>
static constexpr auto
searchBST(
    const TreeNode<T> *root,
    const T &val)
    -> const TreeNode<T> *
{
    if (!root)
        return nullptr;
    else if (root->val == val)
        return root;
    else if (root->val < val && root->right)
        return searchBST(root->right, val);
    else if (root->val > val && root->left)
        return searchBST(root->left, val);
    else
        return nullptr;
}

} // namespace akarithm
