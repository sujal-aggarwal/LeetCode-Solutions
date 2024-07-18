/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(TreeNode* currNode,TreeNode* prevNode,unordered_map<TreeNode*,vector<TreeNode*>>& adj,unordered_set<TreeNode*>& leafNodes){
        if(!currNode)return ;
        if(!currNode->left && !currNode->right){
            leafNodes.insert(currNode);
        }
        if(prevNode){
            adj[prevNode].push_back(currNode);
            adj[currNode].push_back(prevNode);
        }
        makeGraph(currNode->left,currNode,adj,leafNodes);
        makeGraph(currNode->right,currNode,adj,leafNodes);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>> adj;
        unordered_set<TreeNode*> leafNodes;
        
        makeGraph(root,nullptr,adj,leafNodes);
        
        int count=0;
        
        for(auto leaf:leafNodes){
            unordered_set<TreeNode*>seen;
            queue<TreeNode*>q;
            seen.insert(leaf);
            q.push(leaf);
            for(int i=0;i<=distance;i++){
                int size=q.size();
                for(int j=0;j<size;j++){
                    TreeNode* curr=q.front();
                    q.pop();
                    
                    if(leafNodes.find(curr)!=leafNodes.end() && curr!=leaf){
                        count++;
                    }
                    
                    for(auto v:adj[curr]){
                        if(seen.find(v)==seen.end()){
                            q.push(v);
                            seen.insert(v);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};