class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        set<char> st;
        map<char, char> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] != t[i])
                    return false;
            } else {
                if (st.find(t[i]) != st.end())
                    return false;
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }
        }
        return true;
    }
};