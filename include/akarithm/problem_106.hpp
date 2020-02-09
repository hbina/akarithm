#pragma once

#include "data_structure/tree_node.hpp"

#include <vector>
#include <algorithm>
#include <memory>
#include <type_traits>
#include <iterator>

template <typename IterTy,
          typename ValueTy,
          typename DifferenceTy =
              typename std::iterator_traits<IterTy>::difference_type,
          typename = std::enable_if_t<
              std::is_same_v<
                  typename std::iterator_traits<IterTy>::value_type,
                  ValueTy>>>
static constexpr auto
get_dividing_index(
    const IterTy &inorder_begin,
    const IterTy &inorder_end,
    const ValueTy &postorder_end)
    -> DifferenceTy
{
    return std::distance(
        inorder_begin,
        std::find(
            inorder_begin,
            inorder_end,
            postorder_end));
}

template <typename IterTy>
static constexpr auto
buildTreeTemplateInPost(
    const IterTy &inorder_begin,
    const IterTy &inorder_end,
    const IterTy &postorder_begin,
    const IterTy &postorder_end)
    -> TreeNode<
        typename std::iterator_traits<IterTy>::value_type> *
{
    using ValueTy =
        typename std::iterator_traits<IterTy>::value_type;

    if (inorder_begin == inorder_end && postorder_begin == postorder_end)
        return nullptr;

    std::size_t dividing_index = get_dividing_index(
        inorder_begin,
        inorder_end,
        *(postorder_end - 1));

    TreeNode<ValueTy> *root = new TreeNode<ValueTy>(*(inorder_begin + dividing_index));

    root->left = buildTreeTemplateInPost(
        inorder_begin,
        inorder_begin + dividing_index,
        postorder_begin,
        postorder_begin + dividing_index);
    root->right = buildTreeTemplateInPost(
        inorder_begin + dividing_index + 1,
        inorder_end,
        postorder_begin + dividing_index,
        postorder_end - 1);
    return root;
}

namespace akarithm
{

template <typename ValueTy>
static constexpr auto
buildTreeInPost(
    const std::vector<ValueTy> &inorder,
    const std::vector<ValueTy> &postorder)
    ->TreeNode<ValueTy> *
{
    return buildTreeTemplateInPost(
        inorder.cbegin(),
        inorder.cend(),
        postorder.cbegin(),
        postorder.cend());
}

} // namespace akarithm
