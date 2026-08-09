class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m,0);
        int len = 0;
        int i = 1;
        while(i<m){
            if(needle[i]==needle[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int hidx = 0;
        int nidx = 0;
        while(hidx<n){
            if(haystack[hidx]==needle[nidx]){
                hidx++;
                nidx++;
                if(nidx==m){
                    return hidx-m;
                }
            }else{
                if(nidx!=0){
                    nidx = lps[nidx-1];
                }else{
                    hidx++;
                }
            }
        }
        return -1;
    }
};