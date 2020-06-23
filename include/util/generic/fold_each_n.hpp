#pragma once

#include "call_n_acc.hpp"

#include <cassert>
#include <iterator>

namespace akarithm {

template<unsigned int N,
         typename IterTy,
         typename AccTy,
         typename F,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type>
static constexpr auto
fold_each_n(IterTy iter_begin, IterTy iter_end, AccTy acc, const F& f) -> AccTy
{
  while (std::distance(iter_begin, iter_end) >= N && iter_begin != iter_end) {
    acc =
      std::move(call_n_acc(f, acc, iter_begin, std::make_index_sequence<N>{}));
    iter_begin = std::next(iter_begin, N);
  }

  return acc;
}

}
