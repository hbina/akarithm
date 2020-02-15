#pragma once

#include "data_structure/tree_node.hpp"
#include "data_structure/bst_iterator.hpp"

#include <vector>
#include <stack>

//  TODO    ::  Remove heap usages
//  FIXME   ::  Need to look at tree iterator implementation
namespace akarithm
{

template <
    typename ValueTy,
    typename BinaryPredicate>
static std::vector<ValueTy>
getAllElements_If(
    const akarithm::TreeNode<ValueTy> *lhs,
    const akarithm::TreeNode<ValueTy> *rhs,
    const BinaryPredicate &pred)
{
    std::vector<ValueTy> result;

    akarithm::BSTIterator lhs_iterator =
        akarithm::BSTIterator(lhs);
    akarithm::BSTIterator rhs_iterator =
        akarithm::BSTIterator(rhs);

    while (lhs_iterator.hasNext() && rhs_iterator.hasNext())
    {
        //  Can be replaced with a Comp
        if (pred(lhs_iterator.peek()->val, rhs_iterator.peek()->val))
            result.emplace_back(lhs_iterator.next()->val);
        else
            result.emplace_back(rhs_iterator.next()->val);
    }
    while (lhs_iterator.hasNext())
        result.emplace_back(lhs_iterator.next()->val);
    while (rhs_iterator.hasNext())
        result.emplace_back(rhs_iterator.next()->val);

    return result;
}

template <
    typename ValueTy>
static std::vector<ValueTy>
getAllElements(
    const akarithm::TreeNode<ValueTy> *lhs,
    const akarithm::TreeNode<ValueTy> *rhs)
{
    return getAllElements_If(lhs, rhs, std::less{});
}

} // namespace akarithm
