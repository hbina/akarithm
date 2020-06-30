#pragma once

#include <algorithm>
#include <vector>

namespace aka {

template<typename T>
class vector
{

  std::vector<T> data;

public:
  template<typename T2>
  static auto from(std::initializer_list<T2> list) -> aka::vector<T>
  {
    aka::vector<T> result;
    result.data = list;
    return result;
  }

  template<typename F>
  auto map(const F& f) -> aka::vector<T>
  {
    for (T& x : data) {
      x = f(x);
    }
    return *this;
  }

  template<typename F>
  auto filter(const F& f) -> decltype(*this)
  {
    data.erase(std::remove_if(std::begin(data), std::end(data), f),
               std::end(data));
    return *this;
  }

  auto cbegin() const -> typename std::vector<T>::const_iterator
  {
    return std::cbegin(data);
  }

  auto cend() const -> typename std::vector<T>::const_iterator
  {
    return std::cend(data);
  }

  auto begin() const -> typename std::vector<T>::const_iterator
  {
    return std::cbegin(data);
  }

  auto end() const -> typename std::vector<T>::const_iterator
  {
    return std::cend(data);
  }
};

} // namespace aka
