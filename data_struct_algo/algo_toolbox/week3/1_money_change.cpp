// Robert T. Casey
// Coursera DSA - week 3
// 1_money_change.cpp
// Problem spec:  find the minimum number of coins to change the input value
// into coins with denominations 1, 5, and 10

#include <iostream>

int get_change(int m) {

  int rem = 0, quotient = 0, count = 0;

  // Determine how many 10's present
  quotient = m / 10;
  rem      = m % 10;
  count    += quotient;

  // Determine how many 5's present (will always be 0 or 1: 2x 5's covered by one 10.
  m = rem;
  quotient = m / 5;
  rem      = m % 5;
  count    += quotient + rem;

  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
