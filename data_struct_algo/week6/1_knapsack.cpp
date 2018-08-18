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

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
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
