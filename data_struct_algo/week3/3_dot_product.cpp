// Robert T. Casey
// Coursera DSA - week 3
// 3_dot_product.cpp

// General algorithm
// sort each of the a and b arrays
// if elements < 0, push those into separate sub_arrays

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int num_elems = a.size();
  for (int i = num_elems - 1; i >= 0; --i ) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
