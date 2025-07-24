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
   TreeNode* succ(TreeNode* root){
       TreeNode* prev = root;

       while(root!=NULL){
             prev = root;
             root = root->left;
       }
       return prev;

   }
    TreeNode* solve(TreeNode* root , int x){
           if(root == NULL){
                 return root;
           }

           if(root->val == x){
                  if(root->left == NULL && root->right == NULL){
                           return NULL;
                  }
                  else if(root->left != NULL && root->right == NULL){
                       return root->left;
                  }
                  else if(root->left == NULL && root->right != NULL){
                       return root->right;
                  }
                  else{
                      TreeNode* node = succ(root->right);
                      root->val  = node->val;
                      root->right = solve(root->right,root->val);
                      return root;

                  }

           }
           else if(root->val > x){
               root->left = solve(root->left,x);
           }
           else{
               root->right = solve(root->right,x);
           }
           return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return solve(root,key);
    }
};