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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> leftstack, rightstack;
        TreeNode* leftnode = root;
        TreeNode* rightnode = root;
        while(leftnode!=nullptr){
            leftstack.push(leftnode);
            leftnode = leftnode->left;
        }
        while(rightnode!=nullptr){
            rightstack.push(rightnode);
            rightnode = rightnode->right;
        }
        int leftval = leftstack.top()->val;
        int rightval = rightstack.top()->val;
        while(leftval<rightval){
            int sum = leftval + rightval;
            if(sum==k){
                return true;
            }
            else if(sum<k){
                TreeNode* node = leftstack.top();
                leftstack.pop();
                node = node->right;
                while(node!=nullptr){
                    leftstack.push(node);
                    node = node->left;
                }
                leftval = leftstack.top()->val;
            }
            else{
                TreeNode* node = rightstack.top();
                rightstack.pop();
                node = node->left;
                while(node!=nullptr){
                    rightstack.push(node);
                    node = node->right;
                }
                rightval = rightstack.top()->val;
            }
        }
        return false;
    }
};