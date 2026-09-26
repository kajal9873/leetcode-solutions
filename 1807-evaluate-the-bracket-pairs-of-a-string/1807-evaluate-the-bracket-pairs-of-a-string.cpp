class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> keyToValue;
        keyToValue.reserve(knowledge.size() * 2);
        for (auto &pair : knowledge) {
            keyToValue[pair[0]] = pair[1];
        }

        string result;
        result.reserve(s.size());

        string currentKey;
        currentKey.reserve(16);

        bool insideBracket = false;

        for (char c : s) {
            if (c == '(') {
                insideBracket = true;
                currentKey.clear();
            }
            else if (c == ')') {
                auto it = keyToValue.find(currentKey);
                if (it != keyToValue.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                insideBracket = false;
            }
            else {
                if (insideBracket) {
                    currentKey += c;
                } else {
                    result += c;
                }
            }
        }

        return result;
    }
};