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
        int count = 0;
        pair<int,int> dfs(TreeNode* node){
            if(node==nullptr){
                return {0,0};
            }
            pair<int,int> leftresult = dfs(node->left);
            int leftsum = leftresult.first;
            int leftcount = leftresult.second;
            pair<int,int> rightresult = dfs(node->right);
            int rightsum = rightresult.first;
            int rightcount = rightresult.second;
            int totalsum = leftsum + rightsum + node->val;
            int totalcount = leftcount + rightcount + 1;
            int average = totalsum/totalcount;
            if(node->val==average){
                count++;
            }
            return {totalsum,totalcount};
        }
        int averageOfSubtree(TreeNode* root) {
            count = 0;
            dfs(root);
            return count;
        }
};