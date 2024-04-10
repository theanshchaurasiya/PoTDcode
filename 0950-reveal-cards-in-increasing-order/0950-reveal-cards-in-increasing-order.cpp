class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        reverse(deck.begin(), deck.end());
        deque<int> q;
        q.push_back(deck[0]);
        for (int i = 1; i < n; i++) {
            q.push_front(q.back());
            q.pop_back();
            q.push_front(deck[i]);
            // reveal, push,......
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};