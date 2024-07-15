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
    TreeNode* solve(unordered_map<int,vector<int>>& mp,int root){
        if(root==-1)return nullptr;
        TreeNode* curr = new TreeNode(root);
        if(mp.find(root)!=mp.end()){
            curr->left=solve(mp,mp[root][0]);
            curr->right=solve(mp,mp[root][1]);
        }else{
            curr->left=nullptr;
            curr->right=nullptr;
        }
        return curr;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>indegree;
        for(auto des:descriptions){
            if(mp.find(des[0])!=mp.end()){
                mp[des[0]][1-des[2]]=des[1];
            }else{
                mp[des[0]]={-1,-1};
                mp[des[0]][1-des[2]]=des[1];
            }
            indegree[des[1]]++;
            indegree[des[0]];
        }
        int root=0;
        for(auto [x,y]:indegree){
            if(y==0){
                root=x;
                break;
            }
        }
        return solve(mp,root);
    }
};