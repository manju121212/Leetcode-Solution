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
  int maxi = 0;
  TreeNode* findLCA(TreeNode* root , unordered_map<int,int>&mpp){
         
         if(root == NULL){
            return NULL;
         }

         if(mpp[root->val] == maxi ){
              return root;
         }

         TreeNode* left = findLCA(root->left,mpp);
         TreeNode* right = findLCA(root->right , mpp);

         if(left != NULL && right !=NULL){
            return root;
         }
         else if(left !=NULL && right==NULL){
            return left;
         }
         else{
            return right;
         }

  }

   
   void solve(TreeNode* root, int level , unordered_map<int,int>&mpp){
        
        if(root == NULL){
            return ;
        }
        maxi = max(maxi , level);
        mpp[root->val] = level;
        solve(root->left, level+1,mpp);
        solve(root->right , level+1,mpp);

        return ;


   }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         

         unordered_map<int,int>mpp;

         solve(root,0,mpp);

        

         return findLCA(root,mpp);
    }
};