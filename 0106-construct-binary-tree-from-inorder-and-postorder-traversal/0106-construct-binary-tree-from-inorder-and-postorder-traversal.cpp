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
    int postorderidx;
    unordered_map<int, int> inorderindexmap; 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderidx = postorder.size()-1;
        for(int i=0; i<inorder.size(); i++){
            inorderindexmap[inorder[i]] = i;
        }
        return build(postorder, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& postorder, int inorderstart, int inorderend){
        if(inorderstart>inorderend) return nullptr;
        int rootval = postorder[postorderidx];
        postorderidx--;
        TreeNode* root = new TreeNode(rootval);
        int mid = inorderindexmap[rootval];
        root->right = build(postorder, mid+1, inorderend);
        root->left = build(postorder, inorderstart, mid-1);
        return root;
    }    
};