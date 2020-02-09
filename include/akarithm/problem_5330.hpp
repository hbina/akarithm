#pragma once

#include "data_structure/tree_node.hpp"
#include "data_structure/preorder_iterator.hpp"

namespace akarithm
{

template <typename IntTy = int>
static constexpr auto
maxProduct(
    const TreeNode<IntTy> *root)
    -> IntTy
{
    constexpr auto tree_accumulator =
        [](const TreeNode<IntTy> *root,
           IntTy acc)
        -> IntTy {
        akarithm::PreorderIterator iter = akarithm::PreorderIterator(root);
        while (iter.hasNext())
        {
            acc += iter.next()->val;
        }
        return acc;
    };

    IntTy sum = tree_accumulator(root, 0);
    akarithm::PreorderIterator iter = akarithm::PreorderIterator(root);
    while (iter.hasNext())
    {
    }
    return 0;
}

} // namespace akarithm
