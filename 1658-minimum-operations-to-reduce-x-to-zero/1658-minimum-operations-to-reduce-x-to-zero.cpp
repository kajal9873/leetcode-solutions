class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = accumulate(nums.begin(),nums.end(),0LL);
        long long target = total - x;
        if(target<0) return -1;
        int left = 0;
        long long windowsum = 0;
        int maxlen = -1;
        for(int right=0; right<n; right++){
            windowsum += nums[right];
            while(windowsum>target && left<=right){
                windowsum -= nums[left];
                left++;
            }
            if(windowsum == target){
                maxlen = max(maxlen, right-left+1);
            }
        }
        if(maxlen==-1) return -1;
        return n - maxlen;
    }
};