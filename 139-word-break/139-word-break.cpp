class Solution {
public:
    
    class Node{
    public:
        char c;
        bool isWord;
        vector<Node*> children;
        
        Node(char c){
            this->c = c;
            isWord = false;
            children = vector<Node*>(26, nullptr);
        }
    };
    
    
    Node* root;
    string key;
    int n;
    int dp[305][305];
    
    
    void constructTrie(vector<string>& wordDict){
        this->root = new Node('{');

        for(auto word:wordDict) {
            auto curr = root;
            for(auto w:word){
                if(!curr->children[w-'a'])
                    curr->children[w-'a'] = new Node(w);
                curr = curr->children[w-'a'];
            }
            curr->isWord=true;
        }
    }
    
    bool dfs(Node* curr, int start, int i){
        
        if(!curr)
            return false; 
        if(start==n )
            return true;
        if(i==n)
            return curr->isWord==true;
        
        if(dp[start][i]!=-1)
            return dp[start][i];

        
        if(curr->isWord)
            return dp[start][i] = dfs(curr->children[key[i]-'a'], start, i+1) || dfs(root, i, i);
        
        return dp[start][i] = dfs(curr->children[key[i]-'a'], start, i+1);

         
    
        
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        this->key = s;
        constructTrie(wordDict);
        this->n = s.length();
        memset(dp,-1,sizeof(dp));
        return dfs(root, 0, 0);
        
        
        
    }
};