#include "doctest/doctest.h"

#include "akarithm/problem_589.hpp"

TEST_CASE("problem_589 -- iterative")
{
    const akarithm::Node<> *input =
        new akarithm::Node<>(1,
                   {new akarithm::Node<>(3,
                               {new akarithm::Node<>(5),
                                new akarithm::Node<>(6)}),
                    new akarithm::Node<>(2),
                    new akarithm::Node<>(4)});
    const std::vector<int> expected = {1, 3, 5, 6, 2, 4};
    const std::vector<int> result = akarithm::preorder_iterative(input);
    CHECK(expected == result);
    delete input;
}

TEST_CASE("problem_589 -- recursive")
{
    const akarithm::Node<> *input =
        new akarithm::Node<>(1,
                   {new akarithm::Node<>(3,
                               {new akarithm::Node<>(5),
                                new akarithm::Node<>(6)}),
                    new akarithm::Node<>(2),
                    new akarithm::Node<>(4)});
    const std::vector<int> expected = {1, 3, 5, 6, 2, 4};
    const std::vector<int> result = akarithm::preorder_recursive(input);
    CHECK(expected == result);
    delete input;
}
