class Solution {
public:
    
    int f(int index, vector<vector<int>>& jobs, vector<int>& dp) {
        // base case : out of bound
        if (index == jobs.size()) return 0;
        
        // already calculated
        if (dp[index] != -1) return dp[index];

        // pick 
        vector<int> v = {jobs[index][1], 0, 0}; // we need to find lower bound for current job end time
                                                // w.r.t. next job start time
        int nextJobForPick = lower_bound(jobs.begin(), jobs.end(), v) - jobs.begin();
        int pickProfit = jobs[index][2] + f(nextJobForPick, jobs, dp);

        // not pick
        int nonPickProfit = f(index + 1, jobs, dp); 

        return dp[index] = max(pickProfit, nonPickProfit);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {   
        vector<int> dp(startTime.size(), -1);   // dp vector
        vector<vector<int>> jobs;      // convert 3 vectors to single job vector        
        for (int i = 0; i < profit.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());     // sort on start time

        // recurse - index, jobs
        return f(0, jobs, dp);
    }
};