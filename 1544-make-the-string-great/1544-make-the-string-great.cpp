class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        stack<char> ss;
        int diff = abs('a' - 'A');
        for (int i = 0; i < n; i++) {
            if (!ss.empty() && diff == abs(s[i] - ss.top())) {
                ss.pop();
            } else
                ss.push(s[i]);
        }
        string ans;
        while (!ss.empty()) {
            ans.push_back(ss.top());
            ss.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
