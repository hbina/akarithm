#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

namespace akarithm
{

template <typename ValueTy>
static constexpr auto
kWeakestRows(
    const std::vector<std::vector<ValueTy>> &mat,
    const ValueTy &k)
    -> std::vector<ValueTy>
{
    std::vector<ValueTy> result;
    result.resize(mat.size());
    std::iota(
        std::begin(result),
        std::end(result),
        0);
    auto count_soldier =
        [](const std::vector<std::vector<ValueTy>> &mat,
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
        [&](const ValueTy &lhs, const ValueTy &rhs) -> bool {
            return count_soldier(mat, lhs) < count_soldier(mat, rhs);
        });
    result.resize(k);
    return result;
}

} // namespace akarithm
