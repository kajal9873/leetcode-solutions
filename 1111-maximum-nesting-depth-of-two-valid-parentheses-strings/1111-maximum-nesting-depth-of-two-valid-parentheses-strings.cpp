class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int d = 0;
        for (int i = 0; i < (int)seq.size(); ++i) {
            if (seq[i] == '(') {
                ans[i] = ++d & 1;
            } else {
                ans[i] = d-- & 1;
            }
        }
        return ans;
    }
};