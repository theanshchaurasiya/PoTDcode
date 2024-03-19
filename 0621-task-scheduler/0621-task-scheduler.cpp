class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int frequency[26] = {0};
        for (auto x : tasks) {
            frequency[x - 'A']++;
        }
        int maxFrequency = 0, count = 0;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > maxFrequency) {
                maxFrequency = frequency[i];
                count = 1;
            } else if (frequency[i] == maxFrequency) {
                count++;
            }
        }
        int segment = maxFrequency - 1;
        int emptyPerSegment = n - (count - 1);
        int totalEmpty = segment * emptyPerSegment;
        int remainingTasks = tasks.size() - (maxFrequency * count);
        int idleness = max(0, totalEmpty - remainingTasks);
        return tasks.size() + idleness;
    }
};