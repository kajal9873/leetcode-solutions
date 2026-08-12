class Solution {
public:
    bool issubsequence(string& s, string& t){
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.size();
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int result = -1;
        for(int i=0; i<n; i++){
            bool isuncommon = true;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(issubsequence(strs[i],strs[j])){
                   isuncommon = false;
                   break; 
                }
            }
            if(isuncommon){
                result = max(result, (int)strs[i].size());
            }
        }
        return result;
    }
};