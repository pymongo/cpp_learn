#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static string addStrings(string num1, string num2) {
        string res;
        const int m = num1.size();
        const int n = num2.size();
        const int min_m_n = min(m, n);
        const int max_m_n = max(m, n);
        const int max_minus_min = max_m_n - min_m_n;
        int carry = 0;
        for (size_t i = max_m_n; i>max_minus_min; i--) {
            int digit = (num1[i] - '0') + (num2[i] - '0') + carry;
            res.push_back((digit % 10) + '0');
            carry = digit / 10;
        }

        if (m > n) {
            for (size_t i = m-min_m_n; i>0; i--) {
                int digit = (num1[i] - '0') + carry;
                res.push_back((digit % 10) + '0');
                carry = digit / 10;
            }
        } else if (m < n) {
            for (size_t i = n-min_m_n; i>0; i--) {
                int digit = (num2[i] - '0') + carry;
                res.push_back((digit % 10) + '0');
                carry = digit / 10;
            }
        }
        if (carry > 0) {
            res.push_back(carry + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    cout << Solution::addStrings("9", "98") << endl;
//    cout << Solution::addStrings("789", "654") << endl;
//    cout << Solution::addStrings("1", "1") << endl;
    return 0;
}

