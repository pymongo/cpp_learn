#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> // for_each

//using namespace std;
/*
C/C++多个源文件的函数/变量的链接方式(linkage):
1. external: 常用于FFI或C引用第三方库API
2. internal:
    a.c源文件内定义的`static int num`和b.c源文件内定义的`static int num`是两个不同的变量，并且只能在相应的源文件内使用
    static变量默认情况下是internal link
    ```c
    // a.c
    int a;
    static int b=1;
    ```
    上述a.c文件中int a;虽然没加static,但是实际存储上是auto自动推断存储类
    会被自动推断成static存储在可执行文件的数据区
    但是这个int a;就只能是internal链接，属于单个文件的static全局变量
    register存储类型要占据CPU一个宝贵的寄存器，有的编译器甚至不允许这么做，一般不怎么用
3. no linkage: 函数作用域内定义的临时变量，没有任何链接
*/
using std::cout;
using std::ostream;
using std::vector;
using std::for_each;

// linked_list.hpp
struct ListNode {
    int val;
    ListNode *next;
    // [What does a colon following a C++ constructor name do? - initialization list](https://stackoverflow.com/questions/1272680/what-does-a-colon-following-a-c-constructor-name-do)
    explicit ListNode(int x)
        : val(x)
        , next(nullptr) {}
    // move constructor，相关知识shallow_copy, bitwise_copy
    /*
    MyClass obj1;
    MyClass obj2;
    obj1 = obj2; // 如果这里是shallow_copy，obj1和obj2可能会有同一个成员字段指向相同的内存地址，如果obj1被析构，则obj2的指针指向的内存就是未定义的内存
    解决方案，重载MyClass的=操作符，使之的行为成为clone，使得obj1=obj2会变成obj1=obj2.clone()
    如果写成`MyClass obj2 = obj1`则编译器会去找copy constructor
    */
    ListNode(vector<int> &&nums) {
        ListNode dummy = ListNode(-1);
        ListNode* curr = &dummy;
        for (auto num : nums) {
            // 用了new会分配到堆内存，函数结束后不会被销毁
            curr->next = new ListNode(num);
            curr = curr->next;
            /* 下面写法会将链表节点分配到栈内存中，会有内存错误！链表节点必须分配到堆内存中才能保证return ListNode时链表后面的节点不会被free
            ListNode new_node = ListNode(num);
            cur->next = &new_node;
            cur = cur->next; */
        }
        this->val = dummy.next->val;
        this->next = dummy.next->next;
        // vector is free because RAII
    }
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
