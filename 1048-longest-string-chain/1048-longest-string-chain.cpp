class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int maxchain = 1;
        for(const string& w : words){
            dp[w] = 1;
            for(int i=0; i<(int)w.size(); i++){
                string predecessor = w.substr(0,i) + w.substr(i+1);
                if(dp.find(predecessor)!=dp.end()){
                    dp[w] = max(dp[w],dp[predecessor]+1);
                }
            }
            maxchain = max(maxchain, dp[w]);
        }
        return maxchain;
    }
};