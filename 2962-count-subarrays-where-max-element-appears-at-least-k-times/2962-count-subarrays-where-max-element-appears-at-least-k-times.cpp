class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int n= nums.size(),j=0;
        ll ans=0,cnt=0,mx=0;

        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]*1ll);
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]==mx)
            {
                cnt++;
            }

            while(j<=i && cnt>=k)
            {
                ans+=n-i;
                if(nums[j]==mx)
                cnt--;
                j++;
            }
        }
        return ans;
    }
};