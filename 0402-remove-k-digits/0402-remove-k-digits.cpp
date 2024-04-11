class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char c : num) {
            while (ans.length() > 0 && k > 0 && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            if (ans.length() > 0 || c != '0')
                ans.push_back(c);
        }
        while (ans.length() > 0 && k > 0) {
            ans.pop_back();
            k--;
        }
        if (ans.empty())
            return "0";
        else
            return ans;
    }
};