class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int g = 0;
        for (int coin : coins) g = __gcd(g, coin);

        if (amount != 0 && g != 0 && amount % g != 0) return 0;

        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        // Ek "safe cap" define karo — is se zyada ki value ki humein 
        // kabhi zaroorat nahi (kyunki asli answer guaranteed int32 mein fit hota hai)
        const long long CAP = 2e18;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                // Saturating add: agar sum CAP se zyada ho jaaye, 
                // usse CAP pe hi rok do (overflow crash hone se bachao)
                if (dp[j - coin] > CAP - dp[j]) {
                    dp[j] = CAP;  // clamp kar do, crash mat hone do
                } else {
                    dp[j] += dp[j - coin];
                }
            }
        }

        return (int)dp[amount];
    }
};