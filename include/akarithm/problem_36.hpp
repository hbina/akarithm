#pragma once

#include <algorithm>
#include <vector>
#include <set>

//  TODO    ::  Implement a dispatcher tag for std::array<ValueTy,N> which can definitely be made
//              constexpr-able.
template <
    typename CharTy = char,
    typename IndexTyY =
        typename std::vector<std::vector<CharTy>>::difference_type,
    typename IndexTyX =
        typename std::vector<CharTy>::difference_type>
static constexpr auto
row_is_valid(
    const std::vector<std::vector<CharTy>> &sudoku,
    const IndexTyY &row_index)
    -> bool
{
    std::set<CharTy> set;
    for (IndexTyX x = 0; x < 9; x++)
    {
        if (sudoku[row_index][x] == '.')
            continue;
        else if (set.find(sudoku[row_index][x]) == std::cend(set))
            set.insert(sudoku[row_index][x]);
        else
            return false;
    }
    return true;
}

template <
    typename CharTy = char,
    typename IndexTyY =
        typename std::vector<std::vector<CharTy>>::difference_type,
    typename IndexTyX =
        typename std::vector<CharTy>::difference_type>
static constexpr auto
col_is_valid(
    const std::vector<std::vector<CharTy>> &sudoku,
    const IndexTyX &col_index)
    -> bool
{
    std::set<CharTy> set;
    for (IndexTyX y = 0; y < 9; y++)
    {
        if (sudoku[y][col_index] == '.')
            continue;
        else if (set.find(sudoku[y][col_index]) == std::cend(set))
            set.insert(sudoku[y][col_index]);
        else
            return false;
    }
    return true;
}

template <
    typename CharTy = char,
    typename IndexTyY =
        typename std::vector<std::vector<CharTy>>::difference_type,
    typename IndexTyX =
        typename std::vector<CharTy>::difference_type>
static constexpr auto
box_is_valid(
    const std::vector<std::vector<CharTy>> &sudoku,
    const IndexTyX &x_begin,
    const IndexTyX &x_end,
    const IndexTyY &y_begin,
    const IndexTyY &y_end)
    -> bool
{
    std::set<CharTy> set;
    for (IndexTyY y_iter = y_begin; y_iter < y_end; ++y_iter)
    {
        for (IndexTyX x_iter = x_begin; x_iter < x_end; ++x_iter)
        {
            if (sudoku[y_iter][x_iter] == '.')
                continue;
            else if (set.find(sudoku[y_iter][x_iter]) == std::cend(set))
                set.insert(sudoku[y_iter][x_iter]);
            else
                return false;
        }
    }
    return true;
}

namespace akarithm
{

//  This should really be std::array<CharTy, N>
template <
    typename CharTy = char,
    typename IndexTyY =
        typename std::vector<std::vector<CharTy>>::difference_type,
    typename IndexTyX =
        typename std::vector<CharTy>::difference_type>
static constexpr auto
isValidSudoku(
    const std::vector<std::vector<CharTy>> &board)
    -> bool
{
    for (IndexTyY y = 0; y < 9; y += 3)
    {
        for (IndexTyX x = 0; x < 9; x += 3)
        {
            if (!box_is_valid(board, x, x + 3, y, y + 3))
                return false;
        }
    }

    // Row unique
    for (IndexTyY y = 0; y < 9; y++)
    {
        if (!row_is_valid(board, y))
            return false;
    }

    // Column unique
    for (IndexTyX x = 0; x < 9; x++)
    {
        if (!col_is_valid(board, x))
            return false;
    }
    return true;
}

} // namespace akarithm
