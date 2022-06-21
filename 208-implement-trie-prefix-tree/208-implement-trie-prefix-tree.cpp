class Trie {
public:
    
    class TrieNode{
    public:
        bool isWord;
        vector<TrieNode*> children;   
        
        TrieNode(){
            isWord = false;
            children = vector<TrieNode*>(26, nullptr);
        }
        
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = this->root;
        for(int i=0; i<word.length(); i++){
            int ind = word[i]-'a';
            if(curr->children[ind]==NULL){
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->isWord = true;
        
    }
    
       
    bool search(string word) {
        TrieNode* curr = this->root;
        for(int i=0; i<word.length(); i++){
            int ind = word[i]-'a';
            if(!curr->children[ind])
                return false;
            curr = curr->children[ind];
        }
        return curr->isWord;   
    }
    
    
    bool startsWith(string prefix) {
        TrieNode* curr = this->root;
        for(int i=0; i<prefix.length(); i++){
            int ind = prefix[i]-'a';
            if(!curr->children[ind])
                return false;
            curr = curr->children[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */