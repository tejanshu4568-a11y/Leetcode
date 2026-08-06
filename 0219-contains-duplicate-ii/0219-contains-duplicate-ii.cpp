#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> lastSeen;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the number has been seen before
            if (lastSeen.find(nums[i]) != lastSeen.end()) {
                // Check if the distance condition is met
                if (i - lastSeen[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the map with the latest index of the number
            lastSeen[nums[i]] = i;
        }
        
        return false;
    }
};