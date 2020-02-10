#include <doctest/doctest.h>

#include "akarithm/problem_297.hpp"

TEST_CASE("problem_297")
{
    akarithm::TreeNode<int> *input = new akarithm::TreeNode<>(
        1,
        new akarithm::TreeNode<>(2),
        new akarithm::TreeNode<>(3,
                       new akarithm::TreeNode<>(4),
                       new akarithm::TreeNode<>(5)));
    // akarithm::TreeNode<int> *result = Codec<int>::deserialize(Codec<int>::serialize(input));
    // CHECK(*input == *result);
    delete input;
    // delete result;
}
