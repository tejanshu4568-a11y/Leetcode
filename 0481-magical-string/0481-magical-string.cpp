#include <string>
#include <vector>

class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        std::vector<int> s = {1, 2, 2};
        int head = 2; // Pointer to the group size
        int count = 1; // Count of '1's

        while (s.size() < n) {
            int numToAppend = (s.back() == 1) ? 2 : 1;
            int times = s[head];

            for (int i = 0; i < times && s.size() < n; ++i) {
                s.push_back(numToAppend);
                if (numToAppend == 1) count++;
            }
            head++;
        }

        return count;
    }
};