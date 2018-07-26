// Robert T. Casey
// Coursera DSA - week 4
// 1_binary_search.cpp

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search( const vector<int> & a,
				   int left, 
	               int right,
	               int x) 
{
	// there needs to be  a check for left <= right
	if (left <= right)
	{
		int mid = left + (right - 1) / 2;
		/*std::cout << "left = " << left;
		std::cout << ", mid = " << mid;
		std::cout << ", right = " << right << std::endl;
*/
		if (a.at(mid) == x)  // Base case
		{
			return mid;
		}
		else // Recursive cases
		{
			if (x < a.at(mid))
			{
				return binary_search(a, left, mid - 1, x); // left
			}
			else
			{
				return binary_search(a, mid + 1, right, x); // right
			}
		}
	}  // end if left <= right
	// Failure case: value does not exist in array
	return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
	std::cout << binary_search(a, 0, a.size() - 1, b[i]) << ' ';
    //std::cout << linear_search(a, b[i]) << ' ';
  }
}
