class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sufmin(n);
        sufmin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            sufmin[i] = min(sufmin[i+1], nums[i]);
        }
        int maxnumber = INT_MIN;
        for(int i=0; i<n; i++){
            maxnumber = max(maxnumber, nums[i]);
            int score = maxnumber - sufmin[i];
            if(score<=k) return i;
        }
        return -1;
    }
};