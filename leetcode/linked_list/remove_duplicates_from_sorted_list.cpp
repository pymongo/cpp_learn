#include <iostream>
#include "linked_list.hpp"

using namespace std;

class Solution {
public:
    static ListNode *deleteDuplicates(ListNode *head) {
        // dummy的值一定不能与链表中的任意值重复
        auto *dummy = new ListNode(-1024);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = dummy->next;
        while (cur) {
            if (cur->val == pre->val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }

    // 遇到重复的就全删掉
    static ListNode* deleteDuplicates2(ListNode* head) {
        auto *dummy = new ListNode(-1024);
        dummy->next = head;
        ListNode *pre = dummy;
        while (pre && pre->next) {
            ListNode* cur = pre->next;
            // 如果cur是链表尾巴 或 cur不是重复值
            if (!cur || !cur->next || cur->next->val != cur->val) {
                pre = cur;
                continue;
            }
            // 将cur前移到重复元素的最后一项
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            pre->next = cur->next;
        }
        return dummy->next;
    }
};

// g++ -std=c++11 remove_duplicates_from_sorted_list.cpp linked_list.hpp
int main() {
    vector<int> nums = vector<int>{1, 1, 2, 3, 3};
    ListNode head = vec_to_linked_list(nums);
    ListNode *output = Solution::deleteDuplicates2(&head);
    print_list(output);
    return 0;
}
