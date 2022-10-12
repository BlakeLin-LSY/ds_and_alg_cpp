/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // Search from the end;

        for(int i=nums.size()-3; i>=0; --i){
            if(nums[i]+nums[i+1] > nums[i+2]) return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};


/*
:
    Largest perimeter(of Triangle) == 3 side length sum.


# A math problem
    Definition of Triangle
    - Find combinations which make the triangle has largest perimeter.
    (a, b, c) a<=b<=c
    1. a+b > c

    海龍公式(Heron's formula)? --> using sum of three sides to find area,
    s = (a+b+c)/2;
    A = sqrt(s*(s-a)*(s-b)*(s-c));

TC: O(N*logN)   --> Sort= O(N*logN)
SC: O(1)
*/
// @lc code=end

