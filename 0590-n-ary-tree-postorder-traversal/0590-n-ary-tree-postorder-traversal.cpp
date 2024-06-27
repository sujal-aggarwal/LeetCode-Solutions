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
    vector<int> postorder(Node* root) {
        if(root==nullptr)return vector<int>();
        vector<int>ans;
        vector<Node*> arr=root->children;
        for(int i=0;i<arr.size();i++){
            vector<int> a=postorder(arr[i]);
            ans.insert(ans.end(), a.begin(), a.end());
        }
        ans.push_back(root->val);
        return ans;
    }
};