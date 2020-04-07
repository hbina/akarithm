#include "doctest/doctest.h"

#include "util/generic/bst_search.hpp"

#include <string>

TEST_CASE("akarithm::bst_search") {
  akarithm::TreeNode<std::string> *expected =
      new akarithm::TreeNode<std::string>(
          "hell", new akarithm::TreeNode<std::string>("hel"),
          new akarithm::TreeNode<std::string>("hello o"));
  const akarithm::TreeNode<std::string> *input_1 =
      new akarithm::TreeNode<std::string>(
          "hello", expected,
          new akarithm::TreeNode<std::string>("hello world"));
  const int input_2 = 4;
  const auto result = akarithm::bst_search<std::string>(
      input_1,
      [&](const std::string &lhs) -> bool { return lhs.size() == input_2; },
      [&](const std::string &lhs) -> bool { return lhs.size() < input_2; });
  CHECK(expected == result);
  delete input_1;
}
