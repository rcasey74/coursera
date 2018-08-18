// Robert T. Casey
// Coursera DSA - week 6
// 1_knapsack.cpp
// Problem spec:  Discrete knapsack, without repetitions.
// You are given a set of bars of gold and your goal is to take as much gold as possible into
// your bag. There is just one copy of each bar and for each bar you can either take it or not.
// Task:  Given 𝑛 gold bars, find the maximum weight of gold that fits into a bag of capacity 𝑊.
// Input Format:  The first line of the input contains the capacity 𝑊 of a knapsack and the number 𝑛 of bars
// of gold.The next line contains 𝑛 integers 𝑤0, 𝑤1, . . ., 𝑤𝑛−1 defining the weights of the bars of gold.
// Constraints:   1 ≤ 𝑊 ≤ 10^4; 1 ≤ 𝑛 ≤ 300; 0 ≤ 𝑤0, . . ., 𝑤𝑛−1 ≤ 10^5.
// Output Format:  Output the maximum weight of gold that fits into a knapsack of capacity 𝑊.

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

bool DecreaseOrderCompare(int i, int j)
{
	return i > j;	
}

int optimal_weight(int W, const vector<int> &w) {

  // Seems like a wise solution will involve sorting the bars first.
  //std::sort(w.begin(), w.end(), DecreaseOrderCompare);
  // List is now in decreasing order

  // Just in case:  erase those elements > W, since we can never add those to the knapsack
  // meh:  the input is const...cannot delete the elements
  //while ( !w.empty() && *(w.begin()) > W )
  //{
	 // w.erase( w.begin() );
  //}
  int n = static_cast< int >(w.size());

  // Set up a value matrix, which iterates
  // over rows from i = 1 to n (basically the number of items), and
  // over cols from w = 1 to W, where w is the size of the current knapsack under consideration

  int ** val_mat = new int *[n+1];
  for (int r = 0; r < n + 1; ++r)
  {
	  val_mat[r] = new int[W+1];
  }
  
  // Init the first row and column to zero
  for (int r = 0; r < n + 1; ++r)
  {
	  val_mat[r][0] = 0;
  }
  for (int c = 0; c < W + 1; ++c)
  {
	  val_mat[0][c] = 0;
  }

  //-------------------------------
  // actual code that does stuff
  int t_val = 0;
  for (int i = 1; i <= n; ++i) // current number of items
  {
	  for (int curr_w = 1; curr_w <= W; ++curr_w)  // current trial weight of knapsack
	  {
		  val_mat[i][curr_w] = val_mat[i - 1][curr_w];
		  if (w.at(i-1) <= curr_w)
		  {
			  t_val = val_mat[i - 1][curr_w - w.at(i-1)] + w.at(i-1);
			  if (t_val > val_mat[i][curr_w])
			  {
				  val_mat[i][curr_w] = t_val;
			  }
		  }
	  }	// end for w
  }	// end for i
  
  //-------------------------------
  // done - grab the max value
  int max_val = val_mat[n][W];

  // free resources
  for (int d = 0; d < n + 1; ++d)
  {
	  delete[] val_mat[d];
  }
  delete[] val_mat;

  return max_val;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
