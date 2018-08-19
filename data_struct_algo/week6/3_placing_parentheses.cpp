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
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
