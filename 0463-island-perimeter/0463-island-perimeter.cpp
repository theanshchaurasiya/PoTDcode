class Solution {
public:
    int contribution(int x, int y, vector<vector<int>>& grid, int n, int m) {
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int newx = x + delx[i];
            int newy = y + dely[i];
            if (newx >= n || newy >= m || newx < 0 || newy < 0 ||
                grid[newx][newy] == 0) {
                count++;
            }
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    perimeter += contribution(i, j, grid, n, m);
                }
            }
        }
        return perimeter;
    }
};