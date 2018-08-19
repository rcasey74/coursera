// Robert T. Casey
// Coursera DSA - week 6
// 3_placing_parentheses.cpp
// Problem spec:  In this problem, your goal is to add parentheses to a given arithmetic
// expression to maximize its value.
// Task: Find the maximum value of an arithmetic expression by specifying the order of applying its arithmetic
// operations using additional parentheses.
// Input Format: The only line of the input contains a string 𝑠 of length 2𝑛 + 1 for some 𝑛, with symbols
// 𝑠0, 𝑠1, . . ., 𝑠2𝑛. Each symbol at an even position of 𝑠 is a digit(that is, an integer from 0 to 9) while
// each symbol at an odd position is one of three operations from{ +,-,*}.
// Constraints: 1 ≤ 𝑛 ≤ 14 (hence the string contains at most 29 symbols).
// Output Format: Output the maximum possible value of the given arithmetic expression among different
// orders of applying arithmetic operations.

#include <iostream>
#include <cassert>
#include <cstring>  // strtok
#include <string>
#include <vector>
#include <cstdlib>	// atoi
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void MinAndMax(int                 i, 
	           int                 j, 
	           long long &         p_min, 
	           long long &         p_max, 
	           long long **        min_arr, 
	           long long **        max_arr, 
	           const std::string & ops )
{
	p_min = LLONG_MAX;
	p_max = LLONG_MIN;
	long long a, b, c, d;
	std::vector< long long > evals; // a slightly cleaner way to do max/min of 5 elements rather than nesting calls to std::max/min
	for (int k = i; k <= j - 1; ++k)
	{
		a = eval(max_arr[i][k], max_arr[k + 1][j], ops[k]); // should ops[k] be ops[k-1]?
		evals.push_back(a);
		b = eval(max_arr[i][k], min_arr[k + 1][j], ops[k]);
		evals.push_back(b);
		c = eval(min_arr[i][k], max_arr[k + 1][j], ops[k]);
		evals.push_back(c);
		d = eval(min_arr[i][k], min_arr[k + 1][j], ops[k]);
		evals.push_back(d);

		evals.push_back(p_min);
		evals.push_back(p_max);
		std::sort(evals.begin(), evals.end());

		p_min = evals.front();
		p_max = evals.back();
	}
}

long long get_maximum_value(const string &exp) {
  
    // 1. Parse the input string into ops and numbers
	std::string ops = "";
	for (int s = 0; s < exp.size(); ++s)
	{
		switch (exp[s])
		{
		case '+':
		case '-':
		case '*':
			ops += exp[s];
			break;
		default:
			break;
		}
	}
	ops += '\0';
	std::cout << "OPS: " << ops << std::endl;

	// Make copy of input string
	char * in_str = const_cast<char*>(exp.c_str());
	std::vector< int > numbers;
	char * num_token = strtok( in_str, "+-*" ) ;
	numbers.push_back(atoi(num_token));
	
	while ( num_token != NULL )
	{
		num_token = strtok(NULL, "+-*");
		if (num_token != NULL)
		{
			numbers.push_back(atoi(num_token));
		}
	}
	std::cout << "After tokenization loop" << std::endl;

	// Test that our parsing works.
	std::cout << "NUMBERS: ";
	for (int i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	
	// Step 2.  Actually solve the problem.
	// We're building two, 2D matrices as we go, for DP approach:
	// Min matrix, Max matrix.
	// Min matrix stores the minimum value of the subexpression, while max stores the opposite.
	int n = numbers.size();
	long long ** mmin = new long long *[n];
	long long ** mmax = new long long *[n];
	for (int i = 0; i < n; ++i)
	{
		mmin[0] = new long long[n];
		mmax[0] = new long long[n];
	}

	// Build up our dp solution from the ground up.
	// Init the diagonal members of the 2 matrices to just the numbers themselves,
	// since j - i == 0 here, no "subexpression" exists beyond just the number itself.
	for (int i = 0; i < n; ++i)
	{
		mmin[i][i] = numbers[i];
		mmax[i][i] = numbers[i];
	}	// end for i

	int j = 0;
	long long eval_min, eval_max;
	for (int s = 0; s < n - 1; ++s)
	{
		for (int i = 0; i < n - s; ++i) // are we going to need n - s -1 in the termination condition?
		{
			j = i + s;

			MinAndMax(i, j, eval_min, eval_max);

			mmin[i][j] = eval_min;
			mmax[i][j] = eval_max;
		}	// end for i
	}	// end for s

	// Save the result
	int result = mmax[0][n-1]; 

	// Cleanup time
	for (int d = 0; d < n; ++d)
	{
		delete[] mmin[d];
		delete[] mmax[d];
	}
	delete[] mmin;
	delete[] mmax;

  return result;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
