class Solution {
public:
    // what we need 
    vector<int> subtree,subdist,parent,final_ans;
    int total=0;
    void solve(int node, int par, vector<vector<int>> &adj)
    {
        parent[node] =par;

        for(auto x:adj[node])
        {
            if(x!=par)
            {
                solve(x,node,adj);
                subtree[node]+=subtree[x];
                subdist[node]+=subtree[x]+subdist[x];
            }
        }
    }

    void solve1(int node,int par,vector<vector<int>> &adj)
    {
        if(par==-1)
        {
            final_ans[node]=subdist[node];
        }

        for(auto x:adj[node])
        {
            // cout<<node<<" "<<final_ans[node]<<endl;
            if(x!=par)
            {
                final_ans[x]= final_ans[node] + total - 2*subtree[x];
                solve1(x,node,adj);
            }
            
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        subtree.resize(n,1);
        subdist.resize(n,0);
        parent.resize(n,-1);
        final_ans.resize(n);
        total =n;
        vector<vector<int>> adj(n);
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        solve(0,-1, adj);

        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" "<<subtree[i]<<" "<<subdist[i]<<endl;
        // }

        solve1(0,-1,adj);

        return final_ans;
    }
};