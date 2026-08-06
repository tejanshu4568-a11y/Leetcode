#include <vector>

class Solution {
public:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: If the combination is the required size
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Optimization: Stop if there aren't enough numbers left to fill k slots
        // i <= n - (k - current.size()) + 1
        for (int i = start; i <= n; i++) {
            current.push_back(i);          // Choose the number
            backtrack(i + 1, n, k, current, result); // Move to the next number
            current.pop_back();            // Backtrack (Undo the choice)
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};