#pragma once

#include <utility>

namespace akarithm {

template<typename F, typename AccTy, typename Iter, std::size_t... Is>
auto
call_n(const F& f, AccTy acc, Iter i, std::index_sequence<Is...>)
{
  return f(acc, *(i + Is)...);
}

}
