#include <iostream>
#include <vector>
#include <boost/math/statistics/univariate_statistics.hpp>

using std::cout;
using boost::math::statistics::mean;

int main() {
    std::vector<int> nums{1,2,3,4,5};
    cout << mean(nums.begin(), nums.end()) << std::endl;
    return 0;
}