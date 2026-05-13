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
    int globalMax = -1e9; 
    int maxPathSum(TreeNode* root) {

        return max(globalMax, maxSubPath(root));
    }

private:
    int maxSubPath(TreeNode* root){
        if(!root) return 0;
        int left = max(0, maxSubPath(root->left));
        int right = max(0, maxSubPath(root->right));

        globalMax = max(globalMax, left + right + root->val); 

        return root->val + max(left, right); 
    }
};
