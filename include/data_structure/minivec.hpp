#pragma once

#include <cstdlib>
#include <cstring>
#include <iostream>
namespace aka {

// NOTE: This is not ALWAYS true because C++ standard only says that they must
// be _at least_ that amount of bits.
using u8 = unsigned char;
using u16 = unsigned int;
using u32 = unsigned long int;
using u64 = unsigned long long;
using i8 = char;
using i16 = int;
using i32 = long int;
using i64 = long long;

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

template<typename T, typename S = u32, typename D = i64>
struct minivec
{

  template<typename TI>
  struct iterator_impl
  {
    TI* ptr = nullptr;

  public:
    using value_type = typename aka::minivec<TI>::value_type;
    using difference_type = typename aka::minivec<TI>::difference_type;
    using reference = typename aka::minivec<TI>::reference;

    iterator_impl<TI>& operator+=(const difference_type& n) noexcept
    {
      this->ptr = this->ptr + n;
      return *this;
    }

    iterator_impl<TI> operator+(const difference_type& n) const noexcept
    {
      iterator_impl<TI> result = { this->ptr + n };
      return result;
    }

    iterator_impl<TI>& operator++() noexcept
    {
      this->ptr = this->ptr + 1;
      return *this;
    }

    iterator_impl<TI> operator++(int) noexcept
    {
      this->ptr = this->ptr + 1;
      return *this;
    }

    iterator_impl<TI>& operator-=(const difference_type& n) noexcept
    {
      this->ptr = this->ptr - n;
      return *this;
    }

    iterator_impl<TI> operator-(const difference_type& n) const noexcept
    {
      iterator_impl<TI> result = { this->ptr - n };
      return result;
    }

    iterator_impl<TI>& operator--() noexcept
    {
      this->ptr = this->ptr - 1;
      return *this;
    }

    iterator_impl<TI> operator--(int) noexcept
    {
      this->ptr = this->ptr - 1;
      return *this;
    }

    difference_type operator-(const iterator_impl<TI>& o) const noexcept
    {
      return this->ptr - o.ptr;
    }

    reference operator[](const difference_type& n) const noexcept
    {
      return *(this->ptr + n);
    }

    bool operator==(const iterator_impl<TI>& o) const noexcept
    {
      return (this->ptr == o);
    }

    bool operator!=(const iterator_impl<TI>& o) const noexcept
    {
      return !(this->ptr == o.ptr);
    }

    bool operator<(const iterator_impl<TI>& o) const noexcept
    {
      return !(this->ptr > o);
    }

    bool operator>(const iterator_impl<TI>& o) const noexcept
    {
      return (this->ptr > o);
    }

    bool operator<=(const iterator_impl<TI>& o) const noexcept
    {
      return !(this->ptr >= o);
    }

    bool operator>=(const iterator_impl<TI>& o) const noexcept
    {
      return (this->ptr >= o);
    }

    T& operator*() noexcept { return *this->ptr; }

    const T& operator*() const noexcept { return *this->ptr; }
  };

  template<typename TI>
  using const_iterator_impl = iterator_impl<const TI>;

public:
  // Member types
  using value_type = T;
  // using allocator_type =
  using size_type = S;
  using difference_type = D;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = T*;
  using const_pointer = const T*;
  using iterator = iterator_impl<T>;
  using const_iterator = const_iterator_impl<T>;

  minivec() = default;

  minivec(const minivec& o)
  {
    std::size_t total_bytes = sizeof(header) + (sizeof(T) * o.capacity());
    void* copy_ptr = std::malloc(total_bytes);
    std::memcpy(copy_ptr, o.get_root_ptr(), total_bytes);
    this->ptr =
      static_cast<T*>(static_cast<void*>(static_cast<header*>(copy_ptr) + 1));
  }

  minivec& operator=(const minivec& o)
  {
    if (this != &o) {
      std::free(this->get_root_ptr());
      std::size_t total_bytes = sizeof(header) + (sizeof(T) * o.capacity());
      void* copy_ptr = std::malloc(total_bytes);
      std::memcpy(copy_ptr, o.get_root_ptr(), total_bytes);
      this->ptr =
        static_cast<T*>(static_cast<void*>(static_cast<header*>(copy_ptr) + 1));
    }
    return *this;
  }

  ~minivec()
  {
    (*get_header()).~header();
    for (auto x = 0; x < length(); x++) {
      (*(get_array_ptr() + x)).~T();
    }
    free(get_root_ptr());
  }

private:
  T* ptr = nullptr;

  const void* get_root_ptr() const noexcept
  {
    return static_cast<const void*>(
      static_cast<const header*>(static_cast<void*>(ptr)) - 1);
  }

  void* get_root_ptr() noexcept
  {
    return static_cast<void*>(static_cast<header*>(static_cast<void*>(ptr)) -
                              1);
  }

  const header* get_header() const noexcept
  {
    return static_cast<const header*>(static_cast<const void*>(ptr)) - 1;
  }

  header* get_header() noexcept
  {
    return static_cast<header*>(static_cast<void*>(ptr)) - 1;
  }

  const T* get_array_ptr() const noexcept { return ptr; }

  T* get_array_ptr() { return ptr; }

  unsigned int length() const noexcept { return get_header()->len; }

  unsigned int capacity() const noexcept { return get_header()->cap; }

  void update_length(unsigned int value) noexcept { get_header()->len = value; }

  void insert_back(const T& t) noexcept
  {
    get_array_ptr()[length()] = t;
    update_length(length() + 1);
  }

public:
  const T& operator[](const int index) const noexcept
  {
    return *(get_array_ptr() + index);
  }

  T& operator[](const int index) noexcept { return *(get_array_ptr() + index); }

  void push_back(const T& t) noexcept
  {
    if (ptr == nullptr) {
      void* new_ptr = std::malloc(sizeof(header) + sizeof(T));
      ptr = static_cast<T*>(
        (static_cast<void*>(static_cast<header*>(new_ptr) + 1)));
      get_header()->len = 0;
      get_header()->cap = 1;
    } else if (length() == capacity()) {
      unsigned int new_cap = 2 * capacity();
      unsigned int len = length();
      void* new_ptr = std::realloc(static_cast<void*>(get_header()),
                                   sizeof(header) + (new_cap * sizeof(T)));
      ptr = static_cast<T*>(
        (static_cast<void*>(static_cast<header*>(new_ptr) + 1)));
      get_header()->len = len;
      get_header()->cap = new_cap;
    }
    insert_back(t);
  }

  constexpr iterator begin() noexcept { return iterator{ this->ptr }; }

  constexpr const_iterator cbegin() noexcept
  {
    return const_iterator{ this->ptr };
  }

  constexpr iterator end() noexcept
  {
    return iterator{ this->ptr + this->length() };
  }

  constexpr const_iterator cend() noexcept
  {
    return const_iterator{ this->ptr + this->length() };
  }
};

}
