class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxidx = 0, minidx = 0;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[minidx]) minidx = i;
            if(nums[i]>nums[maxidx]) maxidx = i;
        }
        int lo = min(minidx,maxidx);
        int hi = max(maxidx,minidx);
        int fromfront = hi+1;
        int fromback = n-lo;
        int mixed = (lo+1) + (n-hi);
        return min({fromfront,fromback,mixed});
    }
};