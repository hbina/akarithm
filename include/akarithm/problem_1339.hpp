#pragma once

#include "data_structure/tree_node.hpp"
#include "data_structure/postorder_iterator.hpp"
#include "data_structure/preorder_iterator.hpp"

#include <map>

namespace akarithm
{

template <
    typename IntTy>
static constexpr auto
maxProduct(
    const TreeNode<IntTy> *root)
    -> IntTy
{
    using MapTy =
        typename std::map<const TreeNode<IntTy> *, IntTy>;

    // Calculate the sum of every nodes
    constexpr auto tree_accumulator =
        [](const TreeNode<IntTy> *root)
        -> MapTy {
        MapTy acc = {};
        akarithm::PostorderIterator iter = akarithm::PostorderIterator(root);
        while (iter.hasNext())
        {
            const TreeNode<IntTy> *node = iter.next();
            IntTy left = {};
            IntTy right = {};
            if (node->left)
            {
                left = acc[node->left];
            }
            if (node->right)
            {
                left = acc[node->right];
            }
            acc[node] = node->val + left + right;
        }
        return std::move(acc);
    };

    MapTy sum = tree_accumulator(root);
    akarithm::PreorderIterator iter = akarithm::PreorderIterator(root);
    while (iter.hasNext())
    {
        const TreeNode<IntTy> *node = iter.next();
    }
    return 0;
}

} // namespace akarithm
