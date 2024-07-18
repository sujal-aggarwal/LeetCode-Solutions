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
    void pathMaker(TreeNode* root,vector<string>& paths,string& currPath){
        
        if(!root->left && !root->right){
            paths.push_back(currPath);
            return;
        }
        
        if(root->left){
            currPath+='L';
            pathMaker(root->left,paths,currPath);
            currPath.pop_back();
        }
        
        if(root->right){
            currPath+='R';
            pathMaker(root->right,paths,currPath);
            currPath.pop_back();
        }
        
    }
    int countPairs(TreeNode* root, int distance) {
        vector<string>paths;
        string currPath="";
        pathMaker(root,paths,currPath);
        
        int result=0,n=paths.size();
        
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int prefixLength = 0;
                for(int k = 0; k < min(paths[i].length(), paths[j].length()); k++)
                {
                    if(paths[i][k] != paths[j][k]) break;
                    prefixLength++;
                }
                if(paths[i].length() + paths[j].length() - prefixLength * 2 <= distance) result++;
            }
        }
        return result;
    }
};