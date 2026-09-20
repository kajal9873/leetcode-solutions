class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            int revalphavalue = 26 - (s[i] - 'a');
            sum += revalphavalue * (i+1);
        }
        return sum;
    }
};