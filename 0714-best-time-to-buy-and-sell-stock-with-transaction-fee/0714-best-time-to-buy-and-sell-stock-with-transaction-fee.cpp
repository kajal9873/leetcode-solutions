class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n<=1) return 0;
        int hold = -prices[0];
        int cash = 0;
        for(int i=1; i<n; i++){
            int prevhold = hold;
            int prevcash = cash;
            hold = max(prevhold, prevcash-prices[i]);
            cash = max(prevcash, prevhold+prices[i]-fee);
        }
        return cash;
    }
};