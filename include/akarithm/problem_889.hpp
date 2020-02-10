#pragma once

#include "data_structure/tree_node.hpp"

#include <cassert>
#include <vector>
#include <algorithm>
#include <memory>
#include <type_traits>
#include <iterator>

namespace akarithm
{

template <
    typename IterTy,
    typename ValueTy =
        typename std::iterator_traits<IterTy>::value_type>
static constexpr auto
constructFromPrePostTemplate(
    const IterTy &preorder_begin,
    const IterTy &preorder_end,
    const IterTy &postorder_begin,
    const IterTy &postorder_end)
    -> akarithm::TreeNode<ValueTy> *
{
    if (preorder_begin == preorder_end && postorder_begin == postorder_end)
        return nullptr;
    else if (
        std::distance(preorder_begin, preorder_end) == 1 &&
        std::distance(postorder_begin, postorder_end) == 1)
    {
        return new akarithm::TreeNode<ValueTy>(*preorder_begin);
    }
    else
    {
        akarithm::TreeNode<ValueTy> *root = new akarithm::TreeNode<ValueTy>(*preorder_begin);

        // Figure out the next element in preorder
        ValueTy next_preorder_element = *(preorder_begin + 1);
        std::size_t size_of_partition_B =
            std::distance(
                postorder_begin,
                std::find(
                    postorder_begin,
                    postorder_end,
                    next_preorder_element)) +
            1;
        std::size_t size_of_partition_C =
            std::distance(
                preorder_begin,
                preorder_end) -
            1 - size_of_partition_B;
        root->left = constructFromPrePostTemplate(
            preorder_begin + 1,
            preorder_begin + 1 + size_of_partition_B,
            postorder_begin,
            postorder_begin + size_of_partition_B);
        root->right = constructFromPrePostTemplate(
            preorder_begin + 1 + size_of_partition_B,
            preorder_begin + 1 + size_of_partition_B + size_of_partition_C,
            postorder_begin + size_of_partition_B,
            postorder_begin + size_of_partition_B + size_of_partition_C);
        return root;
    }
}

template <typename ValueTy>
static constexpr auto
constructFromPrePost(
    const std::vector<ValueTy> &preorder,
    const std::vector<ValueTy> &postorder)
    -> akarithm::TreeNode<ValueTy> *
{
    return constructFromPrePostTemplate(
        preorder.cbegin(),
        preorder.cend(),
        postorder.cbegin(),
        postorder.cend());
}

} // namespace akarithm
