#include "doctest/doctest.h"

#include "util/generic/bst_search.hpp"

#include <string>

TEST_CASE("akarithm::bst_search")
{
    TreeNode<std::string> *expected =
        new TreeNode<std::string>("hell",
                                  new TreeNode<std::string>("hel"),
                                  new TreeNode<std::string>("hello o"));
    const TreeNode<std::string> *input_1 =
        new TreeNode<std::string>("hello",
                                  expected,
                                  new TreeNode<std::string>("hello world"));
    const int input_2 = 4;
    const auto result =
        akarithm::bst_search<std::string>(
            input_1,
            [&](const std::string &lhs)
                -> bool {
                return lhs.size() == input_2;
            },
            [&](const std::string &lhs)
                -> bool {
                return lhs.size() < input_2;
            });
    CHECK(expected == result);
    delete input_1;
}
