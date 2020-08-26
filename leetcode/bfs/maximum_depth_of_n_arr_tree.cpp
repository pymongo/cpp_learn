#include <vector>

using namespace std;

// N叉树节点
class Node {
public:
    int val;
    vector<Node *> children;

    Node();

    // https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
    // prefixing explicit keyword to single argument constructor prevents the compiler from using that constructor for implicit conversions.
    // 一个入参的构造方法前要加上explicit的作用: 例如有个函数是foo(Node)，有一处调用是foo(1)，
    // 如果不加explicit编译器会调用Node(int)构造方法去将1强制转换为Node实例对象，造成UB
    explicit Node(int _val) {
        this->val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        this->val = _val;
        this->children = _children;
    }
};

int main() {
    return 0;
}
