#include <string>
#include <algorithm>
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if (count > 0 && count % k == 0) {
                    result += '-';
                }
                result += toupper(s[i]);
                count++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};