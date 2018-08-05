// Robert T. Casey
// Coursera DSA - week 5
// 1_change_dp.cpp
// Problem spec:  Using dynamic programming, find the minimum number of coins to change the input value
// into coins with denominations 1, 3, and 4
// More generally, for a given integer k, we are trying to
// minimize the sum ( a + b + c ),
// where
// a * x + b * y + c * z = k,
// and
// x = 1, y = 3, and z = 4.
// DP: use prior results, plus some intelligent backtracking, etc.
// constraints:  1 <= k <= 1000
// Create integer array of size max_k (1000)
// Carefully fill in the elements left to right
// Return element at index k


#include <iostream>

int get_change(int k) {
	if (k < 3)
	{
		return k; // just use 1's
    }

	// Remaining cases will have either more 3's than 4's or more 4's than 3's or equal # of each
	// so try all 3 cases and choose the one resulting in the minimum s
	int ones[2] = { 0,0 };
	int threes[2] = { 0,0 };
	int fours[2] = { 0,0 };
	int sums[2] = { 0,0 };
	int ok = k;
	//int min_idx = -1;

	// actually just two cases to try:  
	// 1) first divide by 4's, then divide by 3's
	// 2) first divide by 3's, then divide by 4's
	int rem = 0, quotient = 0, count = 0, idx = 0;
	
	quotient = ok / 4;
	fours[idx] = quotient;
	rem = ok % 4;
	//count += quotient;

	ok = rem;
	quotient = ok / 3;
	threes[idx] = quotient;
	rem = ok % 3;
	ones[idx] = rem;
	//count += quotient + rem;	// just add the ones
	sums[idx] = ones[idx] + threes[idx] + fours[idx];
	
	// reset vars
	rem = 0, quotient = 0, count = 0, ok = k, idx = 1;
	quotient = ok / 3;
	threes[idx] = quotient;
	rem = ok % 3;
	//count += quotient;

	ok = rem;
	quotient = ok / 4;
	fours[idx] = quotient;
	rem = ok % 4;
	ones[idx] = rem;
	//count += quotient + rem;
	sums[idx] = ones[idx] + threes[idx] + fours[idx];

	for (int i = 0; i < 2; ++i)
	{
		std::cout << k << " = " << ones[i] << " * 1 + " << threes[i] << " * 3 + " << fours[i] << " * 4." << std::endl;
	}

	if (sums[0] < sums[1])
	{
		std::cout << "Min == sums[0] == " << sums[0] << std::endl;
		return sums[0];
	}
	else
	{
		std::cout << "Min == sums[1] == " << sums[1] << std::endl;
		return sums[1];
	}
 }

int main() {
  int k;
  std::cin >> k;
  std::cout << get_change(k) << '\n';
}
