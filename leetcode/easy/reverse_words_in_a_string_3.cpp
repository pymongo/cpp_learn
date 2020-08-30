#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        while (i < n) {
            int start = i;
            // 找到单词分隔的位置
            while (i < n && s[i] != ' ') {
                i++;
            }

            int left = start, right = i-1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            // 跳过连续的空格
            while (i < n && s[i] == ' ') {
                i++;
            }
        }
        return s;
    }
};

int main() {
    cout << Solution::reverseWords("Let's take LeetCode contest") << endl;
    return 0;
}
