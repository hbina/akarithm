#pragma once

#include "util/generic/group_by_minify.hpp"
#include "util/generic/sliding_window.hpp"

#include <vector>
#include <algorithm>
#include <functional>

namespace akarithm
{

template <
    typename IntTy,
    typename ResultTy = typename std::vector<std::vector<IntTy>>>
static constexpr auto
fourSum(
    const std::vector<IntTy> &nums,
    const IntTy &target)
    -> ResultTy
{
    return {};
}

} // namespace akarithm
