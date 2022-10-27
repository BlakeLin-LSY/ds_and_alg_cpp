/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0, k=2*n+1;
        unordered_map<int, int> mp;
        vector<int> x, y;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(img1[i][j]==1) x.push_back(i*k+j);
                if(img2[i][j]==1) y.push_back(i*k+j);
            }
        }
        for(auto& i:x){
            for(auto& j:y){
                mp[i-j]+=1;
            }
        }
        for(auto& v:mp) ans=max(ans, v.second);

        return ans;
    }
};
/*
:
    Largest possible overlap

# Idea
    1. Count 1 values in img1 & img2
    (2.) translation of 1 (n*n) image -> n*n possibles
    (3.) separate to row and column
    (4.) start from largest count (img)

>> No idea for further implementation (check solution)
    Official Solution: 
    https://leetcode.com/problems/image-overlap/solutions/775016/official-solution/

    Nice and elegant one:
    [Brute Force]https://github.com/martin0327/LeetCode/blob/main/0835-image-overlap/0835-image-overlap.cpp
    [Map]https://leetcode.com/problems/image-overlap/submissions/831112608/


TC: O(n^2 * n^2) --> Brute Force
    Optimal --> still O(n^4)
SC: O(n)

*/
// @lc code=end

