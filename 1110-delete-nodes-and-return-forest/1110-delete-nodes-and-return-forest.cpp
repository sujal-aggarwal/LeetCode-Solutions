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
    vector<TreeNode*>ans;
    void dfs(TreeNode*& root,unordered_map<int,int>& mp){
        if(root==nullptr)return;
        dfs(root->left,mp);
        dfs(root->right,mp);
        if(mp.find(root->val)!=mp.end()){
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            delete root;
            root=nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int>mp;
        for(auto i:to_delete){
            mp[i]++;
        }
        dfs(root,mp);
        if(root!=nullptr && mp.find(root->val)==mp.end()){
            ans.push_back(root);
        }
        return ans;
    }
};