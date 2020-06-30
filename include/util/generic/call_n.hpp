#pragma once

#include <utility>

namespace aka {

template<typename F, typename AccTy, typename Iter, std::size_t... Is>
static constexpr auto
call_n(const F& f, AccTy acc, Iter i, std::index_sequence<Is...>)
{
  return f(acc, *(i + Is)...);
}

}
