class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = (long long)k * (*min_element(coins.begin(), coins.end()));
        
        auto gcdll = [](long long a, long long b) -> long long {
            while (b) { a %= b; swap(a, b); }
            return a;
        };
        
        auto countUpTo = [&](long long x) -> long long {
            long long total = 0;
            int subsets = 1 << n;
            for (int mask = 1; mask < subsets; mask++) {
                long long lcm = 1;
                int bits = __builtin_popcount(mask);
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcdll(lcm, (long long)coins[i]);
                        long long newLcm = lcm / g * coins[i];
                        if (newLcm > x) { 
                            overflow = true; 
                            break; 
                        }
                        lcm = newLcm;
                    }
                }
                if (overflow) continue;
                long long cnt = x / lcm;
                if (bits % 2 == 1) total += cnt;
                else total -= cnt;
            }
            return total;
        };
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countUpTo(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};