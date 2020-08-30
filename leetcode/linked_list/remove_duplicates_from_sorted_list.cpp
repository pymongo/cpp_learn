#include <iostream>
#include "linked_list.hpp"

using namespace std;

class Solution {
public:
    static ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        int pre_val = -1;
        while (cur != nullptr) {
            if (cur->val == pre_val) {

            }
            pre_val = cur->val;
            cur = cur->next;
        }
        return head;
    }
};

int main() {
    vector<int> nums = vector<int>{1,1,2,3,3};
    ListNode head = vec_to_linked_list(nums);
    ListNode* cur = &head;
    while (cur != nullptr) {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "NULL" << endl;
    return 0;
}
