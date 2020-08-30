#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

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
    ListNode head = ListNode(1);
    ListNode n2 = ListNode(1);
    head.next = &n2;
    ListNode n3 = ListNode(2);
    n2.next = &n3;
    ListNode n4 = ListNode(3);
    n3.next = &n4;
    ListNode n5 = ListNode(3);
    n4.next = &n5;
//    Solution::deleteDuplicates(&head);
    ListNode* cur = &head;
    while (cur != nullptr) {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "NULL" << endl;
    return 0;
}
