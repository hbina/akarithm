#pragma once

#include "data_structure/list_node.hpp"

namespace akarithm
{

template <typename ValueTy>
std::size_t getDecimalValue(const akarithm::ListNode<ValueTy> *head)
{
    std::size_t result = 0;
    while (head)
    {
        result = result << 1;
        result |= head->val;
        head = head->next;
    }
    return result;
}

} // namespace akarithm
