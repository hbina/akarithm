find test/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i
find include/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i