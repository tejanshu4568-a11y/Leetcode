#include <vector>
using namespace std;

class NumArray {
    vector<int> tree;
    int n;

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return 0; // Out of range
        if (L <= start && end <= R) return tree[node]; // Fully in range
        
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, L, R) + 
               query(2 * node + 1, mid + 1, end, L, R);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(4 * n); // Rule of thumb for segment tree size
            build(nums, 1, 0, n - 1);
        }
    }

    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};