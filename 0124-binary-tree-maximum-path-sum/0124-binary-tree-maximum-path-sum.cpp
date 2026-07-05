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
    int maxsum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxgain(root);
        return maxsum;
    }
private:
    int maxgain(TreeNode* node){
        if(node==nullptr) return 0;
        int leftgain = max(maxgain(node->left),0);
        int rightgain = max(maxgain(node->right),0);
        int currentpathsum = node->val + leftgain + rightgain;
        maxsum = max(maxsum, currentpathsum);
        return node->val + max(leftgain, rightgain);
    }    
};