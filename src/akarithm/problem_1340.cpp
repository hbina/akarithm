#include "doctest/doctest.h"

#include "akarithm/problem_1340.hpp"

TEST_CASE("problem 1340 1")
{
    const std::vector<int> input_1 = {6, 5, 4, 3, 2, 1};
    const int input_2 = 2;
    const int expected = 7;
    const int result = akarithm::minDifficulty(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1340 2")
{
    const std::vector<int> input_1 = {9, 9, 9};
    const int input_2 = 4;
    const int expected = -1;
    const int result = akarithm::minDifficulty(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1340 3")
{
    const std::vector<int> input_1 = {1, 1, 1};
    const int input_2 = 3;
    const int expected = 3;
    const int result = akarithm::minDifficulty(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1340 4")
{
    const std::vector<int> input_1 = {7, 1, 7, 1, 7, 1};
    const int input_2 = 3;
    const int expected = 15;
    const int result = akarithm::minDifficulty(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1340 5")
{
    const std::vector<int> input_1 = {11, 111, 22, 222, 33, 333, 44, 444};
    const int input_2 = 6;
    const int expected = 843;
    const int result = akarithm::minDifficulty(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1340 6")
{
    const std::vector<int> input_1 = {186, 398, 479, 206, 885, 423, 805, 112, 925, 656, 16, 932, 740, 292, 671, 360};
    const int input_2 = 4;
    const int expected = 1803;
    const int result = akarithm::minDifficulty(input_1, input_2);
    CHECK(expected == result);
}
