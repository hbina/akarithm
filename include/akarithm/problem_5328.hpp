#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

namespace akarithm
{

template <typename T>
static constexpr auto
kWeakestRows(
    const std::vector<std::vector<T>> &mat,
    const T &k)
    -> std::vector<T>
{
    std::vector<T> result;
    result.resize(mat.size());
    std::iota(
        std::begin(result),
        std::end(result),
        0);
    auto count_soldier =
        [](const std::vector<std::vector<T>> &mat,
           const std::size_t &index) -> std::size_t {
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
        [&](const T &lhs, const T &rhs) -> bool {
            return count_soldier(mat, lhs) < count_soldier(mat, rhs);
        });
    result.resize(k);
    return result;
}

} // namespace akarithm
