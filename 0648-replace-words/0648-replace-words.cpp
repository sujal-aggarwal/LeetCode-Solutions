class TrieNode{
    public:
        bool isEnd;
        vector<TrieNode*>children;
        
        TrieNode():isEnd(false),children(26,nullptr){
        }
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        }
        
        void insert(string word){
            TrieNode* current= root;
            for(char c:word){
                if(current->children[c-'a']==nullptr){
                    current->children[c-'a']=new TrieNode();
                }
                current = current->children[c-'a'];
            }
            current->isEnd=true;
        }
    
        string shortestRoute(string word){
            TrieNode* current=root;
            for(int i=0;i<word.length();++i){
                char c=word[i];
                if(current->children[c-'a']==nullptr){
                    return word;
                }
                current=current->children[c-'a'];
                if(current->isEnd){
                    return word.substr(0,i+1);
                }
            }
            return word;
        }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream sStream(sentence);
        Trie dicTrie;
        for(string word:dictionary){
            dicTrie.insert(word);
        }
        string word;
        string newSentence;
        while(getline(sStream,word,' ')){
            newSentence+=dicTrie.shortestRoute(word)+" ";
        }
        newSentence.pop_back();
        return newSentence;
    }
};