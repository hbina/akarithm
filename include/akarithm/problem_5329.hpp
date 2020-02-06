#pragma once

#include "util/generic/group_by.hpp"

#include <vector>
#include <algorithm>

namespace akarithm
{

// TODO ::  This algorithm is really slow...
int minSetSize(
    const std::vector<int> &arr_input)
{
    std::vector<int> arr = arr_input;
    std::sort(std::begin(arr), std::end(arr));
    auto tmp =
        util::generic::group_by<std::vector<std::vector<int>>>(
            std::cbegin(arr),
            std::cend(arr),
            [](const std::vector<int> &lhs, const int &rhs)
                -> bool {
                return lhs.back() == rhs;
            });
    std::sort(
        std::begin(tmp),
        std::end(tmp),
        [](const std::vector<int> &lhs,
           const std::vector<int> &rhs) -> bool {
            return lhs.size() < rhs.size();
        });
    int acc = 0;
    return std::count_if(
        std::cbegin(tmp),
        std::cend(tmp),
        [&](const std::vector<int> &value)
            -> bool {
            acc += value.size();
            return acc > arr.size() / 2;
        });
}
} // namespace akarithm
