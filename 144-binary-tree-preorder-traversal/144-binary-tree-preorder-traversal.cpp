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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL) 
            return {};
        vector<int> result;
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode *temp = treeStack.top();
            result.push_back(temp->val);
            treeStack.pop();
            if (temp->right!=NULL) 
                treeStack.push(temp->right);
            if (temp->left!=NULL) 
                treeStack.push(temp->left);
        }
        return result;
    }
    
    /*
    void helper(TreeNode* root, vector <int> &v) {
        if(root==NULL)
            return;
        v.push_back(root->val);
        helper(root->left, v);
        helper(root->right, v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> v;
        helper(root, v);
        return v;
    }
    */
};