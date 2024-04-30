class Solution {
public:
    typedef long long ll;

    long long wonderfulSubstrings(string word) {
        int n=word.size();
        ll ans=0,mask=0;
       
        // 2^10 -> 1024
        unordered_map<ll,int> mp;

        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            int val=(1<<(word[i]-'a'));
            mask^=val;

            ans+=mp[mask];

            for(int j=0;j<10;j++) // 1 odd occurence char
            {
                int new_mask=mask^(1<<j);
                ans+=mp[new_mask];
            }

            mp[mask]++;
        }

        return ans;

    }
};