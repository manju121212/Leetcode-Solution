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
class FindElements {
public:
unordered_map<long,int>mpp;
    void solve(TreeNode* root){

        queue<pair<TreeNode*,long>>q;
        q.push({root,0});
        mpp[0] = 1;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0;i<size;i++){
                TreeNode* node = q.front().first;
                int x = q.front().second;
                q.pop();

                if(node->left != NULL){
                     long value = 2*x + 1;
                     mpp[value]++;
                     q.push({node->left,value});
                }
                if(node->right != NULL){
                    long value = 2*x + 2;
                    mpp[value]++;
                    q.push({node->right,value});
                }

                
            }
        }
    }
    FindElements(TreeNode* root) {
        solve(root);

    }
    
    bool find(int target) {
      
        if(mpp.find(target) != mpp.end()){
            return true;
        }
        else{
            return false;
        }
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */