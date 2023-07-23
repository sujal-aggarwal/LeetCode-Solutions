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
    vector<TreeNode*> solve(int n){
        if(n%2==0){
            return {};
        }
        vector<vector<TreeNode*>>dp(n+1);
        
        dp[1]={new TreeNode(0)};
        
        for(int curr=3;curr<=n;curr+=2){
            for(int i=1;i<curr-1;i+=2){
                
                for(auto&l:dp[i]){
                    for(auto&r:dp[curr-i-1]){
                        TreeNode*root=new TreeNode(0);
                        root->left=l;
                        root->right=r;
                        dp[curr].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};