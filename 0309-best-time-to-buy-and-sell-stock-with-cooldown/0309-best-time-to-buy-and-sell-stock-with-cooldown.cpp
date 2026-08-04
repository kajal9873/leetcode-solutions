class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        for(int i=1; i<n; i++){
            int prevhold = hold;
            int prevsold = sold;
            int prevrest = rest;
            hold = max(prevhold, prevrest-prices[i]);
            sold = prevhold + prices[i];
            rest = max(prevrest,prevsold);
        }
        return max(sold,rest);
    }
};