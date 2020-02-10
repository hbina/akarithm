#pragma once

#include "data_structure/list_node.hpp"

namespace akarithm
{

template <
    typename ValueTy,
    typename UnaryPredicate>
static constexpr akarithm::ListNode<ValueTy> *
removeElements_If(
    akarithm::ListNode<ValueTy> *head,
    const UnaryPredicate &pred)
{
    if (!head)
    {
        return nullptr;
    }
    else if (pred(head->val))
    {
        akarithm::ListNode<ValueTy> *result = removeElements_If(head->next, pred);
        head->next = nullptr;
        delete head;
        return result;
    }
    else
    {
        if (!head->next)
        {
            return head;
        }
        else
        {
            if (pred(head->next->val))
            {
                akarithm::ListNode<ValueTy> *tmp = head->next;
                head->next = removeElements_If(head->next->next, pred);
                tmp->next = nullptr;
                delete tmp;
                return head;
            }
            else
            {
                head->next = removeElements_If(head->next, pred);
                return head;
            }
        }
    }
}

template <typename ValueTy>
static constexpr akarithm::ListNode<ValueTy> *
removeElements(
    akarithm::ListNode<ValueTy> *head,
    const ValueTy &val)
{
    if (!head)
    {
        return nullptr;
    }
    else if (head->val == val)
    {
        akarithm::ListNode<ValueTy> *result = removeElements(head->next, val);
        head->next = nullptr;
        delete head;
        return result;
    }
    else
    {
        if (!head->next)
        {
            return head;
        }
        else
        {
            if (head->next->val == val)
            {
                akarithm::ListNode<ValueTy> *tmp = head->next;
                head->next = removeElements(head->next->next, val);
                tmp->next = nullptr;
                delete tmp;
                return head;
            }
            else
            {
                head->next = removeElements(head->next, val);
                return head;
            }
        }
    }
}

} // namespace akarithm
