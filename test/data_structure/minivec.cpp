#include <doctest/doctest.h>

#include "data_structure/minivec.hpp"

#include <thread>
#include <vector>

TEST_CASE("basic vector operations")
{
  aka::minivec<int> vec;
  for (int a = 0; a < 100; a++) {
    vec.push_back(a);
  }
  for (int a = 0; a < 100; a++) {
    CHECK_EQ(vec[a], a);
  }
}
