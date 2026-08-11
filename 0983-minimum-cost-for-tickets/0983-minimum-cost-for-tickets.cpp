class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastday = days.back();
        vector<bool> travelday(lastday+1, false);
        for(int d : days){
            travelday[d] = true;
        }
        vector<int> dp(lastday+1, 0);
        for(int i=1; i<=lastday; i++){
            if(!travelday[i]){
                dp[i] = dp[i-1];
            }else{
                int option1 = dp[i-1] + costs[0];
                int option2 = dp[max(0,i-7)] + costs[1];
                int option3 = dp[max(0,i-30)] + costs[2];
                dp[i] = min({option1,option2,option3});
            }
        }
        return dp[lastday];
    }
};
