﻿// Robert T. Casey
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
#include <string>   // stoll
#include <vector>
#include <cstdlib>	// atoi
#include <algorithm>  // sort
#include <climits>   // LLONG_MAX, _MIN

using std::vector;
using std::string;
using std::max;
using std::min;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MinAndMax(int                 i,
	           int                 j, 
	           long long &         p_min, 
	           long long &         p_max, 
	           long long **        min_arr, 
	           long long **        max_arr, 
	           const std::string & ops )
{
	p_min       = LLONG_MAX;  // basically + infinity
	p_max       = LLONG_MIN;  // basically - infinity
	long long a = 0,
			  b = 0,
			  c = 0,
			  d = 0;

	std::vector< long long > eval_arr; // a slightly cleaner way to do max/min of 5 elements rather than nesting calls to std::max/min
	for (int k = i; k <= j - 1; ++k)
	{
//		std::cout << "MinAndMax() k = " << k      << std::endl;
//		std::cout << "op_k = "          << ops[k] << std::endl;

		a = eval(max_arr[i][k], max_arr[k + 1][j], ops[k]); // should ops[k] be ops[k-1]?
//		std::cout << "a = " << a << std::endl;
		eval_arr.push_back(a);

		b = eval(max_arr[i][k], min_arr[k + 1][j], ops[k]);
		eval_arr.push_back(b);
//		std::cout << "b = " << b << std::endl;

		c = eval(min_arr[i][k], max_arr[k + 1][j], ops[k]);
		eval_arr.push_back(c);
//		std::cout << "c = " << c << std::endl;

		d = eval(min_arr[i][k], min_arr[k + 1][j], ops[k]);
		eval_arr.push_back(d);
//		std::cout << "d = " << d << std::endl;

		std::sort(eval_arr.begin(), eval_arr.end());

		long long min_alpha = eval_arr.front(),
		          max_alpha = eval_arr.back();

//		if( min_alpha >= max_alpha )
//		{
//			std::cout << "min_alpha >= max_alpha: " << min_alpha << " >= " << max_alpha << std::endl;
//		}

		p_min = min_alpha < p_min ? min_alpha : p_min;
		p_max = max_alpha > p_max ? max_alpha : p_max;

//		std::cout << "At end of MinAndMax(), p_min = " << p_min << " and p_max = " << p_max << std::endl;

		eval_arr.clear();  // Key step!  otherwise all kind of gunk builds up
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long get_maximum_value( string & exp) {
  
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
//	ops += '\0';
//	std::cout << "Operators: [" << ops << "]" << std::endl;

	// Make copy of input string
	char * in_str = new char [ exp.length() + 1 ];
    std::strncpy( in_str, exp.c_str(), exp.length() );

	std::vector< long long > numbers;
	char * num_token = strtok( in_str, "+-*" );
	std::string curr_num( num_token );
	numbers.push_back( std::stoll( static_cast< const std::string & >(curr_num)));
	
	while ( num_token != NULL )
	{
		num_token = strtok(NULL, "+-*");
		if (num_token != NULL)
		{
//			numbers.push_back( atoi(num_token));  // fine for integers
			curr_num = num_token;
			numbers.push_back( std::stoll( static_cast< const std::string & >(curr_num)));  // but we need for long long!
		}
		curr_num.clear();
	}
//	std::cout << "After tokenization loop" << std::endl;

	// Test that our parsing works.
//	std::cout << "NUMBERS: ";
//	for (int i = 0; i < numbers.size(); ++i)
//	{
//		std::cout << numbers[i] << " ";
//	}
//	std::cout << std::endl;
//
	// Step 2.  Actually solve the problem.
	// We're building two, 2D matrices as we go, for DP approach:
	// Min matrix, Max matrix.
	// Min matrix stores the minimum value of the subexpression, while max stores the opposite.
	int n = numbers.size();
	long long ** mmin = new long long *[n];
	long long ** mmax = new long long *[n];
	for (int i = 0; i < n; ++i)
	{
		mmin[i] = new long long[n];
		mmax[i] = new long long[n];
	}

	// Build up our dp solution from the ground up.
	// Init the diagonal members of the 2 matrices to just the numbers themselves,
	// since j - i == 0 here, no "subexpression" exists beyond just the number itself.
	// Init remaining members to 0
//	std::cout << "Initial value of Min and Max matrices: " << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for( int j = 0; j < n; ++j )
		{
			if( i == j )  // This is the most important step:  init the diagonals to be the digits themselves.
			{
				mmin[i][j] = numbers[i];
	  			mmax[i][j] = numbers[i];
			}
			else
			{
				mmin[i][j] = 0;
				mmax[i][j] = 0;
			}
//            std::cout << mmin[i][j] << " ";
		}  // end for j
//		std::cout << std::endl;
	}	// end for i


	// These next loops must proceed carefully: starting at the main diagonal (i.e. i == j ) and then moving outwards ( i != j )
	int       j        = 0;
	long long eval_min = 0,
			  eval_max = 0;

	for (int s = 0; s < n - 1; ++s)
	{
		for (int i = 0; i <= n - ( s + 2 ); ++i) // n - ( s + 2 ) ensures that i starts at the 2nd-to-last index and ends at the first index (0)
		{
			j = i + s + 1;

			MinAndMax(i, j, eval_min, eval_max, mmin, mmax, ops);

			mmin[i][j] = eval_min;
			mmax[i][j] = eval_max;
		}	// end for i
	}	// end for s

//	std::cout << "Final values of Max array: " << std::endl;
//	for( int r = 0; r < n; ++r )
//	{
//		for( int c = 0; c < n; ++c )
//		{
//			std::cout << mmax[r][c] << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << "Final values of Min array: " << std::endl;
//	for( int r = 0; r < n; ++r )
//	{
//		for( int c = 0; c < n; ++c )
//		{
//			std::cout << mmin[r][c] << " ";
//		}
//		std::cout << std::endl;
//	}

	// Save the result
	long long result = mmax[0][n-1];

	// Cleanup time
	for (int d = 0; d < n; ++d)
	{
		delete[] mmin[d];
		delete[] mmax[d];
	}
	delete[] mmin;
	delete[] mmax;

	delete [] in_str;

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
