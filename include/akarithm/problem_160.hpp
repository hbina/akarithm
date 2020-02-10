#pragma once

#include "data_structure/list_node.hpp"

#include <iostream>

namespace akarithm
{

template <typename ValueTy>
static constexpr akarithm::ListNode<ValueTy> *getIntersectionNode(ListNode<ValueTy> *headA, akarithm::ListNode<ValueTy> *headB)
{
    if (!headA || !headB)
    {
        return nullptr;
    }
    akarithm::ListNode<ValueTy> *pointerA = headA;
    akarithm::ListNode<ValueTy> *pointerB = headB;

    // Recalibrate pointers
    int both_reverted = 2;
    while (both_reverted != 0)
    {
        if (pointerA->next)
        {
            pointerA = pointerA->next;
        }
        else
        {
            pointerA = headB;
            both_reverted -= 1;
        }

        if (pointerB->next)
        {
            pointerB = pointerB->next;
        }
        else
        {
            pointerB = headA;
            both_reverted -= 1;
        }
    }
    while (pointerA)
    {
        if (pointerA == pointerB)
        {
            return pointerA;
        }
        else
        {
            pointerA = pointerA->next;
            pointerB = pointerB->next;
        }
    }
    return nullptr;
}

} // namespace akarithm
