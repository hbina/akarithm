#pragma once

#include <string>
#include <vector>
#include <algorithm>

template <
    typename StringTy,
    typename SizeTy =
        typename StringTy::size_type>
static constexpr auto
expand_around_center(
    const StringTy &s,
    const SizeTy &left,
    const SizeTy &right)
    -> SizeTy
{
    SizeTy L = left + 1, R = right;
    while (L > SizeTy{} && R < s.size() && s[L - 1] == s[R])
    {
        L--;
        R++;
    }
    return R - L;
}

namespace akarithm
{

template <
    typename StringTy,
    typename SizeTy =
        typename StringTy::size_type>
static constexpr auto
longestPalindrome(const StringTy &s)
    -> StringTy
{
    if (s.size() < 1)
        return {};
    SizeTy start = 0, end = 0;
    for (SizeTy i = 0; i < s.size(); i++)
    {
        SizeTy len1 = expand_around_center(s, i, i);
        SizeTy len2 = expand_around_center(s, i, i + 1);
        SizeTy len = std::max(len1, len2);
        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return {std::next(std::cbegin(s), start), std::next(std::cbegin(s), end + 1)};
}

} // namespace akarithm
