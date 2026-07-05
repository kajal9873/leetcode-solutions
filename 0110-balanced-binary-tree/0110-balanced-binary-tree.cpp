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
    bool isBalanced(TreeNode* root) {
        return checkheight(root) != -1;
    }
private:
    int checkheight(TreeNode* node){
        if(node == nullptr) return 0;
        int leftheight = checkheight(node->left);
        if(leftheight == -1) return -1;
        int rightheight = checkheight(node->right);
        if(rightheight == -1) return -1;
        if(abs(leftheight - rightheight) > 1) return -1;
        return 1 + max(leftheight, rightheight);
    }
};