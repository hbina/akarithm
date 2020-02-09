#pragma once

#include <vector>
#include <string>
#include <iterator>
#include <type_traits>
#include <algorithm>
#include <numeric>

namespace akarithm
{

template <
    typename StringTy,
    typename MatchTy = std::vector<StringTy>,
    typename DifferenceTy =
        typename StringTy::difference_type,
    typename CharTy =
        typename StringTy::value_type>
static constexpr auto findSubstring(
    const StringTy &string,
    const MatchTy &matches)
    -> std::vector<DifferenceTy>
{
    //  NOTE    ::  This is actually a 2 part problem.
    //              1. The first part is finding the occurences of these elements
    //              2. Next is finding the parts that contains all of the matches
    //              We can also optimize a lot of stuff with matches. In particular,
    //              we can removes duplicates when one match is a subset of another match.
    return std::accumulate(
        std::cbegin(string),
        std::cend(string),
        std::vector<DifferenceTy>{},
        [](auto &acc, const CharTy &value) {
            return acc;
        });
}

} // namespace akarithm
