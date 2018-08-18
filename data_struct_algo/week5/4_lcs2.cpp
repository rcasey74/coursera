// Robert T. Casey
// Coursera DSA - week 5
// 4_lcs2.cpp
// Problem statement:
// Compute the length of a longest common subsequence of two subsequences.
// (LCS) - basis of diff
// Inspiration for module solution:  https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// I adapted this solution by making mine move forward in the array instead of backwards,
// with the base case being advancing to one past the end of the array instead of the beginning.

#include <iostream>
#include <vector>
#include <algorithm> // std::max

using std::vector;

int lcs2(vector<int> &a, vector<int> &b, int adx, int bdx ) {
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

  std::cout << lcs2(a, b, 0, 0) << std::endl;
}
