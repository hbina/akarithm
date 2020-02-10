#pragma once

#include "data_structure/tree_node.hpp"

#include <memory>

namespace akarithm
{

template <typename ValueTy>
static constexpr akarithm::TreeNode<ValueTy> *invertTree(TreeNode<ValueTy> *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else
    {
        akarithm::TreeNode<ValueTy> *tmp_left = root->left;
        akarithm::TreeNode<ValueTy> *tmp_right = root->right;
        root->left = invertTree(tmp_right);
        root->right = invertTree(tmp_left);
        return root;
    }
}

} // namespace akarithm
