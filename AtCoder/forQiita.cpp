#include <algorithm>
#include <iostream>

int main(void) {
  int arr[] = {4, 4, 7, 2, 3, 1};

  auto max_arr = std::max_element(std::begin(arr), std::end(arr));
  std::cout << *max_arr << std::endl;

  auto min_arr = std::min_element(std::begin(arr), std::end(arr));
  std::cout << *min_arr << std::endl;
}