#include <doctest/doctest.h>

#include "data_structure/vector.hpp"

#include <iostream>

TEST_CASE("aka::vector")
{
  aka::vector<int> result = aka::vector<int>::from({ 1, 2, 3, 4, 5 })
                                   .map([](const int& x) { return x * 2; })
                                   .filter([](const int& x) { return x > 6; });
  for (const int& x : result) {
    CHECK(x <= 6);
  }
}
