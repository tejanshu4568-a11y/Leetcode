#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to count nodes between prefix and prefix + 1
    long countSteps(long n, long n1, long n2) {
        long steps = 0;
        while (n1 <= n) {
            steps += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k--; // We start at 1, so we need to find the (k-1)th step

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Skip this subtree
                curr++;
                k -= steps;
            } else {
                // Move deeper into the current subtree
                curr *= 10;
                k--;
            }
        }
        return (int)curr;
    }
};