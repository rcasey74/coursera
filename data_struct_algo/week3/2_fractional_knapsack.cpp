#include <iostream>
#include <vector>
#include <algorithm> // sort

using std::vector;

struct WVBucket
{
   int value;
   int weight;
   double opt_val;
};

bool compare( const struct WVBucket & b1, const struct WVBucket & b2  )
{
  return b1.opt_val < b2.opt_val;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  size_t num_elem = weights.size();
  std::vector< struct WVBucket > my_bucket;
  for( int i = 0; i < num_elem; ++i )
  {
    struct WVBucket currBucket;
    currBucket.weight = weights.at( i );
    currBucket.value  = values.at( i );
    currBucket.opt_val = static_cast< double > ( currBucket.value ) / static_cast< double > ( currBucket.weight );
    my_bucket.push_back( currBucket );
  }

  // sorts in ascending order
  // since we want max values first, walk backwards
  std::sort( my_bucket.begin(), my_bucket.end(), compare );

  double remaining_weight = capacity;

  std::vector< struct WVBucket >::reverse_iterator rit = my_bucket.rbegin();

  while( remaining_weight > 0.0 && rit != my_bucket.rend() )
  {
     // take as much of the current element as will fit in the bag
    // which means...take the smaller of the remaining weight in the bag vs. what's in the current element
    double loot_w8 =  ( remaining_weight < rit->weight ) ? remaining_weight : rit->weight;
//    std::cout << "Current loot_w8 = " << loot_w8 << std::endl;
    remaining_weight -= loot_w8;
//    std::cout << "Current remaining_weight = " << remaining_weight << std::endl;
    value += loot_w8 * rit->opt_val;
//    std::cout << "Current value = " << value  << std::endl;
    ++rit;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
