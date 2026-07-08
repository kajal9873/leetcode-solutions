/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentmap;
        buildparentmap(root, nullptr, parentmap);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int currentdistance = 0;
        while(!q.empty()){
            int size = q.size();
            if(currentdistance==k){
                vector<int> result;
                while(!q.empty()){
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=nullptr && visited.find(curr->left)==visited.end()){
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right!=nullptr && visited.find(curr->right)==visited.end()){
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
                if(parentmap[curr]!=nullptr && visited.find(parentmap[curr])==visited.end()){
                    visited.insert(parentmap[curr]);
                    q.push(parentmap[curr]);
                }
            }
            currentdistance++;
        }
        return {};
    }    
private:
    void buildparentmap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentmap){
        if(node==nullptr) return;
        parentmap[node]=parent;
        buildparentmap(node->left, node, parentmap);
        buildparentmap(node->right, node, parentmap);       
    }
};