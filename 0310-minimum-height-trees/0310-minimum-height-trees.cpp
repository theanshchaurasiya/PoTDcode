class Solution {
public:
    void dfs(int node, int parent, vector<int> adj[], vector<int>& distance) {
        if (parent == -1) {
            distance[node] = 0;
        } else
            distance[node] = distance[parent] + 1;
        for (auto x : adj[node]) {
            if (x != parent) {
                dfs(x, node, adj, distance);
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int x = 0;
        vector<int> distX(n, 0);
        dfs(x, -1, adj, distX);
        int y = 0;
        for (int i = 0; i < n; i++) {
            if (distX[i] > distX[y]) {
                y = i;
            }
        }
        vector<int> distY(n, 0);
        dfs(y, -1, adj, distY);
        int z = 0;
        for (int i = 0; i < n; i++) {
            if (distY[i] > distY[z]) {
                z = i;
            }
        }
        int diameter = *max_element(distY.begin(), distY.end());
        int minHeight = (diameter + 1) / 2;
        vector<int> distZ(n, 0);
        dfs(z, -1, adj, distZ);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (max(distY[i], distZ[i]) == minHeight)
                ans.push_back(i);
        }
        return ans;
    }
};