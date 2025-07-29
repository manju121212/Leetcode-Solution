/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode* root, string& res) {
        if (!root) return;
        res += to_string(root->val) + " ";
        preorder(root->left, res);
        preorder(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        istringstream ss(data);
        vector<int> preorder;
        string val;
        while (ss >> val) {
            preorder.push_back(stoi(val));
        }

        int idx = 0;
        return build(preorder, idx, INT_MIN, INT_MAX);
    }

    TreeNode* build(const vector<int>& preorder, int& idx, int lower, int upper) {
        if (idx == preorder.size()) return nullptr;
        int val = preorder[idx];
        if (val < lower || val > upper) return nullptr;

        TreeNode* root = new TreeNode(val);
        idx++;
        root->left = build(preorder, idx, lower, val);
        root->right = build(preorder, idx, val, upper);
        return root;
    }
};
