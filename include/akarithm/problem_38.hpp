#pragma once

#include "util/generic/group_by.hpp"

#include <string>
#include <vector>
#include <algorithm>

//  TODO    ::  Reimplement this using for-loops instead of recursion
namespace akarithm
{

template <
    typename NumType,
    typename OutputType = std::string>
static constexpr auto
countAndSay(const NumType &n)
    -> OutputType
{
    OutputType result = "1";
    for (auto a = 1; a < n; a++)
    {
        const auto grouped =
            akarithm::group_by<OutputType>(
                result.cbegin(),
                result.cend(),
                [](const OutputType &lhs, const auto &rhs)
                    -> bool {
                    return lhs.back() == rhs;
                });
        const auto transformed = std::accumulate(
            std::cbegin(grouped),
            std::cend(grouped),
            std::string{},
            [](std::string &acc, const std::string &value) {
                return acc + std::to_string(value.size()) + value.front();
            });
        result = transformed;
    }
    return result;
}

} // namespace akarithm
