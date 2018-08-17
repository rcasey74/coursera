// Robert T. Casey
// Coursera DSA - week 5
// 4_lcs2.cpp
// Problem statement:
// Compute the length of a longest common subsequence of two subsequences.
// (LCS) - basis of diff
// Inspiration for module solution:  https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// version a:  recursive solution
// version b:  iterative, with dp sol'n

#include <iostream>
#include <vector>
#include <algorithm> // std::max

using std::vector;

int lcs2(vector<int> &a, vector<int> &b ) {
	
	// Base case of recursion:  we're one past the end of one of the arrays
	// and so no more elements available to handle
	if (adx == a.size() || bdx == b.size() )
	{
		return 0;
	}
	if (a.at(adx) == b.at(bdx)) // compare current indices for each array
	{
		// Last elements line up: just move forward in both arrays
		return 1 + lcs2(a, b, adx + 1, bdx + 1);
	}
	else
	{
		// Last elements mismatch: try moving forward one step in just one of the arrays
		// And compare the 2 options, i.e. moving forward in a versus fwd in b.
		return std::max(lcs2(a, b, adx, bdx + 1), lcs2(a, b, adx + 1, bdx));
	}

	int a_size = a.size(),
		b_size = b.size();
	
	int ** LCS = new int *[a_size + 1];
	for (int i = 0; i < a_size + 1; ++i)
	{
		LCS[i] = new int[b_size + 1];
	}

	// Init:  all the 0 indices will have 0 value, since the "length" of the common subsequence has to be 0.
	for (int adx = 0; adx < a_size; ++adx)
	{
		LCS[adx][0] = 0;
	}
	for (int bdx = 0; bdx < b_size; ++bdx)
	{
		LCS[0][bdx] = 0;
	}

	for (int adx = 1; adx <= a_size; ++adx)
	{
		for (int bdx = 1; bdx <= b_size; ++bdx)
		{
			if (a.at(adx) == b.at(bdx) )  // match, just add one to the previous LCS
			{
				LCS[adx][bdx] = 1 + LCS[adx - 1][bdx - 1];
			}
			else
			{
				// No match, try moving backwards one in one of the arrays, try both options and compare results
				LCS[adx][bdx] = std::max(LCS[adx - 1][bdx], LCS[adx][bdx - 1]);
			}
		}
	}
	int result = LCS[a_size][b_size];
	
	// Cleanup, sans destructor
	for (int d = 0; d <= a_size; ++d)
	{
		delete[] LCS[d];
	}
	delete[] LCS;

	return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
