#include <doctest/doctest.h>

#include "util/generic/bst_search.hpp"

#include <string>

TEST_CASE("aka::bst_search")
{
  aka::TreeNode<std::string>* expected =
    new aka::TreeNode<std::string>(
      "hell",
      new aka::TreeNode<std::string>("hel"),
      new aka::TreeNode<std::string>("hello o"));
  const aka::TreeNode<std::string>* input_1 =
    new aka::TreeNode<std::string>(
      "hello", expected, new aka::TreeNode<std::string>("hello world"));
  const int input_2 = 4;
  const auto result = aka::bst_search<std::string>(
    input_1,
    [&](const std::string& lhs) -> bool { return lhs.size() == input_2; },
    [&](const std::string& lhs) -> bool { return lhs.size() < input_2; });
  CHECK(expected == result);
  delete input_1;
}
