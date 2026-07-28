class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26,-1), last(26,-1);
        for(int i=0; i<n; i++){
            int c = s[i] - 'a';
            if(first[c]==-1) first[c] = i;
            last[c] = i;
        }
        vector<pair<int,int>> candidates;
        for(int c=0; c<26; c++){
            if(first[c]==-1) continue;
            int start = first[c];
            int end = last[c];
            bool valid = true;
            int j = start;
            while(j<=end){
                int cj = s[j] - 'a';
                if(first[cj]<start){
                    valid = false;
                    break;
                }
                end = max(end, last[cj]);
                j++;
            }
            if(valid) candidates.push_back({start,end});
        }
        sort(candidates.begin(),candidates.end(),
        [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.second!=b.second) return a.second<b.second;
            return a.first>b.first;
        });
        vector<string> result;
        int lastend = -1;
        for(auto& [st,en] : candidates){
            if(st>lastend){
                result.push_back(s.substr(st, en-st+1));
                lastend = en;
            }
        }
        return result;
    }
};