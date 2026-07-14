class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if(wordset.find(endWord)==wordset.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        wordset.erase(beginWord);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                string word = q.front();
                q.pop();
                if(word==endWord) return level;
                for(int j=0; j<word.size(); j++){
                    char original = word[j];
                    for(int c='a'; c<='z'; c++){
                        if(c==original) continue;
                        word[j] = c;
                        if(wordset.find(word)!=wordset.end()){
                            q.push(word);
                            wordset.erase(word);
                        }
                    }
                    word[j] = original;
                }
            }
            level++;
        }
        return 0;
    }
};