#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> counts(26, 0);
        int left = 0, maxCount = 0, maxLength = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // Increment count of current character and track the most frequent char in window
            maxCount = std::max(maxCount, ++counts[s[right] - 'A']);
            
            // Current window size is (right - left + 1)
            // Number of characters to replace = (window size - count of most frequent char)
            while ((right - left + 1) - maxCount > k) {
                counts[s[left] - 'A']--;
                left++;
            }
            
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};