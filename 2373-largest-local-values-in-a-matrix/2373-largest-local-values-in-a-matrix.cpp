class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>> ans;

        for(int p=0;p<=n-3;p++)
        {
            vector<int> temp;
            for(int q=0;q<=n-3;q++)
            {
                int mx=0;
                for(int i=p;i<p+3;i++)
                {
                    for(int j=q;j<q+3;j++)
                    {
                        mx=max(mx,grid[i][j]);
                    }
                }
                temp.push_back(mx);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};