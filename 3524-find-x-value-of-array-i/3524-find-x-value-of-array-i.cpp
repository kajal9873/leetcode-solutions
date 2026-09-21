class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k,0);
        vector<long long> cnt(k,0);
        for(int a : nums){
            int m = a % k;
            vector<long long> next(k,0);
            for(int r=0; r<k; r++){
                if(cnt[r]>0){
                    next[(r*m)%k] += cnt[r];
                }
            }
            next[m] += 1;
            for(int r=0; r<k; r++){
                result[r] += next[r];
            }
            cnt = next;
        }
        return result;
    }
};