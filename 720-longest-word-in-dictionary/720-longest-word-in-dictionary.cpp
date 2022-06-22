class Solution {
private:
    class TrieNode{
    public:
        bool isWord;
        vector<TrieNode*> children;
        
        TrieNode(){
            isWord = false;
            children = vector<TrieNode*>(26, nullptr);
        }
    };
    
    TrieNode* root = new TrieNode;
    
    
public:
    string ans="";
    void constructTrie(vector<string>& words) {
        root->isWord=true;
        for(auto w:words) {
            auto curr = root;
            for(int i=0; i<w.length(); i++){
                int ind = w[i]-'a';
                if(!curr->children[ind])
                    curr->children[ind] = new TrieNode;
                curr = curr->children[ind];
            }
            curr->isWord=true;
        }
    }
    
    
    void search(TrieNode* curr, char c, string str) {
        if(!curr->isWord)
            return;
        str += c;
        if(str.length()>ans.length())
                    ans = str;
        
        for(int i=0; i<26; i++) 
            if(curr->children[i])
                search(curr->children[i], ('a'+i), str);    
             

    }
    
    
    string longestWord(vector<string>& words) {
        constructTrie(words);
        string s_t_r = "";
        search(root, 'D', s_t_r);
        
        return ans.substr(1);
    }
};