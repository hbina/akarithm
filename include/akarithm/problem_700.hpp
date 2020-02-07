#pragma once

#include "data_structure/tree_node.hpp"

#include <functional>

namespace akarithm
{

template <
    typename T,
    typename EqualFunction = std::equal_to<>,
    typename SearchFunction = std::less<>>
static constexpr auto
searchBST_Generalized(
    const TreeNode<T> *root,
    const T &val,
    const EqualFunction &equal = EqualFunction(),
    const SearchFunction &search = SearchFunction())
    -> const TreeNode<T> *
{
    if (!root)
        return nullptr;
    else if (equal(root->val, val))
        return root;
    else if (search(root->val, val))
        return searchBST_Generalized(root->right, val, equal, search);
    else
        return searchBST_Generalized(root->left, val, equal, search);
}

template <typename T>
static constexpr auto
searchBST(
    const TreeNode<T> *root,
    const T &val)
    -> const TreeNode<T> *
{
    return searchBST_Generalized(root, val);
}

} // namespace akarithm
