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

// g++ -std=c++11 remove_duplicates_from_sorted_list.cpp linked_list.hpp
int main() {
    vector<int> nums = vector<int>{1,1,2,3,3};
    ListNode head = vec_to_linked_list(nums);
    print_list(&head);
    return 0;
}
