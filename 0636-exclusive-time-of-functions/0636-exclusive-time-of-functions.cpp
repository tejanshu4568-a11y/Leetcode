#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> s;
        int prevTime = 0;
        
        for (const string& log : logs) {
            int firstColon = log.find(':');
            int lastColon = log.find_last_of(':');
            
            int id = stoi(log.substr(0, firstColon));
            string status = log.substr(firstColon + 1, lastColon - firstColon - 1);
            int timestamp = stoi(log.substr(lastColon + 1));
            
            if (status == "start") {
                if (!s.empty()) {
                    res[s.top()] += timestamp - prevTime;
                }
                s.push(id);
                prevTime = timestamp;
            } else {
                res[s.top()] += timestamp - prevTime + 1;
                s.pop();
                prevTime = timestamp + 1;
            }
        }
        return res;
    }
};