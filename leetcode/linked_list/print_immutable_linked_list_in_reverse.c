// https://leetcode.com/problems/print-immutable-linked-list-in-reverse/
#include <stdlib.h>

struct ImmutableListNode {
    struct ImmutableListNode *(*getNext)(struct ImmutableListNode *); // return the next node.
    void (*printValue)(struct ImmutableListNode *); // print the value of the node.
};

void printLinkedListInReverse(struct ImmutableListNode *head) {
    if (head == NULL) {
        return;
    }
    // C没有C++的this，代码略显啰嗦
    printLinkedListInReverse(head->getNext(head));
    head->printValue(head);
}

int main() {
    return 0;
}
