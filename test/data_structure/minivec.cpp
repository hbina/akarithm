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

TEST_CASE("check vector copy constructor")
{
  aka::minivec<int> vec;
  for (int a = 0; a < 100; a++) {
    vec.push_back(a);
  }
  aka::minivec vec_copy = vec;
  for (int a = 0; a < 100; a++) {
    CHECK_EQ(vec_copy[a], vec[a]);
    CHECK(&vec_copy[a] != &vec[a]);
  }
}

TEST_CASE("check vector copy assignment")
{
  aka::minivec<int> vec;
  for (int a = 0; a < 100; a++) {
    vec.push_back(a);
  }
  aka::minivec vec_copy_ctor = vec;
  for (int a = 0; a < 100; a++) {
    vec_copy_ctor.push_back(a);
  }
  vec_copy_ctor = vec;
  for (int a = 0; a < 100; a++) {
    CHECK_EQ(vec_copy_ctor[a], vec[a]);
    CHECK(&vec_copy_ctor[a] != &vec[a]);
  }
}

TEST_CASE("check vector iteration")
{
  aka::minivec<int> vec;
  for (int a = 0; a < 100; a++) {
    vec.push_back(a);
  }
  int a = 0;
  for (const int& x : vec) {
    CHECK(a == x);
    a++;
  }
}
