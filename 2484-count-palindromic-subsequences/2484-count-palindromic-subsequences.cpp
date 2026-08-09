class Solution {
public:
    int countPalindromes(string s) {
       const long long MOD = 1e9 + 7;
       int n = s.size();
       vector<array<array<long long,10>,10>> suf(n);
       array<array<long long,10>,10> pairsuf{};
       array<long long,10> digitcountsuf{};
       for(int k=n-1; k>=0; --k){
        suf[k] = pairsuf;
        int d = s[k] - '0';
        for(int a=0; a<10; a++){
            pairsuf[d][a] = (pairsuf[d][a]+digitcountsuf[a])%MOD;
        }
        digitcountsuf[d]++;
       }
       array<array<long long,10>,10> pairpre{};
       array<long long,10> digitcountpre{};
       long long ans = 0;
       for(int k=0; k<n; k++){
        for(int a=0; a<10; a++){
            for(int b=0; b<10; b++){
                ans = (ans+pairpre[a][b]*suf[k][b][a])%MOD;
            }
        }
        int d = s[k] - '0';
        for(int a=0; a<10; a++){
            pairpre[a][d] = (pairpre[a][d]+digitcountpre[a])%MOD;
        }
        digitcountpre[d]++;
       }
       return (int)ans;
    }
};