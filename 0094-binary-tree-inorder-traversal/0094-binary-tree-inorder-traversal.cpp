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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        
        TreeNode* curr=root;
        while(curr){
            if(curr->left==nullptr){
                result.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* leftChild=curr->left;
                while(leftChild->right){
                    leftChild=leftChild->right;
                }
                TreeNode* temp=curr;
                curr=curr->left;
                leftChild->right=temp;
                temp->left=nullptr;
            }
        }
        return result;
    }
};