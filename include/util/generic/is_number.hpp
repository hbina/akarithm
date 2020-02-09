#pragma once

#include <algorithm>
#include <string>
#include <type_traits>
#include <iterator>

namespace akarithm
{

template <typename Iterable>
static constexpr bool
is_number(const Iterable &s)
{
    using ValueTy =
        typename std::iterator_traits<
            typename Iterable::iterator>::value_type;
    return !s.empty() &&
           std::find_if(s.begin(),
                        s.end(),
                        [](const ValueTy &c) { return !std::isdigit(c); }) == s.end();
}

} // namespace akarithm
