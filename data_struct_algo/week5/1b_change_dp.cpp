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
#include <climits>

int get_change(int n) {

	int * C = new int[n];
	C[0] = 0;
	int * S = new int[n];
	int k = 3;
	int d[] = { 0,1,3,4 };
	
	int min = INT_MAX;
	int coin;
	for (int p = 1; p <= n; ++p)
	{
		for (int i = 1; i <= k; ++i)
		{
			if (1 + C[p - d[i]] < min)
			{
				min = 1 + C[p - d[i]];
				coin = i;
			}
		}
		C[p] = min;
		S[p] = coin;
	}

	std::cout << "C[n] = " << std::endl;
	for (int t = 1; t <= n; ++t)
	{
		std::cout << t << " : " << C[t] << " , ";
		if (t % 20) std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "S[n] = " << S[n] << std::endl;

	return C[n];

	delete[] C;
	delete[] S;
	
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
