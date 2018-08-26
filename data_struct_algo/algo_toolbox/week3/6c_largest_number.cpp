// Robert T. Casey
// Coursera DSA - week 3
// 6c_largest_number.cpp

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using std::vector;
using std::string;

bool IsGreaterOrEqual(string a, string b, int & max_i)
{
	std::cout << "IGE input a = " << a << ", b = " << b << std::endl;
	string ab_s = a + b;
	string ba_s = b + a;
	std::cout << "IGE ab_s = " << ab_s << ", ba_s = " << ba_s << std::endl;
	std::string::size_type sz;
	int ab_i = std::stoi(ab_s, &sz);
	int ba_i = std::stoi(ba_s, &sz);
	std::cout << "ab_i = " << ab_i << ", ba_i = " << ba_i << std::endl;
	if (ab_i > ba_i)
	{
		std::cout << "IGE: Greater than result" << std::endl;
		max_i = ab_i;
		return true;
	}
	else
	{
		std::cout << "IGE: Less than result" << std::endl;
		return false;
	}
}

string largest_number(vector<string> a) {
	if (a.size() == 1)
	{
		return a[0];
	}

	std::cout << "inside largest_number(), a = " << std::endl;
	std::cout << "a.size() = " << a.size() << std::endl;

	// init...need to init max_digit to something reasonable
	std::stringstream ss_num1, ss_num2;
	std::string::size_type sz;
	ss_num1 << a[0];
	ss_num2 << a[1];
	int i1 = std::stoi( ss_num1.str(), &sz);
	int i2 = std::stoi( ss_num2.str(), &sz);
	int max_digit_i = 0;
	string result = "";
	string max_digit_str = "";
	if (i1 > i2)
	{
		max_digit_i = i1;
		result += ss_num1.str();
		max_digit_str = ss_num1.str();
		a.erase(a.begin());
	}
	else
	{
		max_digit_i = i2;
		result += ss_num2.str();
		max_digit_str = ss_num2.str();
		a.erase(a.begin()+1);
	}
		
	std::cout << "Init: result = " << result << std::endl;
	vector<string>::iterator sit = a.begin() + 1;

  int count = 0;
  while (!a.empty())
  {
	  while (sit != a.end())
	  {
		  std::cout << "count = " << count << std::endl;
		  int this_int;
		  if (IsGreaterOrEqual(*sit, max_digit_str, this_int))
		  {
			  max_digit_i = this_int;
			  ss_num1 << max_digit_i;
			  max_digit_str = ss_num1.str();
			  result += max_digit_str;
			  std::cout << "Result is now: " << result << std::endl;
			  sit = a.erase(sit);
		  }
		  else
		  {
			  std::cout << "hit else condition" << std::endl;
			  ++sit;
		  }
		  ++count;
	  }
	  if( !a.empty() ) sit = a.begin();
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
  
  std::cout << "Final result = ";
  std::cout << largest_number(a);
}
