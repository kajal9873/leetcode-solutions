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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        map<int, map<int, multiset<int>>> nodes;
        dfs(root, 0, 0, nodes);
        for(auto& colpair : nodes){
            vector<int> column;
            for(auto& rowpair : colpair.second){
                for(int val : rowpair.second){
                    column.push_back(val);
                }
            }
            result.push_back(column);
        }
        return result;
    }
private:
    void dfs(TreeNode* node, int row, int col, map<int, map<int, multiset<int>>>& nodes){
        if(node==nullptr) return;
        nodes[col][row].insert(node->val);
        dfs(node->left, row+1, col-1, nodes);
        dfs(node->right, row+1, col+1, nodes);
    } 
};