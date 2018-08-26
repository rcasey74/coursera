// Robert T. Casey
// Coursera DSA - week 6
// 2_partition3.cpp
// Problem spec:  

#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
