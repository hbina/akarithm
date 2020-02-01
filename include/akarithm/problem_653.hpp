#pragma once

#include "data_structure/preorder_iterator.hpp"
#include "data_structure/postorder_iterator.hpp"
#include "data_structure/tree_node.hpp"

namespace akarithm
{

template <typename T>
static constexpr auto
findTarget(const TreeNode<T> *root, int k)
    -> bool
{
    akarithm::PreorderIterator pre_order = akarithm::PreorderIterator(root);
    akarithm::PostorderIterator post_order = akarithm::PostorderIterator(root);
    while (pre_order.hasNext() && post_order.hasNext())
    {
        if (pre_order.next()->val + post_order.next()->val == k)
        {
            return true;
        }
    }
    return false;
}

} // namespace akarithm
