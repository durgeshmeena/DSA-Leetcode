class Node{
public:    
    char c;
    bool isWord;
    vector<Node*>children;

    Node(char c){
        this->c = c;
        isWord = false;
        children = vector<Node*>(26, nullptr);
    }
};

class Trie{
public:    
    Node* root;
    Node* curr;
    string keyword;

    Trie(){
        root = new Node('0');
        curr = new Node('0');
        keyword = "";
    }

    void insert(string word){
        auto curNode = root;
        for(auto w:word){
            if(!curNode->children[w-'a'])
                curNode->children[w-'a'] = new Node(w);
            curNode = curNode->children[w-'a'];
        }
        curNode->isWord=true;
    }

    void dfs(Node* curNode, string str, vector<string>&v) {
        if(v.size()==3)return;
        // if(!curNode)return;

        str += curNode->c;
        if(curNode->isWord)
            v.push_back(str);

        for(auto child:curNode->children){
            if(child)
                dfs(child, str, v);
        }
    }

    void suggests(int ind , string str, vector<string>& v){
        string s = keyword.substr(0, ind);
        Node* curNode = this->root;
        for(int i=0; i<=ind; i++){
            if(!curNode->children[keyword[i]-'a'])
                return;
            curNode = curNode->children[keyword[i]-'a'];
        }

        dfs(curNode, s, v);

    }    
};



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        
        auto trie = new Trie();
        trie->keyword = searchWord;
        
        for(auto word:products)
            trie->insert(word);
        
        trie->curr = trie->root;
        
        for(int i=0; i<searchWord.length(); i++){
            vector<string> v; 
            trie->suggests(i, "", v);
            ans.push_back(v);    
        }
        
        return ans;
        
    }
};