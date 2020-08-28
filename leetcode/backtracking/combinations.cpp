#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static auto combinations(int n, int k) -> vector<vector<int>> {
        vector<vector<int>> res = vector<vector<int>>();
        helper(res, 1, vector<int>(), n, k);
        return res;
    }

private:
    static void helper(vector<vector<int>> res, int start, vector<int> curr, int n, int k) {
        if (curr.size() == k) {
            // Python: res.append(curr.copy)
            res.push_back(curr);
            return;
        }
        for (int i=start; i<=n; i++) {
            curr.push_back(i);
            helper(res, i+1, curr, n, k);
            curr.pop_back();
        }
    }
};

int main() {
    vector<vector<int>> res = Solution::combinations(4, 2);
    cout << res.size() << endl;
    return 0;
}