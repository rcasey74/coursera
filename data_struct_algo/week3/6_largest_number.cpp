// Robert T. Casey
// Coursera DSA - week 3
// 6_largest_number.cpp

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  
	// Basic algorithm:  turn each string into an integer
	// so you have a vector of integers
	// sort that
	// dump it back into a string....in reverse (since sort does in ascending order)
	// done

	std::string::size_type sz;
	std::vector< int > numbers;
	int num_elems = a.size();
	//std::cout << "Adding numbers to int array:" << std::endl;
	for (int sdx = 0; sdx < num_elems; ++sdx)
	{
		int new_num = std::stoi(a.at(sdx), &sz);
		//std::cout << new_num << " ";
		numbers.push_back(new_num);
	}
	//std::cout << std::endl;
	
	std::sort(numbers.begin(), numbers.end());
	//std::cout << "Sorted numbers:" << std::endl;
	/*for (int n = 0; n < numbers.size(); ++n)
	{
		std::cout << numbers.at(n) << " ";
	}*/
	//std::cout << std::endl;

  std::stringstream ss_num;
  string result;
  for (std::vector< int >::reverse_iterator rit = numbers.rbegin();
	  rit != numbers.rend(); 
	  ++rit )
  {
	  ss_num << *rit;
	  result += ss_num.str();
	  ss_num.str("");  // reset
  }
	
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
