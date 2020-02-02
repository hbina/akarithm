#pragma once

#include "data_structure/tree_node.hpp"
#include "data_structure/preorder_iterator.hpp"

namespace akarithm
{

auto tree_accumulator =
    [](const TreeNode<int> *root,
       int acc)
    -> int {
    akarithm::PreorderIterator iter = akarithm::PreorderIterator(root);
    while (iter.hasNext())
    {
        acc += iter.next()->val;
    }
    return acc;
};

int maxProduct(const TreeNode<int> *root)
{
    int sum = tree_accumulator(root, 0);
    akarithm::PreorderIterator iter = akarithm::PreorderIterator(root);
    while (iter.hasNext())
    {
    }
    return 0;
}

} // namespace akarithm
