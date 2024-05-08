class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++)
        {
            v.push_back({score[i],i});
        }

        sort(v.rbegin(),v.rend());

        vector<string> ans(n);
        
        vector<string> ranks={"Gold Medal","Silver Medal","Bronze Medal"};
        for(int i=0;i<n;i++)
        {
            int ind=v[i].second;
            if(i<=2)
            ans[ind]=ranks[i];

            else ans[ind]=to_string(i+1);
        }

        return ans;
    }
};