/* 
输入某二叉树的前序遍历和中序遍历的结果，
请构建该二叉树并返回其根节点。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
示例 1:
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
示例 2:
    Input: preorder = [-1], inorder = [-1]
    Output: [-1]
限制：
    0 <= 节点个数 <= 5000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int pre_st, int pre_ed,
                    vector<int>& inorder, int in_st, int in_ed){
        if (pre_ed < pre_st){
            return nullptr;
        }
        int root_value = preorder[pre_st];
        TreeNode* root = new TreeNode(root_value);
        int idx = -1;
        for (int i = in_st; i <= in_ed; i++){
            if (inorder[i] == root_value){
                idx = i;
                break;
            }              
        }
        root->left = build(preorder, pre_st + 1, pre_st + idx - in_st, 
                           inorder, in_st, idx - 1);
        root->right = build(preorder, pre_st + idx - in_st + 1, pre_ed,
                            inorder, idx + 1, in_ed);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};