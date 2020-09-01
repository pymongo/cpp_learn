#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static string addStrings(string num1, string num2) {
        string res;
        int i = (int)num1.size()-1, j = (int)num2.size()-1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int curr_digit = x + y + carry;
            carry = curr_digit / 10;
            res.push_back((curr_digit % 10) + '0');
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    cout << Solution::addStrings("9", "98") << endl;
    // 1443
    cout << Solution::addStrings("789", "654") << endl;
    return 0;
}

