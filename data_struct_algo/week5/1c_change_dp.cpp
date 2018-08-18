// Robert T. Casey
// Coursera DSA - week 5
// 1c_change_dp.cpp
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


#include <iostream>
#include <algorithm>

int get_change(int k) {
	if (k < 3)
	{
		return k; // just use 1's
    }
	if (k % 4 == 0)
	{
		return k / 4;
	}
	else if (k % 3 == 0)
	{
		return k / 3;
	}
	// Get largest multiple of 4 >= k
	int mul_arry_size = (k / 4) + 2;  // just need ( k / 4 + 1 ) entries, but adding another to account for 
	// fact that we'll be using 1 as starting index.
	int ** mul_arry = new int * [mul_arry_size];  // set up rows (1st column)
	for (int m = 0; m < mul_arry_size; ++m)
	{
		mul_arry[m] = new int[2];	// set up rest of cols
	}
	for (int i = 0; i < mul_arry_size; ++i)
	{
		//std::cout << "i = " << i << std::endl;
		mul_arry[i][0] = 3 * i;
		//std::cout << "mul_arry[i][0] =" << mul_arry[i][0] << std::endl;
		mul_arry[i][1] = 4 * i;
		//std::cout << "mul_arry[i][1] =" << mul_arry[i][1] << std::endl;
	}

	int num_coins[3];
	int start_four_idx = k / 4;
	for (int j = 0; j < 3; ++j)
	{
		// create 3 subsets of coin counts
		// 1) largest 4, 2) 2nd largest 4, 3) 3rd largest 4
		// then fill in the remaining largest 3's and 1's
		int ok = k;
		int four_idx = start_four_idx - j;
		//std::cout << "four_idx = " << four_idx << std::endl;
		//std::cout << "mul_arry[four_idx][1] = " << mul_arry[four_idx][1] << std::endl;
		ok -= mul_arry[four_idx][1];
		//std::cout << "ok is now = " << ok << std::endl;

		int three_idx = ok / 3;
		//std::cout << "three_idx = " << three_idx << std::endl;
		//std::cout << "mul_arry[three_idx][0] = " << mul_arry[three_idx][0] << std::endl;
		ok -= mul_arry[three_idx][0];
		//std::cout << "ok is now = " << ok << std::endl;
		// ok now has remainder

		if (ok < 0)
		{
			ok += 3;
			--three_idx;
		}
		num_coins[j] = four_idx + three_idx + ok;
		//std::cout << "num_coins[" << j << "] = " << num_coins[j] << ", 4 * " << four_idx << " + 3 * " << three_idx << " + " << ok << std::endl;
	}
	return (std::min(num_coins[0], std::min(num_coins[1], num_coins[1])));

 }

int main() {
  int k;
  std::cin >> k;
  std::cout << get_change(k) << '\n';
}
