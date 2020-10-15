#include <doctest/doctest.h>

#include "data_structure/variable_guard.hpp"

#include <thread>
#include <vector>

TEST_CASE("calculate sum")
{
  aka::variable_guard<int> sum = aka::variable_guard(0);
  aka::variable_guard<std::vector<std::thread>> threads;
  for (int a = 0; a < 10; a++) {
    threads.usem([&](std::vector<std::thread>& threads) {
      threads.push_back(std::thread([&]() {
        for (int b = 0; b < 100; b++) {
          sum.usem([&](int& value) { value += b; });
        }
      }));
    });
  }
  threads.usem([](std::vector<std::thread>& threads) {
    for (std::thread& thread : threads) {
      thread.join();
    }
  });
  CHECK_EQ(sum.copy_inner(), 49500);
}
