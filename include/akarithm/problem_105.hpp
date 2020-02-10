#pragma once

#include "data_structure/tree_node.hpp"

#include <vector>
#include <algorithm>
#include <type_traits>
#include <iterator>
#include <memory>

template <typename IterTy,
          typename ValueTy,
          typename = std::enable_if_t<
              std::is_same_v<
                  typename std::iterator_traits<IterTy>::value_type,
                  ValueTy>>>
static constexpr std::size_t
get_dividing_index(
    const IterTy &preorder_begin,
    const IterTy &preorder_end,
    const ValueTy &inorder_end)
{
    return std::distance(
        preorder_begin,
        std::find(
            preorder_begin,
            preorder_end,
            inorder_end));
}

template <typename IterTy>
static constexpr akarithm::TreeNode<
    typename std::iterator_traits<IterTy>::value_type> *
buildTreeTemplatePreIn(
    const IterTy &preorder_begin,
    const IterTy &preorder_end,
    const IterTy &inorder_begin,
    const IterTy &inorder_end)
{
    using ValueTy =
        typename std::iterator_traits<IterTy>::value_type;

    if (preorder_begin == preorder_end && inorder_begin == inorder_end)
        return nullptr;

    std::size_t dividing_index = get_dividing_index(
        inorder_begin,
        inorder_end,
        *(preorder_begin));

    akarithm::TreeNode<ValueTy> *root = new akarithm::TreeNode<ValueTy>(*preorder_begin);

    root->left = buildTreeTemplatePreIn(
        preorder_begin + 1,
        preorder_begin + dividing_index + 1,
        inorder_begin,
        inorder_begin + dividing_index);
    root->right = buildTreeTemplatePreIn(
        preorder_begin + dividing_index + 1,
        preorder_end,
        inorder_begin + dividing_index + 1,
        inorder_end);
    return root;
}

namespace akarithm
{

template <typename ValueTy>
static constexpr akarithm::TreeNode<ValueTy> *
buildTreePreIn(
    const std::vector<ValueTy> &preorder,
    const std::vector<ValueTy> &inorder)
{
    return buildTreeTemplatePreIn(
        preorder.cbegin(),
        preorder.cend(),
        inorder.cbegin(),
        inorder.cend());
}

} // namespace akarithm
