#pragma once

#include "data_structure/tree_node.hpp"

#include <functional>

namespace aka {

template<typename ValueTy,
         typename EqualFunction,
         typename SearchFunction = std::less<>>
static constexpr auto
bst_search(const aka::TreeNode<ValueTy>* root,
           const EqualFunction& equal,
           const SearchFunction& search) -> const aka::TreeNode<ValueTy>*
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

} // namespace aka
