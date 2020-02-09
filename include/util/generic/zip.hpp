#pragma once

#include <iterator>

namespace akarithm
{

template <
    typename IterTyLhs,
    typename IterTyRhs,
    typename BinaryFunction>
static constexpr void
zip(
    IterTyLhs iter_lhs_begin,
    IterTyLhs iter_lhs_end,
    IterTyRhs iter_rhs_begin,
    IterTyRhs iter_rhs_end,
    const BinaryFunction &fun)
{
    while (iter_lhs_begin != iter_lhs_end && iter_rhs_begin != iter_rhs_end)
    {
        fun(*iter_lhs_begin, *iter_rhs_begin);
        iter_lhs_begin++;
        iter_rhs_begin++;
    }
}

} // namespace akarithm
