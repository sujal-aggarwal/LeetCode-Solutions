/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root==NULL)
            return vector<int>();
        vector<int>arr;
        arr.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            vector<int>a1=preorder(root->children[i]);
            arr.insert(arr.end(),a1.begin(),a1.end());
        }
        return arr;
    }
};