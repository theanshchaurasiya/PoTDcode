class Solution {
public:
    vector<string> neighbors(string str) {
        vector<string> ans;
        for (int i = 0; i < 4; i++) {
            string temp = str;
            temp[i] = (temp[i] + 1 - '0' + 10) % 10 + '0';
            ans.push_back(temp);
            temp[i]--;
            temp[i] = (temp[i] - 1 - '0' + 10) % 10 + '0';
            ans.push_back(temp);
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string> de;
        for (auto x : deadends)
            de.insert(x);
        queue<string> pendingNodes;
        int rotations = 0;
        pendingNodes.push("0000");
        if (de.find("0000") != de.end()) {
            return -1;
        }
        de.insert("0000");
        while (!pendingNodes.empty()) {
            int sz = pendingNodes.size();
            for (int i = 0; i < sz; i++) {
                string front = pendingNodes.front();
                pendingNodes.pop();
                if (front == target)
                    return rotations;
                // 0000 ----->10000, 9000, 0100, 0900
                for (auto x : neighbors(front)) {
                    if (de.find(x) == de.end()) {
                        pendingNodes.push(x);
                        de.insert(x);
                    }
                }
            }
            rotations++;
        }
        return -1;
    }
};
