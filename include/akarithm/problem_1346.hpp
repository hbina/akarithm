#pragma once

#include <vector>
#include <algorithm>

namespace akarithm
{

static auto
checkIfExist(
    const std::vector<int> &arr)
    -> bool
{
    auto arr_c = arr;
    std::sort(
        std::begin(arr_c),
        std::end(arr_c),
        [](const int &lhs, const int &rhs)
            -> bool {
            return std::abs(lhs) < std::abs(rhs);
        });
    auto parted = std::stable_partition(
        std::begin(arr_c),
        std::end(arr_c),
        [](const int &value)
            -> bool {
            return std::abs(value) % 2 != 0;
        });

    // Odd don't check with other odds
    for (auto odd_check = std::cbegin(arr_c);
         odd_check != parted;
         ++odd_check)
    {
        for (auto iter_i = parted;
             iter_i != std::cend(arr_c);
             iter_i++)
        {
            if ((*odd_check) * 2 == *iter_i)
                return true;
        }
    }
    // Even check with evens
    for (auto even_check = std::cbegin(arr_c);
         even_check != std::prev(std::cend(arr_c));
         ++even_check)
    {
        for (auto iter_i = std::next(even_check);
             iter_i != std::cend(arr_c);
             iter_i++)
        {
            if ((*even_check) * 2 == *iter_i)
                return true;
        }
    }
    return false;
}

} // namespace akarithm
