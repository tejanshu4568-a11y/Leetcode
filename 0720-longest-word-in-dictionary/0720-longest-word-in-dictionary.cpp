#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        // Sort words lexicographically
        sort(words.begin(), words.end());
        
        unordered_set<string> built;
        string result = "";
        
        for (const string& w : words) {
            // If the word is a single char or its prefix exists in the set
            if (w.length() == 1 || built.count(w.substr(0, w.length() - 1))) {
                built.insert(w);
                
                // Update result if current word is longer
                if (w.length() > result.length()) {
                    result = w;
                }
            }
        }
        
        return result;
    }
};