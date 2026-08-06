/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // 1. Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // 2. Found the node! Handle deletion cases:
            
            // Case 1 & 2: Leaf or one child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            // Find the inorder successor (smallest in right subtree)
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            
            // Copy successor's value to current node
            root->val = successor->val;
            
            // Delete the successor node in the right subtree
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};