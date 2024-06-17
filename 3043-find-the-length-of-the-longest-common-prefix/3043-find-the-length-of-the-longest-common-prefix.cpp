class TrieNode{
    public:
        vector<TrieNode*>next;
        bool isEnd;

        TrieNode():next(10,nullptr),isEnd{false}{}
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        }

        void insert(string s){
            TrieNode* Node=root;
            for(char c:s){
                int i=c-'0';
                if(Node->next[i]==nullptr){
                    Node->next[i]=new TrieNode();
                }
                Node=Node->next[i];
            }
            Node->isEnd=true;
        }
    
        int commonPrefix(string s){
            TrieNode* Node=root;
            int len=0;
            for(char c:s){
                int i=c-'0';
                if(Node->next[i]==nullptr){
                    return len;
                }
                Node=Node->next[i];
                len++;
            }
            return len;
        }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int i:arr1){
            int curr=i;
            while(curr){
                trie.insert(to_string(curr));
                curr/=10;
            }
        }
        int maxlen=0;
        for(int i:arr2){
            int curr=i;
            while(curr){
                int len=trie.commonPrefix(to_string(curr));
                maxlen=max(maxlen,len);
                curr/=10;
            }
        }
        return maxlen;
    }
};