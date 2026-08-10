class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Step 1: Travel days ko fast lookup ke liye a boolean array/set banao
        // isTravelDay[d] = true agar day 'd' par travel karna hai
        int lastDay = days.back();               // sabse aakhri travel day
        vector<bool> isTravelDay(lastDay + 1, false);
        for (int d : days) {
            isTravelDay[d] = true;
        }

        // Step 2: dp array banao
        // dp[i] = minimum cost to cover all travel days from 1 to i
        vector<int> dp(lastDay + 1, 0);
        // dp[0] = 0 hi rahega (0 din tak kharch = 0)

        // Step 3: Har din ke liye dp fill karo
        for (int i = 1; i <= lastDay; i++) {
            if (!isTravelDay[i]) {
                // Is din travel hi nahi karna, to koi extra cost nahi
                // Bas pichle din ka cost copy kar lo
                dp[i] = dp[i - 1];
            } else {
                // Teeno pass options try karo aur minimum lo

                // Option 1: 1-day pass -> sirf aaj cover hoga
                int option1 = dp[i - 1] + costs[0];

                // Option 2: 7-day pass -> (i-7) se i tak cover hoga
                int option2 = dp[max(0, i - 7)] + costs[1];

                // Option 3: 30-day pass -> (i-30) se i tak cover hoga
                int option3 = dp[max(0, i - 30)] + costs[2];

                // In teeno mein se minimum le lo
                dp[i] = min({option1, option2, option3});
            }
        }

        // Step 4: Answer hoga last travel day tak ka minimum cost
        return dp[lastDay];
    }
};
