#pragma once

#include "util/generic/split.hpp"

#include <vector>
#include <algorithm>

namespace akarithm
{

template <
    typename StringTy = std::string,
    typename CharTy =
        typename std::string::value_type>
static constexpr auto
daysBetweenDates(
    const StringTy &date1,
    const StringTy &date2)
    -> int
{
    const auto split_dates = [](const StringTy &date) {
        return akarithm::split_if<CharTy>(
            std::cbegin(date),
            std::cend(date),
            [](const CharTy &elem)
                -> bool {
                return elem == '-';
            });
    };

    const auto date_1 = split_dates(date1);
    const auto date_2 = split_dates(date2);

    // Calculates the dates...
    return true;
}

} // namespace akarithm
