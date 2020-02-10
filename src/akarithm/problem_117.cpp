#include "doctest/doctest.h"

#include "akarithm/problem_117.hpp"

TEST_CASE("problem_117")
{
    akarithm::NodeNext<> *input =
        new akarithm::NodeNext<>(1,
                       new akarithm::NodeNext<>(2,
                                      new akarithm::NodeNext<>(4,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      new akarithm::NodeNext<>(5,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      nullptr),

                       new akarithm::NodeNext<>(3,
                                      nullptr,
                                      new akarithm::NodeNext<>(7,
                                                     nullptr,
                                                     nullptr,
                                                     nullptr),
                                      nullptr),
                       nullptr);
    akarithm::NodeNext<> *expected_node_7 = new akarithm::NodeNext<>(7);
    akarithm::NodeNext<> *expected_node_5 =
        new akarithm::NodeNext<>(5,
                       nullptr,
                       nullptr,
                       expected_node_7);
    akarithm::NodeNext<> *expected_node_4 =
        new akarithm::NodeNext<>(4,
                       nullptr,
                       nullptr,
                       expected_node_5);
    akarithm::NodeNext<> *expected_node_3 =
        new akarithm::NodeNext<>(3,
                       nullptr,
                       expected_node_7,
                       nullptr);
    akarithm::NodeNext<> *expected_node_2 =
        new akarithm::NodeNext<>(2,
                       expected_node_4,
                       expected_node_5,
                       expected_node_3);
    const akarithm::NodeNext<> *expected =
        new akarithm::NodeNext<>(1,
                       expected_node_2,
                       expected_node_3,
                       nullptr);
    const akarithm::NodeNext<int> *result = akarithm::connect(input);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
