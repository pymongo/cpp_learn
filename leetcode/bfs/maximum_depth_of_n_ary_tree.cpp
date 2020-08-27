#include <iostream>
#include <utility> /* move */
#include <vector>
#include <deque>

using namespace std;

// N叉树节点
class Node {
public:
    int val;
    vector<Node *> children;


    // TODO QA.1 为什么要留一个无参构造方法？我记得在Java里，如果重载了构造方法，定义一个无参构造方法是为了防止隐式super调用父类的构造方法时报错
    // Node() = default;

    // https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
    // prefixing explicit keyword to single argument constructor prevents the compiler from using that constructor for implicit conversions.
    // 一个入参的构造方法前要加上explicit的作用: 例如有个函数是foo(Node)，有一处调用是foo(1)，
    // 如果不加explicit编译器会调用Node(int)构造方法去将1强制转换为Node实例对象，造成UB
    explicit Node(int _val) {
        this->val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        this->val = _val;
        this->children = move(_children);
    }
};

// Runtime: 28 ms, faster than 98.84% of C++ online submissions for Maximum Depth of N-ary Tree.
class Solution {
public:
    // 搞不懂leetcode上的解答模板为什么那么喜欢用instance的函数，用static不好吗？可能是历史遗留问题吧，Rust的leetcode模板是用association function，而Go就直接是一个函数了
    // 类似Python的typehint，这个 -> int写不写都对编译结果没有影响
    static auto maxDepth(Node *root) -> int {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        deque<Node *> queue = deque<Node *>();
        queue.push_back(root);
        queue.push_back(nullptr);
        while (!queue.empty()) {
            Node *node = queue.front();
            queue.pop_front();
            if (node == nullptr) {
                depth++;
                if (queue.empty()) {
                    break;
                }
                queue.push_back(nullptr);
                continue;
            }
            // auto 可以理解为C++的自动类型推断(Type inference)，C++20版又新增一些自动类型推断的支持
            // for (Node* child_node : node->children) {
            for (auto child_node : node->children) {
                queue.push_back(child_node);
            }
        }
        return depth;
    }
};

struct ListNode {
    int val;
    ListNode *next;
};

int main() {
    ListNode head = ListNode{.val=1, .next=NULL};
    ListNode *head_ptr = &head;
//    ListNode& head_ref = head;
//    free(head_ptr);

    Node a = Node(1);
    Node *a_ptr = &a;
    Node &a_ref = a;
    cout << Solution::maxDepth(a_ptr) << endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // TODO 结构体的构造方法?
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

auto binary_tree_max_depth(TreeNode *root) -> int {
    if (root == nullptr) {
        return 0;
    }
    int depth = 0;
    deque<TreeNode *> queue = deque<TreeNode *>();
    queue.push_back(root);
    queue.push_back(nullptr);
    while (!queue.empty()) {
        TreeNode *node = queue.front();
        queue.pop_front();
        if (node == nullptr) {
            depth++;
            if (queue.empty()) {
                break;
            }
            queue.push_back(nullptr);
            continue;
        }

        if (node->left != nullptr) {
            queue.push_back(node->left);
        }
        if (node->right != nullptr) {
            queue.push_back(node->right);
        }
    }

    return depth;
}
