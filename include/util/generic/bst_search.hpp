#pragma once

#include "data_structure/tree_node.hpp"

#include <functional>

namespace util
{
namespace generic
{

template <
    typename T,
    typename EqualFunction,
    typename SearchFunction = std::less<>>
static constexpr auto
bst_search(
    const TreeNode<T> *root,
    const EqualFunction &equal,
    const SearchFunction &search)
    -> const TreeNode<T> *
{
    if (!root)
        return nullptr;
    else if (equal(root->val))
        return root;
    else if (search(root->val))
        return bst_search(root->right, equal, search);
    else
        return bst_search(root->left, equal, search);
}

} // namespace generic
} // namespace util
