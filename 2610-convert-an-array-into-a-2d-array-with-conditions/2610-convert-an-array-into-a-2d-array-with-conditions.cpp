class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
         unordered_map<int, int> f;
        
        for(auto i : nums)
            ++f[i];
        
        int size = 0;
        
        for(auto i : f)
            size = max(size, i.second);
        
        vector<vector<int>> ans(size);
        
        for(auto i : f){
            for(int j = 0; j < i.second; j++)
                ans[j].push_back(i.first);
        }
        
        return ans;
    }
};