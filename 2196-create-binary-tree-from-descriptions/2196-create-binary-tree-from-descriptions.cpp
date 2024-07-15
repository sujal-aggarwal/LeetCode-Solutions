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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodes;
        unordered_map<int,int>indegree;
        for(auto vec:descriptions){
            int parent=vec[0];
            int child=vec[1];
            int isLeft=vec[2];
            
            indegree[parent];
            indegree[child]++;
            
            TreeNode* ParentNode=(nodes.find(parent)!=nodes.end())?nodes[parent]:new TreeNode(parent);
            TreeNode* childNode=(nodes.find(child)!=nodes.end())?nodes[child]:new TreeNode(child);
            nodes[parent]=ParentNode;
            nodes[child]=childNode;
            
            if(isLeft){
                ParentNode->left=childNode;
            }else{
                ParentNode->right=childNode;
            }
        }
        TreeNode* ans;
        for(auto [i,j]:indegree){
            if(j==0){
                ans=nodes[i];
            }
        }
        
        return ans;
    }
};