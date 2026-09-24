class Solution {
public:
    int digitsum(int num){
        int sum = 0;
        while(num>0){
            sum += num % 10; //add last digit
            num /= 10; //remove last digit
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(digitsum(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
};