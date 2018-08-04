// Robert T. Casey
// Coursera DSA - week 3
// 6b_largest_number.cpp

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
	std::cout << "inside largest_number(), a = " << std::endl;
	std::cout << "a.size() = " << a.size() << std::endl;
	
  std::stringstream ss_num;
  string result = "";
  //int max_digit_i = INT_MIN; // creates big issues!
  int max_digit_i = 0;
  ss_num << max_digit_i;
  string max_digit_str = ss_num.str();
  std::cout << "Begin: max_digit_str = " << max_digit_str << std::endl;
  vector<string>::iterator sit = a.begin();

  int count = 0;
  while(sit != a.end())
  {
	  std::cout << "count = " << count << std::endl;
	  int this_int;
	  if (IsGreaterOrEqual( *sit, max_digit_str, this_int ))
	  {
		  max_digit_i   = this_int;
		  ss_num << max_digit_i;
		  max_digit_str = ss_num.str();
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
