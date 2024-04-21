class Solution {
public:
    bool check=0;
    void dfs(vector<vector<int>> &adj,int source,int destination,vector<int> &vis)
    {
        vis[source]=1;
        if(source==destination)
        {
            check=1;
            return;
        }
        for(auto x:adj[source])
        {
            if(vis[x]==0)
            {
                dfs(adj,x,destination,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //DFS 
        vector<vector<int>> adj(n);
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        dfs(adj,source,destination,vis);
        return check;
    }
};