cmake_minimum_required(VERSION 3.1)
project(akarithm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(
  akarithm
  test/main.cpp
  test/util/string/split.cpp
  test/util/integer/digit_fold.cpp
  test/util/generic/bst_iterator.cpp
  test/util/generic/is_palindrome.cpp
  test/util/generic/zip_fold.cpp
  test/util/generic/preorder_iterator.cpp
  test/util/generic/inorder_iterator.cpp
  test/util/generic/reverse_if.cpp
  test/util/generic/is_number.cpp
  test/util/generic/find_range.cpp
  test/util/generic/set_equality.cpp
  test/util/generic/group_by.cpp
  test/util/generic/group_by_minify.cpp
  test/util/generic/split.cpp
  test/util/generic/zip.cpp
  test/util/generic/sliding_window.cpp
  test/util/generic/bst_search.cpp)

target_include_directories(akarithm PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
