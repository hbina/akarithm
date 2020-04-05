cmake_minimum_required (VERSION 3.1)
project (akarithm)

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
    
    src/main.cpp
    
    src/util/string/split.cpp

    src/util/integer/digit_fold.cpp

    src/util/generic/bst_iterator.cpp
    src/util/generic/is_palindrome.cpp
    src/util/generic/zip_accumulate.cpp
    src/util/generic/preorder_iterator.cpp
    src/util/generic/inorder_iterator.cpp
    src/util/generic/reverse_if.cpp
    src/util/generic/is_number.cpp
    src/util/generic/find_range.cpp
    src/util/generic/set_equality.cpp
    src/util/generic/group_by.cpp
    src/util/generic/group_by_minify.cpp
    src/util/generic/split.cpp
    src/util/generic/zip.cpp
    src/util/generic/sliding_window.cpp
    src/util/generic/bst_search.cpp
    
    src/akarithm/problem_1.cpp
    src/akarithm/problem_4.cpp
    src/akarithm/problem_5.cpp
    src/akarithm/problem_14.cpp
    src/akarithm/problem_13.cpp
    src/akarithm/problem_18.cpp
    src/akarithm/problem_19.cpp
    src/akarithm/problem_21.cpp
    src/akarithm/problem_22.cpp
    src/akarithm/problem_24.cpp
    src/akarithm/problem_26.cpp
    src/akarithm/problem_27.cpp
    src/akarithm/problem_28.cpp
    src/akarithm/problem_30.cpp
    src/akarithm/problem_31.cpp
    src/akarithm/problem_33.cpp
    src/akarithm/problem_34.cpp
    src/akarithm/problem_35.cpp
    src/akarithm/problem_36.cpp
    src/akarithm/problem_38.cpp
    src/akarithm/problem_81.cpp
    src/akarithm/problem_121.cpp
    src/akarithm/problem_122.cpp
    src/akarithm/problem_394.cpp
    src/akarithm/problem_105.cpp
    src/akarithm/problem_107.cpp
    src/akarithm/problem_145.cpp
    src/akarithm/problem_117.cpp
    src/akarithm/problem_173.cpp
    src/akarithm/problem_160.cpp
    src/akarithm/problem_203.cpp
    src/akarithm/problem_88.cpp
    src/akarithm/problem_206.cpp
    src/akarithm/problem_226.cpp
    src/akarithm/problem_264.cpp
    src/akarithm/problem_297.cpp
    src/akarithm/problem_344.cpp
    src/akarithm/problem_345.cpp
    src/akarithm/problem_371.cpp
    src/akarithm/problem_494.cpp
    src/akarithm/problem_535.cpp
    src/akarithm/problem_536.cpp
    src/akarithm/problem_537.cpp
    src/akarithm/problem_557.cpp
    src/akarithm/problem_589.cpp
    src/akarithm/problem_643.cpp
    src/akarithm/problem_653.cpp
    src/akarithm/problem_700.cpp
    src/akarithm/problem_888.cpp
    src/akarithm/problem_905.cpp
    src/akarithm/problem_897.cpp
    src/akarithm/problem_929.cpp
    src/akarithm/problem_938.cpp
    src/akarithm/problem_106.cpp
    src/akarithm/problem_889.cpp
    src/akarithm/problem_965.cpp
    src/akarithm/problem_977.cpp
    src/akarithm/problem_1010.cpp
    src/akarithm/problem_1029.cpp
    src/akarithm/problem_1051.cpp
    src/akarithm/problem_1281.cpp
    src/akarithm/problem_1221.cpp
    src/akarithm/problem_1282.cpp
    src/akarithm/problem_1038.cpp
    src/akarithm/problem_1283.cpp
    src/akarithm/problem_1290.cpp
    src/akarithm/problem_1304.cpp
    src/akarithm/problem_1305.cpp
    src/akarithm/problem_1332.cpp
    src/akarithm/problem_1337.cpp
    src/akarithm/problem_1338.cpp
    src/akarithm/problem_1339.cpp
    src/akarithm/problem_1346.cpp
)

target_include_directories(akarithm PRIVATE ${CMAKE_SOURCE_DIR}/doctest)
target_include_directories(akarithm PRIVATE ${CMAKE_SOURCE_DIR}/fmt)
