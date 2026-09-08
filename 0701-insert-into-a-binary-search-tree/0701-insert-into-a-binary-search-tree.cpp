class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        
        while (curr) {
            parent = curr;
            if (val > curr->val) curr = curr->right;
            else curr = curr->left;
        }
        
        if (val > parent->val) parent->right = new TreeNode(val);
        else parent->left = new TreeNode(val);
        
        return root;
    }
};