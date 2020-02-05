#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <iterator>
#include <tuple>

// TODO ::  Only works with signed integers.
namespace akarithm
{

template <typename ValueType>
static constexpr auto
minDifficulty(
    const std::vector<ValueType> &arr,
    const ValueType &d)
    -> ValueType
{
    using IndexType = typename std::iterator_traits<
        typename std::vector<ValueType>::iterator>::difference_type;
    using PairType = std::pair<IndexType, ValueType>;
    if (d > arr.size())
    {
        return -1;
    }
    else if (d == arr.size())
    {
        return std::accumulate(
            std::cbegin(arr),
            std::cend(arr),
            0);
    }
    else
    {
        std::vector<ValueType> arr_c = arr;
        while (arr_c.size() != d)
        {
            std::vector<PairType> tmp;
            tmp.reserve(arr.size() - 1);
            // This is basically adjacent difference.
            // Each pair is asked how much they will contribute if they are merged together.
            for (IndexType iter = 0; iter != arr_c.size() - 1; iter++)
            {
                if (arr_c[iter] > arr_c[iter + 1])
                    tmp.emplace_back(iter + 1, arr_c[iter + 1]);
                else
                    tmp.emplace_back(iter, arr_c[iter]);
            }
            // From the previous inquiry, get the element with the largest contribution.
            const PairType tt = *std::max_element(
                std::cbegin(tmp), std::cend(tmp),
                [](const PairType &lhs, const PairType &rhs)
                    -> bool {
                    return lhs.second < rhs.second;
                });
            // Remove that element from the array.
            arr_c.erase(std::begin(arr_c) + tt.first);
        }
        return std::accumulate(
            std::cbegin(arr_c),
            std::cend(arr_c),
            0);
    }
}

} // namespace akarithm
