class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long start = 1;
        int commas = 0;
        while(start<=n){
            long long end = start*1000 - 1;
            long long high = min(end,(long long)n);
            long long count = high-start+1;
            total += count * (long long)commas;
            commas++;
            start *= 1000;
        }
        return total;
    }
};