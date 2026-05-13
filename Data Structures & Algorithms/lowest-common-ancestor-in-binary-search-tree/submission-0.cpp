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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //start current from root
        //if p and q are on less and greater than root, return current
        //if both on same side, update current to that side
        if(p->val == q->val) return p; 
        TreeNode* smaller = (p->val < q->val)? p : q; 
        TreeNode* larger = (p->val > q->val)? p : q;
        TreeNode* current = root; 
        while(current != smaller){
            if(larger->val == current->val) return current; 
            else if(smaller->val < current->val && larger->val > current->val){
                return current; 
            }
            else if(smaller->val < current->val){
                current = current->left; 
            }
            else{
                current = current->right;
            }
        }
        return current; 
    }
};
