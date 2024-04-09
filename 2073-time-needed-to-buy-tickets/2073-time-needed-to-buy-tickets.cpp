class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int numberOfTickets = tickets[k];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i <= k) {
                ans += min(numberOfTickets, tickets[i]);
            } else {
                ans += min(numberOfTickets - 1, tickets[i]);
            }
        }
        return ans;
    }
};