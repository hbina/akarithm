#pragma once

#include "data_structure/tree_node.hpp"

#include <vector>
#include <stack>

namespace akarithm
{

template <typename ValueTy>
static constexpr std::vector<std::vector<ValueTy>>
levelOrderBottom(const TreeNode<ValueTy> *root)
{
    std::vector<std::vector<ValueTy>> result = {};
    std::vector<const TreeNode<ValueTy> *> layers = {root};
    while (!layers.empty())
    {
        std::vector<ValueTy> tmp;
        std::vector<const TreeNode<ValueTy> *> next_layers;
        for (const TreeNode<ValueTy> *x : layers)
        {
            tmp.push_back(x->val);
            if (x->left)
                next_layers.push_back(x->left);
            if (x->right)
                next_layers.push_back(x->right);
        }
        result.push_back(tmp);
        layers = next_layers;
    }
    return result;
}

} // namespace akarithm
