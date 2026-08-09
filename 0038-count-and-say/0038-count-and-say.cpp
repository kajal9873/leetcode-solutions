class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i=1; i<n; i++){
            result = getnextterm(result);
        }
        return result;
    }
private:
    string getnextterm(const string &s){
        string next = "";
        int len = s.size();
        int i=0;
        while(i<len){
            char currentchar = s[i];
            int count = 0;
            while(i<len && s[i]==currentchar){
                count++;
                i++;
            }
            next += to_string(count);
            next += currentchar;
        }
        return next;
    }
};