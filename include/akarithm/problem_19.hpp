#pragma once

#include "data_structure/list_node.hpp"

namespace akarithm
{

template <
    typename ValueTy,
    typename IndexTy = int>
static constexpr auto
removeNthFromEnd(
    ListNode<ValueTy> *head,
    const IndexTy &n)
    -> ListNode<ValueTy> *
{
    ListNode<ValueTy> *barrier = head;
    for (IndexTy iter = 0; iter < n; iter++)
    {
        barrier = barrier->next;
    }

    if (!barrier)
    {
        ListNode<ValueTy> *result = head->next;
        head->next = nullptr;
        delete head;
        return result;
    }
    else
    {
        ListNode<ValueTy> *iter = head;
        while (barrier->next)
        {
            barrier = barrier->next;
            iter = iter->next;
        }

        ListNode<ValueTy> *tmp = iter->next;
        iter->next = iter->next->next;
        tmp->next = nullptr;
        delete tmp;
        return head;
    }
}

} // namespace akarithm
