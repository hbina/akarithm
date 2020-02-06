#pragma once

#include "data_structure/list_node.hpp"

#include <vector>
#include <algorithm>
#include <iterator>

namespace akarithm
{

template <typename T>
static constexpr auto
mergeKLists(
    std::vector<ListNode<T> *> &lists)
    -> ListNode<T> *
{
    lists.erase(
        std::remove_if(
            std::begin(lists),
            std::end(lists),
            [](const ListNode<T> *x)
                -> bool {
                return x == nullptr;
            }),
        std::end(lists));

    if (lists.empty())
        return nullptr;

    auto first_min = std::min_element(
        std::begin(lists),
        std::end(lists),
        [](const ListNode<T> *lhs, const ListNode<T> *rhs)
            -> bool {
            return lhs->val < rhs->val;
        });
    ListNode<T> *result = *first_min;
    lists[std::distance(std::begin(lists), first_min)] = lists[std::distance(std::begin(lists), first_min)]->next;
    ListNode<T> *next = result;

    while (!lists.empty())
    {
        lists.erase(
            std::remove_if(
                std::begin(lists),
                std::end(lists),
                [](const ListNode<T> *x)
                    -> bool {
                    return x == nullptr;
                }),
            std::end(lists));

        if (lists.empty())
            return result;

        auto first_min = std::min_element(
            std::begin(lists),
            std::end(lists),
            [](const ListNode<T> *lhs, const ListNode<T> *rhs)
                -> bool {
                return lhs->val < rhs->val;
            });
        next->next = *first_min;
        next = next->next;
        lists[std::distance(std::begin(lists), first_min)] = lists[std::distance(std::begin(lists), first_min)]->next;
    }
    return result;
}

} // namespace akarithm
