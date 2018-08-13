#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2) {
	int len1 = str1.size();
	int len2 = str2.size();
	int ** D = new int *[len1 + 1];
	for (int i = 0; i < len1 + 1; ++i)
	{
		D[i] = new int[len2+1];
	}
	// str1 spans rows (on left), str2 spans columns (above)
	D[0][0] = 0;
	for (int i = 1; i <= len1; ++i)
	{
		D[i][0] = i;
	}
	for (int j = 1; j <= len2; ++j)
	{
		D[0][j] = j;
	}
	for (int r = 1; r <= len1; ++r) //row
	{
		for (int c = 1; c <= len2; ++c) // col
		{
			int o1 = D[r][c-1]+1;
			//  D(i,j) = min(
			//  D(i, j - 1) + 1
			int o2 = D[r-1][c]+1;
			//	D(i - 1, j) + 1
			int o3 = 1000000;
			if (str1[r-1] != str2[c-1])
			{
				//	D(i - 1, j - 1) + 1 if A[i] != B[j]
				o3 = D[r-1][c-1]+1;
			}
			else
			{
				//	D(i - 1, j - 1) if A[i] == B[j]
				o3 = D[r-1][c-1];
			}

			if (o1 < o2)
			{
				// o1 min
				D[r][c] = o1 < o3 ? o1 : o3;
			}
			else
			{
				// o2 min
				D[r][c] = o2 < o3 ? o2 : o3;
			}
		}
	}

	/*std::cout << "D[i][j] matrix:" << std::endl;
	for (int i = 0; i <= len1; ++i)
	{
		for (int j = 0; j <= len2; ++j)
		{
			std::cout << D[i][j] << " ";
		}
		std::cout << std::endl;
	}
*/
	int min_val = D[len1][len2];
	
	for (int d = 0; d <= len1; ++d)
	{
		delete[] D[d];
	}
	delete[] D;

	return min_val;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
