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
    int pre_idx = 0; 
    unordered_map<int, int> inorder_idx; 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorder_idx[inorder[i]] = i;
        }
        return buildSubTree(preorder, 0, inorder.size()-1); 
    }
private:
    TreeNode* buildSubTree(vector<int>& preorder, int l, int r){
        if(l > r) return nullptr; 
        int rootVal = preorder[pre_idx++];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIdx = inorder_idx[rootVal];

        root->left = buildSubTree(preorder, l, rootIdx - 1);
        root->right = buildSubTree(preorder, rootIdx + 1, r); 

        return root; 
    }
};
