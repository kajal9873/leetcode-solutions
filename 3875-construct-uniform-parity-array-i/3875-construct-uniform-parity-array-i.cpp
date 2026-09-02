class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int oddcount = 0;
        for(int x : nums1){
            if(x%2==1) oddcount++;
        }
        for(int p=0; p<=1; p++){
            bool ok = true;
            for(int i=0; i<n; i++){
                if(nums1[i]%2==p){
                    continue;
                }
                if(nums1[i]%2==1){
                    if(oddcount<2) {ok=false; break;}
                }else{
                    if(oddcount<1) {ok=false; break;}
                }
            }
            if(ok) return true;
        }
        return false;
    }
};