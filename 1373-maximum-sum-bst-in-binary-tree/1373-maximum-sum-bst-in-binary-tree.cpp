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
    int maxsum = 0;
    array<long long, 4> postorder(TreeNode* node){
        if(node==nullptr) return {1, LLONG_MAX, LLONG_MIN, 0};
        array<long long, 4> left = postorder(node->left);
        array<long long, 4> right = postorder(node->right);
        bool leftisbst = left[0];
        bool rightisbst = right[0];
        if(leftisbst && rightisbst && node->val>left[2] && node->val<right[1]){
            long long totalsum = left[3] + right[3] + node->val;
            long long minval = min((long long)node->val, left[1]);
            long long maxval = max((long long)node->val, right[2]);
            maxsum = max(maxsum, (int)totalsum);
            return {1, minval, maxval, totalsum};
        }
        return {0, 0, 0, 0};
    }
    int maxSumBST(TreeNode* root) {
        postorder(root);
        return maxsum;
    }
};