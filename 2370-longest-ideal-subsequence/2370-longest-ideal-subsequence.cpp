class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();

        vector<int> index(26,-1);
        vector<int> dp(n,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(index[j]!=-1 && abs(s[i]-(j+'a'))<=k)
                {
                    dp[i]=max(dp[i],1+dp[index[j]]); //index[j] will given me previous
                                                      //index
                }
            }
            index[s[i]-'a']=i;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};