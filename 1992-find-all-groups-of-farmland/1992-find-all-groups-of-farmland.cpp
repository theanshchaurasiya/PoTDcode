class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& land,
             vector<vector<int>>& visited, vector<int>& temp, int n, int m) {
        if (x >= n || y >= m || x < 0 || y < 0 || land[x][y] == 0 ||
            visited[x][y] == 1) {
            return;
        }
        visited[x][y] = 1;
        if (x >= temp[2] && y >= temp[3]) {
            temp[2] = x;
            temp[3] = y;
        }
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newx = x + delx[i];
            int newy = y + dely[i];
            dfs(newx, newy, land, visited, temp, n, m);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && visited[i][j] == 0) {
                    vector<int> temp = {i, j, i, j};
                    dfs(i, j, land, visited, temp, n, m);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};