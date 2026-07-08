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
    int preorderidx;
    unordered_map<int, int> inorderindexmap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderidx = 0;
        for(int i=0; i<inorder.size(); i++){
            inorderindexmap[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& preorder, int inorderstart, int inorderend){
        if(inorderstart>inorderend) return nullptr;
        int rootval = preorder[preorderidx];
        preorderidx++;
        TreeNode* root = new TreeNode(rootval);
        int mid = inorderindexmap[rootval];
        root->left = build(preorder, inorderstart, mid-1);
        root->right = build(preorder, mid+1, inorderend);
        return root;
    }    
};