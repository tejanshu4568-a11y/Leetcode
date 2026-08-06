#include <vector>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, int> mp;

    TreeNode* build(std::vector<int>& inorder, int inStart, int inEnd, 
                   std::vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(inorder, inStart, inRoot - 1, 
                           postorder, postStart, postStart + numsLeft - 1);
        root->right = build(inorder, inRoot + 1, inEnd, 
                            postorder, postStart + numsLeft, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, 
                     postorder, 0, postorder.size() - 1);
    }
};