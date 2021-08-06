/* 
给定一个 完美二叉树 ，其所有叶子节点都在同一层，
每个父节点都有两个子节点。二叉树定义如下：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。
进阶：
    你只能使用常量级额外空间。
    使用递归解题也符合要求，
    本题中递归程序占用的栈空间不算做额外的空间复杂度。
示例：
    输入：root = [1,2,3,4,5,6,7]
    输出：[1,#,2,3,#,4,5,6,7,#]
    解释：给定二叉树如图 A 所示，
    你的函数应该填充它的每个 next 指针，
    以指向其下一个右侧节点，
    如图 B 所示。序列化的输出按层序遍历排列，
    同一层节点由 next 指针连接，
    '#' 标志着每一层的结束。
提示：
    树中节点的数量少于 4096
    -1000 <= node.val <= 1000
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectTwoNode(Node* node1, Node* node2){
        //如果两个节点中的一个为空，则不要连接
        if (node1 == nullptr || node2 == nullptr)
            return;
        //前序遍历位置
        node1->next = node2;
        connectTwoNode(node1->left, node1->right);
        connectTwoNode(node2->left,node2->right);
        connectTwoNode(node1->right,node2->left);
    }
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        connectTwoNode(root->left, root->right);
        return root;
    }
};