#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <iterator>
#include <tuple>

template <typename Iterator,
          typename ValueType = typename std::iterator_traits<Iterator>::value_type,
          typename IndexType = typename std::iterator_traits<Iterator>::difference_type>
static constexpr auto
second_largest_index(
    Iterator begin,
    Iterator end)
    -> IndexType
{
    auto distance = std::distance(begin, end);
    if (distance == 0)
        return static_cast<IndexType>(-1);
    if (distance == 1)
        return 0;
    std::array<IndexType, 2> maxs = {0, 1};
    if (*(begin + maxs[0]) < *(begin + maxs[1]))
        std::swap(maxs[0], maxs[1]);
    for (auto iter = begin + 2; iter != end; ++iter)
    {
        if (*iter > *(begin + maxs[1]))
        {
            maxs[1] = std::distance(begin, iter);
            if ((*begin + maxs[1]) > *(begin + maxs[0]))
                std::swap(maxs[0], maxs[1]);
        }
    }
    return maxs[1];
}

enum class Direction
{
    LEFT,
    RIGHT
};

template <typename ValueType,
          typename IndexType,
          typename Triplet = std::tuple<IndexType, ValueType, Direction>>
static constexpr auto
inquire(
    const std::vector<ValueType> &arr,
    const IndexType index)
    -> Triplet
{
    if (index == 0)
        return {index, arr[index] - arr[index + 1], Direction::RIGHT};
    else if (index == arr.size() - 1)
        return {index, arr[index] - arr[index - 1], Direction::LEFT};
    else
    {
        if (arr[index - 1] > arr[index + 1])
            return {index, arr[index] - arr[index - 1], Direction::LEFT};
        else
            return {index, arr[index] - arr[index + 1], Direction::RIGHT};
    }
}

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
    using Pair = std::pair<IndexType, ValueType>;
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
        auto arr_c = arr;
        while (arr_c.size() != d)
        {
            std::vector<Pair> inquiries;
            for (IndexType iter = 0; iter != arr_c.size() - 1; ++iter)
            {
                inquiries.emplace_back(iter, arr_c[iter] - arr_c[iter + 1]);
            }
            std::stable_sort(
                std::begin(inquiries),
                std::end(inquiries),
                [](const Pair &lhs,
                   const Pair &rhs)
                    -> bool {
                    return std::abs(lhs.second) < std::abs(rhs.second);
                });
            auto find_last = std::find_if(
                std::begin(inquiries) + 1,
                std::end(inquiries),
                [&](const Pair &value)
                    -> bool {
                    return std::abs(value.second) != std::abs((*std::begin(inquiries)).second);
                });
            auto find_largest = std::max_element(
                std::begin(inquiries),
                find_last,
                [&](const Pair &lhs,
                    const Pair &rhs)
                    -> bool {
                    return arr_c[lhs.first] < arr_c[rhs.first];
                });
            if ((*find_largest).second < 0)
            {
                arr_c.erase(std::begin(arr_c) + (*find_largest).first);
            }
            else
            {
                arr_c.erase(std::begin(arr_c) + (*find_largest).first + 1);
            }
        }
        return std::accumulate(
            std::cbegin(arr_c),
            std::cend(arr_c),
            0);
    }
}

} // namespace akarithm
