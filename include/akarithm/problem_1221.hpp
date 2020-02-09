#pragma once

#include <string>
#include <type_traits>
#include <cassert>
#include <stack>

namespace akarithm
{

//  TODO    ::  Narrow down this template to only accept types that implements std::char_traits
template <
    typename CounterTy = std::size_t,
    typename StringTy = std::string>
static constexpr auto
balancedStringSplit(const StringTy &s)
    -> CounterTy
{
    CounterTy global_counter{};
    int counter = 0;
    for (const auto &x : s)
    {
        if (x == 'L')
        {
            counter--;
        }
        else if (x == 'R')
        {
            counter++;
        }
        else
        {
            assert(false);
        }
        if (counter == 0)
        {
            global_counter++;
        }
    }
    return global_counter;
}

} // namespace akarithm
