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
private:
    TreeNode* vinehead;
    void makeRotations(int count){
        TreeNode* curr=vinehead;
        for(int i=0;i<count;i++){
            TreeNode* tmp=curr->right;
            leftRotate(curr,tmp);
            curr=curr->right;
        }
    }
    void leftRotate(TreeNode* parent, TreeNode* child){
        TreeNode* tmp=child->right;
        child->right=tmp->left;
        tmp->left=child;
        parent->right=tmp;
    }
    void rightRotate(TreeNode* parent, TreeNode* child){
        TreeNode* tmp=child->left;
        child->left=tmp->right;
        tmp->right=child;
        parent->right=tmp;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==nullptr)return root;
        
        
        vinehead=new TreeNode(0);
        vinehead->right=root;
        TreeNode*current=vinehead;
        while(current->right){
            if(current->right->left)
                rightRotate(current,current->right);
            else
                current=current->right;
        }
        
        
        int nodeCount=0;
        current=vinehead->right;
        while(current){
            nodeCount++;
            current=current->right;
        }
        
        int m=pow(2,floor(log2(nodeCount+1)))-1;
        makeRotations(nodeCount-m);
        while(m>1){
            m/=2;
            makeRotations(m);
        }
        
        TreeNode* balancedBst=vinehead->right;
        delete vinehead;
        return balancedBst;
    }
};