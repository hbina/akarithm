#pragma once

#include <vector>

namespace aka {

template<typename ResultTy = void, typename IterTy, typename MapFun>
static constexpr auto
map(IterTy iter_begin, IterTy iter_end, const MapFun& map) -> ResultTy
{
  ResultTy result;
  result.reserve(std::distance(iter_begin, iter_end));

  while (iter_begin != iter_end) {
    result.emplace_back(map(*iter_begin));
    iter_begin = std::next(iter_begin);
  }

  return result;
}

}
