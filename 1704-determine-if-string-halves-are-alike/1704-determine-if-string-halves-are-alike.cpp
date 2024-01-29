class Solution {
public:
    bool halvesAreAlike(string s) {
    auto gud = [&](char c) -> bool {
            return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
        };
        
        int n = s.size();
        
        int cur = 0;
        
        for(int i = 0; i < n / 2; i++){
            cur += gud(tolower(s[i]));
        }
        
        for(int i = n / 2; i < n; i++){
            cur -= gud(tolower(s[i]));
        }
        
        return cur == 0;
    }
};