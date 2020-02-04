#pragma once

#include <tuple>
#include <iterator>

namespace util
{
namespace generic
{

template <
    typename Iterator,
    typename DecisionFunction,
    typename FoundFunction,
    typename ValueType =
        typename std::iterator_traits<Iterator>::value_type>
static constexpr auto
sliding_window(
    Iterator begin,
    Iterator end,
    const DecisionFunction &decision,
    const FoundFunction &found)
    -> std::pair<Iterator, Iterator>
{
    Iterator end_c = end;
    --end;
    while (begin != end)
    {
        if (found(*begin, *end))
            return {begin, end};
        else
        {
            if (decision(*begin, *end))
                ++begin;
            else
                --end;
        }
    }
    return {end_c, end_c};
}

} // namespace generic
} // namespace util
