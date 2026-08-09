class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        int minrepeat = (lenB + lenA - 1)/lenA;
        string candidate = "";
        for(int i=0; i<minrepeat; i++){
            candidate += a;
        }
        if(candidate.find(b)!=string::npos){
            return minrepeat;
        }
        candidate += a;
        if(candidate.find(b)!=string::npos){
            return minrepeat+1;
        }
        return -1;
    }
};