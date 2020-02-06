#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <iterator>
#include <tuple>
#include <limits>

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
        while (arr_c.size() < d)
        {
            std::vector<PairType> tmp;
            tmp.reserve(arr.size() - 1);
            // This is basically adjacent difference.
            // Each pair is asked how much they will contribute if they are merged together.
            for (IndexType iter = 0; iter < arr_c.size() - 1; iter++)
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

template <typename T>
static constexpr auto
minDifficulty_Copy(
    const std::vector<T> &arr,
    const T &days)
    -> T
{
    using IndexType = typename std::vector<T>::size_type;

    // Step 1: Find the cost of all possible ranges.

    // Step 1.a: Initialize the 2 dimensional array.
    const auto n = arr.size();
    std::vector<std::vector<T>> maxes(n);
    for (std::vector<T> &r : maxes)
        r.resize(n);

    // Step 1.b: Finds the price of every possible range
    // by comparing the previous range's cost
    // with the current value.
    // i.e. given:
    // ..., [   6    ], 10, 4, ...
    // We compare 6 with 10 for the new max thus our new range is then,
    // ..., [     10     ], 4, ...
    for (IndexType i = 0; i < n; i++)
    {
        maxes[i][i] = arr[i];
        for (IndexType j = i + 1; j < n; j++)
            maxes[i][j] = std::max(maxes[i][j - 1], arr[j]);
    }

    // Step 2: Begin dp algorithm.
    // Basically we are trying to find the best possible
    // configurations from the ground up. First
    // iteration finds the best configuration of splitting into 1s
    // Second into 2s etc etc.
    // This works because dp index = 1 at iteration N tells us the
    // best configuration beginning from index = 1 --> end of N globs.

    // Step 2.a: Initialize dp at index i with the cost of
    // taking the range i -> end
    std::vector<T> dp(n);
    for (IndexType i = 0; i < n; i++)
        dp[i] = maxes[i].back();

    // Step 2.b: Iterate through the possible globs configuration from the ground-up.
    for (IndexType d = 1; d < days; d++)
    {
        // Step 2.c: Find the best configuration for this iteration.
        // The index i here represents the first element of the first glob.
        // i.e.
        //   A                 B
        // |---|--------------------------------|
        // equivalent to,
        // |---|[maxes[i][j]]|     dp[j + 1]    |
        // equivalent to,
        // ..., [arr[i], ...], [...], [...], ...
        // In the case of index i != 0, Part A is uninteresting to us.
        // If index i != 0, we are trying to collect information for the next
        // iteration. This is why we stop before d == N. Because for iteration
        // d - 1, we have built up all the information that index i = 0 at iteration
        // d requires. After all, dp[0] is the answer.
        // Notice what we are doing in part B.
        // We are saying, lets say arr[i] is the first element of the first glob in
        // this solution; this is represented by maxes[i][j].
        // Plus the possible configurations from the previous iteration, from index
        // j + 1 onwards.
        // Is this less than the previous found configuration at index i? If so, then replace.
        for (IndexType i = 0; i < n - d; i++)
        {
            dp[i] = std::numeric_limits<T>::max();
            for (IndexType j = i; j < n - d; j++)
            {
                dp[i] = std::min(dp[i], maxes[i][j] + dp[j + 1]);
            }
        }
    }
    if (n >= days)
    {
        return dp[0];
    }
    else
    {
        return -1;
    }
}

} // namespace akarithm
