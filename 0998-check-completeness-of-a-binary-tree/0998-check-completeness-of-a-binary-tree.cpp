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
    int count = 0;
    int n = 0;
    bool solve(TreeNode* root , int level){
           if(root == NULL){
               return true;
           }
           
           if(n<=level){
               return false;
           }

           return solve(root->left,2*level+1) and solve(root->right,2*level+2);
           
    }
    void countNodes(TreeNode* root){
            if(root == NULL){
                  return ;
            }

            countNodes(root->left);
            count++;
            countNodes(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
        
        countNodes(root);
        n = count;
        return solve(root,0);
    }
};