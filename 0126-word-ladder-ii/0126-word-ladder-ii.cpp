class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if (dict.find(endWord) == dict.end()) return res;
        dict.erase(beginWord);
        
        // KEY CHANGE: parents map -> word ka list of predecessors (word -> [parent1, parent2...])
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel{beginWord};
        bool found = false;
        
        // ===== PHASE 1: BFS, ab parent edges store karo (reverse direction) =====
        while (!currentLevel.empty() && !found) {
            for (const string& w : currentLevel) dict.erase(w);
            
            unordered_set<string> nextLevel;
            
            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        temp[i] = c;
                        
                        if (dict.count(temp)) {
                            nextLevel.insert(temp);
                            // CHANGE: forward "word->temp" nahi, balki temp ka parent "word" store karo
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }
            currentLevel = nextLevel;
        }
        
        if (!found) return res;
        
        // ===== PHASE 2: endWord se beginWord ki taraf backward DFS =====
        vector<string> path{endWord};
        backtrack(endWord, beginWord, parents, path, res);
        
        return res;
    }
    
private:
    // Backward DFS: endWord se shuru karke parents follow karte hue beginWord tak pahuncho
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& res) {
        
        // Base case: beginWord tak pahunch gaye -> ye ek valid complete path hai
        if (word == beginWord) {
            vector<string> completePath(path.rbegin(), path.rend()); // reverse karo (endWord->begin ko begin->end banao)
            res.push_back(completePath);
            return;
        }
        
        // Agar word ka koi parent nahi (shouldn't happen for valid path words, safety check)
        if (parents.find(word) == parents.end()) return;
        
        // Har parent try karo (backtracking)
        for (const string& parent : parents[word]) {
            path.push_back(parent); // choose
            backtrack(parent, beginWord, parents, path, res); // explore backward
            path.pop_back(); // un-choose
        }
    }
};