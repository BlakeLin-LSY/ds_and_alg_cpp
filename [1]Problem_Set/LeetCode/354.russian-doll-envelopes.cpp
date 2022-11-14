/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    static bool mComp(vector<int>& e1, vector<int>& e2){
        return e1[0]<e2[0] || (e1[0]==e2[0] && e1[1]>e2[1]);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort(envelopes.begin(), envelopes.end(), mComp);
        sort(envelopes.begin(), envelopes.end(), 
            [&](vector<int>& e1, vector<int>& e2){
                return e1[0]<e2[0] || (e1[0]==e2[0] && e1[1]>e2[1]);
                });

        vector<int> dp;
        for(auto &e:envelopes){
            auto it=lower_bound(dp.begin(), dp.end(), e[1]);
            if(it==dp.end()) dp.push_back(e[1]);
            else *it=e[1];       // case 29/87, to update [3,5], [3,4] case;
        }
        return dp.size();
    }
};
/*
:
    Compare envelopes --> w_i > w_i+1 && h_i > h_i+1

# Idea:
    ## 1st
        Sort envelopes, pick from largest one

    ### Key Points:
      1. DFS
      2. Edge case size are equal
      3. "Backtrack"

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

5 minute finish problem comprehension,
20 minute finish first idea,
meet bug --> dropped.

# Note:
    Case 36/87:
        [[46,89],[50,53],[52,68],[72,45],[77,81]]       // 3

    Case 29/87:
        [[1,2],[2,3],[3,4],[3,5],[4,5],[5,5],[5,6],[6,7],[7,8]]     // 7

        sorted:
        [[1,2],[2,3],[3,5],[3,4],[4,5],[5,6],[5,5],[6,7],[7,8]]

    Case 86/87 && 87/87:
        use static bool comparison, else will cause the TLE

    !LIS!
    Longest Increasing Sequence

TC: O(N^2) -> TLE at case 85/87
    O(N*logN)  reference: https://leetcode.com/problems/russian-doll-envelopes/solutions/82798
SC: O(N)
*/
// @lc code=end

