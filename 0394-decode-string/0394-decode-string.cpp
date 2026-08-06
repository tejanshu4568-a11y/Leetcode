#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    string decodeString(string s) {
        std::stack<int> countStack;
        std::stack<string> resStack;
        std::string currentRes = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // Build the number (k) in case it's more than one digit
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                // Push the current multiplier and the string built so far
                countStack.push(k);
                resStack.push(currentRes);
                // Reset for the new scope inside brackets
                k = 0;
                currentRes = "";
            } else if (c == ']') {
                // Pop the multiplier and the previous string
                int repeatTimes = countStack.top();
                countStack.pop();
                std::string temp = currentRes;
                
                // Repeat currentRes repeatTimes
                for (int i = 1; i < repeatTimes; i++) {
                    currentRes += temp;
                }
                
                // Prepend the string that was built before the '['
                currentRes = resStack.top() + currentRes;
                resStack.pop();
            } else {
                // It's a regular character, just append it
                currentRes += c;
            }
        }
        return currentRes;
    }
};