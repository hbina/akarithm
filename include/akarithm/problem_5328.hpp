#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

namespace akarithm
{

static auto
kWeakestRows(
    const std::vector<std::vector<int>> &mat,
    const int k)
    -> std::vector<int>
{
    std::vector<int> result;
    result.resize(mat.size());
    std::iota(
        std::begin(result),
        std::end(result),
        0);
    auto count_soldier =
        [](const std::vector<std::vector<int>> &mat,
           const std::size_t &index) -> int {
        return std::distance(
            std::cbegin(mat[index]),
            std::find(
                std::cbegin(mat[index]),
                std::cend(mat[index]),
                0));
    };
    std::stable_sort(
        std::begin(result),
        std::end(result),
        [&](const int &lhs, const int &rhs) -> bool {
            return count_soldier(mat, lhs) < count_soldier(mat, rhs) ;
        });
    result.resize(k);
    return result;
}

} // namespace akarithm
