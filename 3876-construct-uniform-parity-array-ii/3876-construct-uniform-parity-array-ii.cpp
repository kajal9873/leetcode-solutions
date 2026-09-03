class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(),nums1.end());
        int p = nums1[0]%2;
        bool oddseen = false;
        for(int i=0; i<n; i++){
            int parity = nums1[i]%2;
            if(parity!=p){
                if(!oddseen) return false;
            }
            if(parity==1) oddseen = true;
        }
        return true;
    }
};