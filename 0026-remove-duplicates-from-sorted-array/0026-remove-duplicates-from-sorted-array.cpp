class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int pos = 0;

        // cache reference to avoid repeated indexing
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[pos]) {
                nums[++pos] = nums[i];
            }
        }

        return pos + 1;
    }
};