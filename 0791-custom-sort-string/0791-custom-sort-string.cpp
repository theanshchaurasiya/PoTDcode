class Solution {
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int>map;
        for (int i=0;i<order.length();i++)
            map[order[i]] = i;
        auto customSort = [&](char a, char b)
        {
            return map[a]<map[b];
        };
        sort(s.begin(), s.end(), customSort);
        return s;
    }
};