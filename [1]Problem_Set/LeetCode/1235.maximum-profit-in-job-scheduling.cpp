/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i=0; i<startTime.size(); ++i){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp={{0, 0}};      // {endTime, profit}
        // map<int, int> dp;
        // dp[0]=0;
        for(auto &job:jobs){
            // dp.upper_bound(job[1])           --> usually meet the dp.end()
            // prev(dp.upper_bound(job[1]))     --> prev(dp.upper_bound()) --> reach the last
            int cur=prev(dp.upper_bound(job[1]))->second+job[2];
            // dp.rbegin()->second    --> the previous profit
            if(cur>dp.rbegin()->second){            // Add to dp
                dp[job[0]]=cur;
            }
        }
        return dp.rbegin()->second;
    }
};
/*
:
    Scheduling problem, to find a maximum profit.

# Idea:
    job = [e, s, p] -> e: endTime, s: startTime, p: profit
    
    1. Push job to vector<vector<int>> jobs
    2. Sort job with endTime
    3. Binary search to find current profit (upper_bound())
    4. prev() to the upper_bound()
    5. Find if there is any larger profit job
    6. store the job and total profit into map --> which have order, and as dp
    7. return the last term of map (the larget total profit)

5 minutes to read problem and examples.
5 minutes try to figure out some idea... (not accomplished)

# Note:
    Reference (Lee215)
    https://leetcode.com/problems/maximum-profit-in-job-scheduling/solutions/409009/

TC: O(N*logN)
SC: O(N)

========================================
Day-0x, Leetcode November Challenge Study Room Event
*/
// @lc code=end

