#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode vec_to_linked_list(vector<int>& nums) {
    ListNode dummy = ListNode(0);
    ListNode* cur = &dummy;
    for (int num : nums) {
        // 用了new会分配到堆内存，函数结束后不会被销毁
        cur->next = new ListNode(num);
        cur = cur->next;
        // 下面写法是分配到栈内存中，不要学！函数结束后可能导致链表无限长
//        ListNode cur_node = ListNode(num);
//        cur->next = &cur_node;
//        cur = cur->next;
    }
    return *dummy.next;
}

void print_list(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}