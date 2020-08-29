#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    auto static transpose_matrix(vector<vector<int>> &A) -> vector<vector<int>> {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> res;
        for (int j = 0; j < n; j++) {
            vector<int> output_row;
            // C++通过reserve初始化vector的容量
            output_row.reserve(m);
            for (int i = 0; i < m; i++) {
                output_row.push_back(A[i][j]);
            }
            res.push_back(output_row);
        }
        return res;
    }
};

// 感觉可以看看cpp中实现函数式编程他的lambda和rust有点不一样 还有个pipeline技术
int main() {
    vector<vector<int>> input;
    input.push_back(vector<int>{1, 2, 3});
    input.push_back(vector<int>{4, 5, 6});
    vector<vector<int>> output = Solution::transpose_matrix(input);
    vector<int> expected_row_0 = vector<int>{1, 4};
    vector<int> expected_row_1 = vector<int>{2, 5};
    vector<int> expected_row_2 = vector<int>{3, 6};
    assert(output[0] == expected_row_0);
    assert(output[1] == expected_row_1);
    assert(output[2] == expected_row_2);
    return 0;
}