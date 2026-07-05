/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
       return diameter; 
    }
private:
    int height(TreeNode* node){
        if(node==nullptr) return 0;
        int leftheight = height(node->left);
        int rightheight = height(node->right);
        diameter = max(diameter, leftheight+rightheight);
        return 1 + max(leftheight, rightheight);
    }
};