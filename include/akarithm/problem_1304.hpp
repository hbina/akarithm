#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

namespace akarithm
{

//  Replace this implementation with std::generate_n
template <
    typename ValueTy,
    typename Iterable = std::vector<ValueTy>>
Iterable sumZero(const ValueTy &n)
{
    using DifferenceTy =
        typename std::iterator_traits<
            typename Iterable::iterator>::difference_type;
    Iterable result(static_cast<DifferenceTy>(n));
    std::iota(
        std::begin(result),
        std::end(result),
        -(static_cast<ValueTy>(n / 2)));
    if (static_cast<DifferenceTy>(n) % 2 == 0)
    {
        std::for_each(
            std::next(
                std::begin(result),
                static_cast<DifferenceTy>(n / 2)),
            std::end(result),
            [](ValueTy &value) {
                value++;
            });
    }
    return result;
}

} // namespace akarithm
