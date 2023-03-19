class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool isEnd;
    TrieNode(){
        isEnd=false;
    }
};
class Trie {
private:
    TrieNode*root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*node=root;
        for(auto i:word){
            if(node->children.find(i)==node->children.end()){
                node->children[i]=new TrieNode();
            }
            node=node->children[i];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode*node=root;
        for(auto i:word){
            if(node->children.find(i)==node->children.end())
                return false;
            node=node->children[i];
        }
        return node->isEnd;
    }
    
    bool startsWith(string word) {
        TrieNode*node=root;
        for(auto i:word){
            if(node->children.find(i)==node->children.end())
                return false;
            node=node->children[i];
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