#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
	if (n <= 1)
	{
		return n;
	}
	else
	{
		int * f_array = new int[n + 1];  // +1 since arrays are 0-based.  
		int result = 0;
		f_array[0] = 0;
		f_array[1] = 1;
		for (int fdx = 2; fdx < n + 1; ++fdx)
		{
			f_array[fdx] = ( f_array[fdx - 1] + f_array[fdx - 2] ) % 10;
		}
		result = f_array[n];
		delete [] f_array;
		return result;
	}
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
	int v = get_fibonacci_last_digit_fast(n);
	//if (c != v)
	//{
	//	std::cout << "Fast results disagree with naive on n = " << n << ", c = " << c << ",v = " << v << std::endl;
	//}
    std::cout << v << '\n';
}
