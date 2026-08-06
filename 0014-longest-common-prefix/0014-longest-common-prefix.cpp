#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Start with the first string as the potential prefix
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            // While the current string doesn't start with 'prefix'
            // find returns 0 if 'prefix' is at the very start
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by one character from the end
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If there's no common prefix, return empty
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};