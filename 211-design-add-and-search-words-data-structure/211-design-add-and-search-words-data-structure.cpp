class WordDictionary {
    
private:
    class node{
        public:
            bool isWord;
            vector<node*>children;
            node(){
                isWord = false;
                children = vector<node*>(26, nullptr);
            }
            
        };
    
    node* root;
    
    
    
public:
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* curr = root;      
        for(int i=0; i<word.length(); i++){
            int ind = word[i]-'a';     
            if(curr->children[ind]==NULL)
                curr->children[ind] = new node();
            curr = curr->children[ind];
        }
        curr->isWord=true;
    }

    bool dfs(int i, node* curr, string& word ){

        if(!curr)
            return false; //i==word.length();
        if(i==word.length())
            return curr->isWord;

        if(word[i]!='.'){
            // int ind = ;
            // if(curr->children[ind]==NULL)
            //     return false;
            return dfs(i+1, curr->children[word[i]-'a'], word);
            
        }
        else{

            for(auto child:curr->children){
                if(child and dfs(i+1, child, word))
                   return true;

            }
        }
        return false;

    }     


    bool search(string word) {
        return dfs(0, root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */