class Solution {
private:
    struct TrieNode{
        TrieNode* children[2];
        TrieNode(){
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };
    TrieNode* root;
    static const int bits = 31;
    void insert(int num){
        TrieNode* curr = root;
        for(int i=bits; i>=0; i--){
            int bit = (num>>i) & 1;
            if(curr->children[bit]==nullptr){
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }
    int FindMaxXor(int num){
        TrieNode* curr = root;
        int maxXor = 0;
        for(int i=bits; i>=0; i--){
            int bit = (num>>i) & 1;
            int oppositebit = 1-bit;
            if(curr->children[oppositebit]!=nullptr){
                maxXor |= (1<<i);
                curr = curr->children[oppositebit];
            }
            else{
                curr = curr->children[bit];
            }
        }
        return maxXor;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode;
        for(int num : nums){
            insert(num);
        }
        int result = 0;
        for(int num : nums){
            result = max(result, FindMaxXor(num));
        }
        return result;
    }
};