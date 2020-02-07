#pragma once

#include "data_structure/tree_node.hpp"

#include "util/generic/bst_search.hpp"

namespace akarithm
{

template <typename T>
static constexpr auto
searchBST(
    const TreeNode<T> *root,
    const T &val)
    -> const TreeNode<T> *
{
    return util::generic::bst_search(
        root,
        [&](const T &node)
            -> bool {
            return node == val;
        },
        [&](const T &node)
            -> bool {
            return node < val;
        });
}

} // namespace akarithm
