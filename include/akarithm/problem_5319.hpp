#pragma once

#include "util/generic/is_palindrome.hpp"

#include <string>
#include <algorithm>

namespace akarithm
{

template <
    typename StringType = std::string>
static constexpr auto
removePalindromeSub(
    const StringType &s)
    -> int
{
    if (s.empty())
        return 0;
    else if (util::generic::is_palindrome(std::cbegin(s), std::cend(s)))
        return 1;
    else
        return 2;
}

} // namespace akarithm
