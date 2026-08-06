#include <vector>
#include <string>

class Solution {
public:
    void backtrack(std::string& s, int start, std::vector<std::string>& current, std::vector<std::string>& result) {
        // Base case: If we have 4 segments and reached the end of the string
        if (current.size() == 4) {
            if (start == s.length()) {
                result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            }
            return;
        }

        // Try segments of length 1, 2, and 3
        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.length()) break;

            std::string segment = s.substr(start, len);
            int val = std::stoi(segment);

            // Validation: 
            // 1. Value must be <= 255
            // 2. No leading zeros (e.g., "01" is invalid, but "0" is fine)
            if (val > 255 || (len > 1 && segment[0] == '0')) continue;

            current.push_back(segment);
            backtrack(s, start + len, current, result);
            current.pop_back(); // Undo choice
        }
    }

    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        std::vector<std::string> current;
        if (s.length() < 4 || s.length() > 12) return result;
        backtrack(s, 0, current, result);
        return result;
    }
};