#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Construct a new string: original + separator + reversed
        // The separator '#' ensures the prefix doesn't overlap past the middle
        string temp = s + "#" + rev_s;
        int n = temp.size();
        
        // KMP LPS (Longest Proper Prefix which is also Suffix) array
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // The last value in LPS tells us the length of the longest palindromic prefix
        int longestPrefixLen = lps.back();
        string suffixToAdd = s.substr(longestPrefixLen);
        reverse(suffixToAdd.begin(), suffixToAdd.end());
        
        return suffixToAdd + s;
    }
};