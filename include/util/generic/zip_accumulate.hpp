#pragma once

#include "util/generic/zip.hpp"

#include <iterator>

namespace akarithm
{

template <
    typename OutputType,
    typename IterTyLhs,
    typename IterTyRhs,
    typename DotFunction,
    typename AddFunction>
static constexpr auto
zip_accumulate(
    IterTyLhs lhs_begin,
    IterTyLhs lhs_end,
    IterTyRhs rhs_begin,
    IterTyRhs rhs_end,
    OutputType init,
    const DotFunction &dot,
    const AddFunction &add)
    -> OutputType
{
    akarithm::zip(
        lhs_begin,
        lhs_end,
        rhs_begin,
        rhs_end,
        [&](const auto &left, const auto &right) {
            init = add(init, dot(left, right));
        });
    return init;
}

} // namespace akarithm
