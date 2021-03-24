#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> // for_each

using namespace std;

// linked_list.hpp
struct ListNode {
    int val;
    ListNode *next;
    // [What does a colon following a C++ constructor name do? - initialization list](https://stackoverflow.com/questions/1272680/what-does-a-colon-following-a-c-constructor-name-do)
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode()
};

// impl std::fmt::Debug for ListNode
ostream& operator<<(ostream& stdout, const ListNode& list_node) {
    //target << source.val;
    return stdout;
}

ListNode vec_to_linked_list(vector<int>& nums) {
    ListNode dummy = ListNode(-1);
    ListNode* curr = &dummy;
    for (int num : nums) {
        // 用了new会分配到堆内存，函数结束后不会被销毁
        curr->next = new ListNode(num);
        curr = curr->next;
        /* 下面写法是分配到栈内存中，不要学！函数结束后可能导致链表无限长
        ListNode new_node = ListNode(num);
        cur->next = &new_node;
        cur = cur->next;
        */
    }
    return *dummy.next;
}

vector<int> linked_list_to_vec(ListNode* head) {
    vector<int> nums;
    ListNode* curr = head;
    while (curr != nullptr) {
        nums.push_back(curr->val);
        curr = curr->next;
    }
    for_each(begin(nums), end(nums), [](int num) {
        cout << num << "<-";
    });
    return nums;
}

int main() {
    printf("1231321312312323\n");
}
