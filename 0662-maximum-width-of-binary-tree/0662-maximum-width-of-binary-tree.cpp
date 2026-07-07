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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root,0});
        int maxwidth = 0;
        while(!q.empty()){
            int levelsize = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = first;
            for(int i=0; i<levelsize; i++){
                auto[node, idx] = q.front();
                q.pop();
                idx -= first;
                last = idx;
                if(node->left) q.push({node->left, 2*idx});
                if(node->right) q.push({node->right, 2*idx+1});
            }
            maxwidth = max(maxwidth, (int)(last-0+1));
        }
        return maxwidth;
    }
};