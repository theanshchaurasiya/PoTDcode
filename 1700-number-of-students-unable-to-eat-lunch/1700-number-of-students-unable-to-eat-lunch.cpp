class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[] = {0, 0};
        for (auto x : students) {
            count[x]++;
        }
        int i = 0;
        int n = sandwiches.size();
        while (i < n && count[sandwiches[i]] > 0) {
            count[sandwiches[i]]--;
            i++;
        }
        return n - i;
    }
};