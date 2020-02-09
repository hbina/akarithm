#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cassert>

namespace akarithm
{

template <typename ValueTy>
int numUniqueEmails(const std::vector<ValueTy> &emails)
{
    std::unordered_map<ValueTy, std::size_t> map;
    for (const ValueTy &email : emails)
    {
        ValueTy temp;
        bool skipping_plus = false;
        bool skipping_dot = true;
        for (const char &a : email)
        {
            if (a == '+')
            {
                skipping_plus = true;
            }
            else if (a == '@')
            {
                skipping_dot = false;
                skipping_plus = false;
            }

            if (skipping_plus)
            {
                continue;
            }
            else if (a == '.' && skipping_dot)
            {
                continue;
            }
            else
            {
                temp += a;
            }
        }
        map[temp]++;
    }
    return static_cast<int>(map.size());
}

} // namespace akarithm
