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
    static const int bits = 29;
    void insert(int num){
        TrieNode* curr = root;
        for(int i=bits; i>=0; i--){
            int bit = (num>>i)&1;
            if(curr->children[bit]==nullptr){
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }
    int findmaxXor(int x){
        TrieNode* curr = root;
        int maxXor = 0;
        for(int i=bits; i>=0; i--){
            int bit = (x>>i)&1;
            int oppositebit = 1 - bit;
            if(curr->children[oppositebit] != nullptr){
                maxXor |= (1<<i);
                curr = curr->children[oppositebit];
            }else{
                curr = curr->children[bit];
            }
        }
        return maxXor;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(),nums.end());
        vector<array<int,3>> sortedqueries(q);
        for(int i=0; i<q; i++){
            sortedqueries[i] = {queries[i][1], queries[i][0], i};
        }
        sort(sortedqueries.begin(),sortedqueries.end());
        root = new TrieNode();
        vector<int> answer(q);
        int numsptr = 0;
        for(auto& query : sortedqueries){
            int m = query[0];
            int x = query[1];
            int originalidx = query[2];
            while(numsptr<n && nums[numsptr]<=m){
                insert(nums[numsptr]);
                numsptr++;
            }
            if(numsptr==0){
                answer[originalidx] = -1;
            }else{
                answer[originalidx] = findmaxXor(x);
            }
        }
        return answer;
    }
};