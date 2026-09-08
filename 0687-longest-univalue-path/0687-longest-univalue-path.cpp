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
    int maxPath = 0;

public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return maxPath;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;

        // Recursive call to children
        int leftLen = dfs(node->left);
        int rightLen = dfs(node->right);

        int leftArrow = 0, rightArrow = 0;

        // If left child exists and has the same value, extend the path
        if (node->left && node->left->val == node->val) {
            leftArrow = leftLen + 1;
        }

        // If right child exists and has the same value, extend the path
        if (node->right && node->right->val == node->val) {
            rightArrow = rightLen + 1;
        }

        // The path through the current node is the sum of both directions
        maxPath = max(maxPath, leftArrow + rightArrow);

        // Return the longest single leg to the parent
        return max(leftArrow, rightArrow);
    }
};