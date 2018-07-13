#include <iostream>
#include <vector>
#include <algorithm>

int64_t MaxPairwiseProduct(const std::vector<int>& numbers) {

	int64_t max_product = 0;
	int     n = numbers.size();
	int     max_idx1 = 0;
	int64_t max1 = -1,
   		    max2 = -1;

	if (n == 2) // degenerate condition
	{
		max1 = static_cast< int64_t >(numbers[0]);
		max2 = static_cast< int64_t >(numbers[1]);
		max_product = max1 * max2;
		return max_product;
	}

	for (int i = 0; i < n; ++i)
	{
		if (static_cast< int64_t >(numbers[i]) > max1)
		{
			max_idx1 = i;
			max1 = static_cast< int64_t >(numbers[max_idx1]);
		}   // end if
	}  // end for i

	int max_idx2 = 0;

	for (int j = 0; j < n; ++j)
	{
		if (j != max_idx1 &&
			static_cast< int64_t >(numbers[j]) > max2)
		{
			max_idx2 = j;
			max2 = static_cast< int64_t >(numbers[max_idx2]);
		}  // end if
	}	// end for j

		//std::cout << "max1 = " << max1 << ", max2 = " << max2 << "; ";
	max_product = max1 * max2;
	//std::cout << "Fast max_product = " << max_product << std::endl;
	return max_product;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    int64_t result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
