class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j])
                break;
            char toBeRemoved = s[i];
            while (i <= j && s[i] == toBeRemoved) {
                i++;
            }
            while (i <= j && s[j] == toBeRemoved)
                j--;
        }
        return j - i + 1;
    }
};