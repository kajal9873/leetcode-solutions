class Trie {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isendofword;
        TrieNode(){
            isendofword = false;
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx]; 
        }
        curr->isendofword = true;
    }
    
    bool search(string word) {
        TrieNode* node = findNode(word);
        return node != nullptr && node->isendofword;
    }
    
    bool startsWith(string prefix) {
        return findNode(prefix) != nullptr;
    }
private:
    TrieNode* findNode(const string& s){
        TrieNode* curr = root;
        for(char ch : s){
            int idx = ch - 'a';
            if(curr->children[idx]==nullptr){
                return nullptr;
            }
            curr = curr->children[idx];
        }
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */