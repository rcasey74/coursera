#include <iostream>
#include <vector>
#include <memory>

using std::vector;

int merge(vector<int> & arr, int low, int mid, int high)
{
	int i, j, k, num_inv = 0;
	int n1 = mid - low + 1;
	int n2 = high - mid;

	std::unique_ptr< int[] > L(new int[n1]());
	std::unique_ptr< int[] > R(new int[n2]());

	for (i = 0; i < n1; ++i)
	{
		L[i] = arr[low + i];
	}
	for (j = 0; j < n2; ++j)
	{
		R[j] = arr[mid + j + 1];
	}
	i = 0, j = 0, k = low;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			arr[k] = L[i];
			++i;
		}
		else
		{
			arr[k] = R[j];
			++j;
			++num_inv;
		}
		++k;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		++i;
		++k;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		++j;
		++k;
	}
	return num_inv;
}

int mergesort(vector<int> & arr, int low, int high)
{
	int num_inv = 0;
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		num_inv = merge(arr, low, mid, high);
	}
	return num_inv;
}

long long get_number_of_inversions(vector<int> &a) {
	//std::cout << "inside get_number_of_inversions" << std::endl;
  long long number_of_inversions = mergesort( a, 0, a.size() - 1 );
  /*for (int i = 0; i < a.size(); ++i)
  {
	  std::cout << a[i] << ", ";
  }
  std::cout << std::endl;*/
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
   std::cout << get_number_of_inversions(a) << '\n';
}
