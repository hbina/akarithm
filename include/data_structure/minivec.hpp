#pragma once

#include <malloc.h>

namespace aka {

struct header
{
  unsigned int len = 0;
  unsigned int cap = 0;

  header() = delete;

  header(const int len, const int cap)
    : len(len)
    , cap(cap)
  {}
};

template<typename T>
struct minivec
{
  minivec() = default;

  ~minivec()
  {
    (*get_header()).~header();
    for (auto x = 0; x < length(); x++) {
      (*(get_array_ptr() + x)).~T();
    }
    free(get_root_ptr());
  }

private:
  T* ptr = nullptr; // pointer to [header][...Ts]

  const void* get_root_ptr() const
  {
    return static_cast<const void*>(
      static_cast<const header*>(static_cast<void*>(ptr)) - 1);
  }

  void* get_root_ptr()
  {
    return static_cast<void*>(static_cast<header*>(static_cast<void*>(ptr)) -
                              1);
  }

  const header* get_header() const
  {
    return static_cast<const header*>(static_cast<const void*>(ptr)) - 1;
  }

  header* get_header()
  {
    return static_cast<header*>(static_cast<void*>(ptr)) - 1;
  }

  const T* get_array_ptr() const { return ptr; }

  T* get_array_ptr() { return ptr; }

  unsigned int length() const { return get_header()->len; }

  unsigned int capacity() const { return get_header()->cap; }

  void update_length(unsigned int value) { get_header()->len = value; }

  void insert_back(const T& t)
  {
    get_array_ptr()[length()] = t;
    update_length(length() + 1);
  }

public:
  const T& operator[](const int index) const
  {
    return *(get_array_ptr() + index);
  }

  T& operator[](const int index) { return *(get_array_ptr() + index); }

  void push_back(const T& t)
  {
    if (ptr == nullptr) {
      void* new_ptr = malloc(sizeof(header) + sizeof(T));
      ptr = static_cast<T*>(
        (static_cast<void*>(static_cast<header*>(new_ptr) + 1)));
      get_header()->len = 0;
      get_header()->cap = 1;
    } else if (length() == capacity()) {
      unsigned int new_cap = 2 * capacity();
      unsigned int len = length();
      void* new_ptr = realloc(static_cast<void*>(get_header()),
                              sizeof(header) + (new_cap * sizeof(T)));
      ptr = static_cast<T*>(
        (static_cast<void*>(static_cast<header*>(new_ptr) + 1)));
      get_header()->len = len;
      get_header()->cap = new_cap;
    }
    insert_back(t);
  }
};

}
