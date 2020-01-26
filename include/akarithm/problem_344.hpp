#pragma once

#include <vector>
#include <algorithm>

namespace akarithm
{

void reverseString(std::vector<char> &s)
{
    std::reverse(s.begin(), s.end());
}

} // namespace akarithm
