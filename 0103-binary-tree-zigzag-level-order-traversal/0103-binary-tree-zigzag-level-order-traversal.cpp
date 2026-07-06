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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright = true;
        while(!q.empty()){
            int levelsize = q.size();
            vector<int> currentlevel(levelsize);
            for(int i=0; i<levelsize; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = lefttoright ? i : (levelsize-1-i);
                currentlevel[index] = node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            result.push_back(currentlevel);
            lefttoright = !lefttoright;
        }
        return result;
    }
};