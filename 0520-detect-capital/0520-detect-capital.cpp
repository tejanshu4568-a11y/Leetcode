class Solution {
public:
    bool detectCapitalUse(string word) {
        int caps = 0;
        for (char c : word) {
            if (isupper(c)) caps++;
        }
        if (caps == word.length() || caps == 0) return true;
        return caps == 1 && isupper(word[0]);
    }
};