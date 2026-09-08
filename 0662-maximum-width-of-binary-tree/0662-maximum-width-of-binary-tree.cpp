class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIdx = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                auto [node, idx] = q.front();
                q.pop();

                unsigned long long currIdx = idx - minIdx;

                if (i == 0) first = currIdx;
                if (i == size - 1) last = currIdx;

                if (node->left) q.push({node->left, 2 * currIdx + 1});
                if (node->right) q.push({node->right, 2 * currIdx + 2});
            }

            maxWidth = max(maxWidth, static_cast<int>(last - first + 1));
        }

        return maxWidth;
    }
};