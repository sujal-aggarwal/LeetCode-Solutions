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
    unordered_map<string,vector<TreeNode*>>mp;
    vector<TreeNode*> solve(int start,int end){
        if(start>end){
            return {NULL};
        }
        if(start==end){
            TreeNode* root=new TreeNode(start);
            return {root};
        }
        string key=to_string(start)+" "+to_string(end);
        if(mp.count(key))
            return mp[key];
        vector<TreeNode*>ans;
        for(int i=start;i<=end;i++){
            auto leftBst=solve(start,i-1);
            auto rightBst=solve(i+1,end);
            for(auto left:leftBst){
                for(auto right:rightBst){
                    TreeNode*root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    ans.push_back(root);
                }
            }
        }
        return mp[key]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};