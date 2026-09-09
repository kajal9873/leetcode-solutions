class Solution {
public:
    long long countCommas(long long n) {
       long long total = 0;
       long long low = 1;
       long long high = 9;
       int d = 1;
       while(low<=n){
        long long actualhigh = min(high,n);
        long long count = actualhigh - low + 1;
        long long commaspernumber = (d-1)/3;
        total += count * commaspernumber;
        low = high + 1;
        high = high * 10 + 9;
        d++;
       } 
       return total;
    }
};