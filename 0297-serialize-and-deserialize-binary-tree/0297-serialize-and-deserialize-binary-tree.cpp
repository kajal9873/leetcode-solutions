/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializehelper(root, result);
        return result;
    }
    
    void serializehelper(TreeNode* node, string& result){
        if(node==nullptr){
            result += "#,";
            return;
        }
        result += to_string(node->val) + ",";
        serializehelper(node->left, result);
        serializehelper(node->right, result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializehelper(data, pos);
    }

    TreeNode* deserializehelper(string& data, int& pos){
        int commaidx = data.find(',',pos);
        string token = data.substr(pos, commaidx-pos);
        pos = commaidx + 1;
        if(token=="#") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializehelper(data, pos);
        node->right = deserializehelper(data, pos);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));