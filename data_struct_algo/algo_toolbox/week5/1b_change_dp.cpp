// Robert T. Casey
// Coursera DSA - week 5
// 1b_change_dp.cpp
// Problem spec:  Using dynamic programming, find the minimum number of coins to change the input value
// into coins with denominations 1, 3, and 4

#include <iostream>
#include <climits>
#include <vector>

int get_change(int n) {
	
	std::vector< int > C( n + 1, 0 );
	C[0] = 0;
	const int k = 3; // number of coin denominations:  1, 3, 4
	int d[k+1] = { 0, 1, 3, 4 };
	// i = 1, 3, 4
	// C[j] = INT_MAX, if j < 0
	//        0,       if j = 0
	//    min{  1 + C[ j - 4 ] 
	//          1 + C[ j - 3 ] 
	//          1 + C[ j - 1 ]
	for (int j = 1; j <= n; ++j)
	{
		C[j] = 2000000000;
		for (int i = 1; i <= k; ++i)
		{
			if (j >= d[i] && (1 + C[j - d[i]] < C[j]))
			{
				C[j] = 1 + C[j - d[i]];
			}
		}	// end for i
	}	// end for j

	/*for (int p = 0; p < C.size(); ++p)
	{
		std::cout << C[p] << " ";
	}*/
	return C[n];
}	// end get_change

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
