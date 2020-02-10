#pragma once

#include "data_structure/list_node.hpp"

namespace akarithm
{

template <
    typename ValueTy,
    typename IndexTy = int>
static constexpr auto
removeNthFromEnd(
    akarithm::ListNode<ValueTy> *head,
    const IndexTy &n)
    -> akarithm::ListNode<ValueTy> *
{
    akarithm::ListNode<ValueTy> *barrier = head;
    for (IndexTy iter = 0; iter < n; iter++)
    {
        barrier = barrier->next;
    }

    if (!barrier)
    {
        akarithm::ListNode<ValueTy> *result = head->next;
        head->next = nullptr;
        delete head;
        return result;
    }
    else
    {
        akarithm::ListNode<ValueTy> *iter = head;
        while (barrier->next)
        {
            barrier = barrier->next;
            iter = iter->next;
        }

        akarithm::ListNode<ValueTy> *tmp = iter->next;
        iter->next = iter->next->next;
        tmp->next = nullptr;
        delete tmp;
        return head;
    }
}

} // namespace akarithm
