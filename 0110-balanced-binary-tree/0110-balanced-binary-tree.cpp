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
    pair<int,bool>solve(TreeNode* root){
           if(root == NULL){
               return {0,true};
           }

           if(root->left == NULL && root->right ==NULL){
                  return {1,true};
           }

           pair<int,bool>left = solve(root->left);
           pair<int,bool>right = solve(root->right);

           bool diff = abs(left.first-right.first)<=1?true : false;

          if(diff == true && left.second == true && right.second == true)
               {
                int height = 1+max(left.first,right.first);
                return {height,true};

          }
          else{
               return {1e9,false};
          }
    }
    bool isBalanced(TreeNode* root) {
        
        pair<int,bool>p = solve(root);

        return p.second;
    }
};