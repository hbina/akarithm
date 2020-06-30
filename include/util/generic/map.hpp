#pragma once

#include <vector>

namespace aka {

template<typename ResultTy,
         typename IterTy,
         typename MapFun,
         typename ArgTy = typename std::iterator_traits<IterTy>::value_type>
static constexpr auto
map(IterTy iter_begin, IterTy iter_end, const MapFun& map)
  -> std::conditional_t<std::is_same_v<ResultTy, void>,
                        std::vector<std::invoke_result_t<MapFun, ArgTy>>,
                        ResultTy>
{
  ResultTy result;
  result.reserve(std::distance(iter_begin, iter_end));

  for (auto iter = iter_begin; iter_begin != iter_end; iter++) {
    result.emplace_back(map(*iter));
  }

  return result;
}

}
