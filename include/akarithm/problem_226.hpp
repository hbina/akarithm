#pragma once

#include "data_structure/tree_node.hpp"

#include <memory>

namespace akarithm
{

template <typename ValueTy>
static constexpr TreeNode<ValueTy> *invertTree(TreeNode<ValueTy> *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        TreeNode<ValueTy> *tmp_left = root->left;
        TreeNode<ValueTy> *tmp_right = root->right;
        root->left = invertTree(tmp_right);
        root->right = invertTree(tmp_left);
        return root;
    }
}

} // namespace akarithm
