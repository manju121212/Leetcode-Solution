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
    int solve(TreeNode* root){
           if(root == NULL){
               return 0;
           }

           int left = solve(root->left);
           int right = solve(root->right);
           
           if(left !=0 && right !=0){
                  return 1 + min(left,right);
           }
           else if(left == 0 && right!=0){
                  return 1 + right;
           }
           else{
                return 1 + left;
           }
           
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};