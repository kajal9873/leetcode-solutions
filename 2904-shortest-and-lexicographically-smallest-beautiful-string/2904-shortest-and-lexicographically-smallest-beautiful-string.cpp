class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best = "";
        int bestLen = -1;
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') cnt++;
                if (cnt == k) {
                    string sub = s.substr(i, j - i + 1);
                    if (bestLen == -1 || (int)sub.size() < bestLen || 
                        ((int)sub.size() == bestLen && sub < best)) {
                        best = sub;
                        bestLen = sub.size();
                    }
                    break; // stop extending once count reaches k
                }
            }
        }
        
        return best;
    }
};