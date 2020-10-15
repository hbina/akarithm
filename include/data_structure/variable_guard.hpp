#pragma once

#include <mutex>
#include <type_traits>

namespace aka {

template<typename T>
struct variable_guard
{
private:
  mutable std::mutex mutex;
  T inner;

public:
  variable_guard()
    : inner{}
  {}

  explicit variable_guard(const T& t)
    : inner(t)
  {}

  template<typename F, typename R = typename std::result_of<F(T)>::type>
  variable_guard<R> map_f(const F& f)
  {
    std::lock_guard<std::mutex> lock(mutex);
    return variable_guard(f(inner));
  }

  template<typename F>
  typename std::invoke_result_t<F, const T&> use(const F& f) const
  {
    std::lock_guard<std::mutex> lock(mutex);
    return f(inner);
  }

  template<typename F>
  typename std::invoke_result_t<F, T&> usem(const F& f)
  {
    std::lock_guard<std::mutex> lock(mutex);
    return f(inner);
  }

  T copy_inner() const
  {
    std::lock_guard<std::mutex> lock(mutex);
    return inner;
  }
};
}
