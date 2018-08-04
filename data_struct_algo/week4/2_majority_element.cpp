// Robert T. Casey
// Coursera DSA - week 4
// 2_majority_element.cpp

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;

int get_majority_element(vector<int> &a ) {
  if (a.empty()) return 0;
  if (a.size() == 1) return 1;

  int half_num_elems = a.size() / 2;
  //std::cout << "half_num_elems = " << half_num_elems << std::endl;
  std::map<int, int> m;
  std::map< int, int >::iterator mit;
  for (auto num : a)
  {
	  //std::cout << "Processing num = " << num << std::endl;
	  mit = m.find(num);
	  if (mit != m.end())
	  {
		  ++m[num];
	  }
	  else
	  {
		  m.insert(std::pair< int, int >( num, 1 ));
		  //std::cout << "inserting num = " << num << std::endl;
	  }
  }
  for (auto num : a)
  {
	  if (m[num] > half_num_elems)
	  {
		  return 1;
	  }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a) != 0) << '\n';
}
