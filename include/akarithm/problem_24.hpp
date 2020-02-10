#pragma once

#include "data_structure/list_node.hpp"

namespace akarithm
{

template <typename ValueTy>
ListNode<ValueTy> *swapPairs(ListNode<ValueTy> *head)
{
    if (!head)
    {
        return nullptr;
    }
    else if (!head->next)
    {
        return head;
    }
    else
    {
        akarithm::ListNode<ValueTy> *result = head->next;
        head->next = swapPairs(result->next);
        result->next = head;
        return result;
    }
}

} // namespace akarithm
