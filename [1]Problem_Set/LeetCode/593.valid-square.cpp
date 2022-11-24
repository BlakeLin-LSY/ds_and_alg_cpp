/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */

// @lc code=start
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        float sumX=p1[0]+p2[0]+p3[0]+p4[0];
        float sumY=p1[1]+p2[1]+p3[1]+p4[1];
        sumX/=4.0;
        sumY/=4.0;
        vector<float> pc({sumX, sumY});
        float d12=d2(p1, p2);
        float dc1=d2(pc, p1);
        float dc2=d2(pc, p2);
        float dc3=d2(pc, p3);
        if(d12==0) return false;        // Edge case
        if(d2(p1, p2)==0) return false;        // Edge case
        if(d2(p1, p3)==0) return false;        // Edge case
        if(d2(p2, p3)==0) return false;        // Edge case
        
        bool res=true;
        res &= (d12==(dc1+dc2) || d12==(2*(dc1+dc2)));
        res &= (dc1==dc2 && dc1==dc3);
        return res;
    }

    float d2(vector<float>& pi, vector<int>& pf){
        float dx=pf[0]-pi[0];
        float dy=pf[1]-pi[1];
        dx*=dx;
        dy*=dy;
        return dx+dy;
    }
    
    float d2(vector<int>& pi, vector<int>& pf){
        float dx=pf[0]-pi[0];
        float dy=pf[1]-pi[1];
        dx*=dx;
        dy*=dy;
        return dx+dy;
    }
};
/*
:
    p1, p2, p3, p4 -> four points (x, y) in 2D space.
    Check if these four point forms a "square"

# Idea:
    ## 1st
        Define square, distance, degree, relative vector, center to 4 points
    1. Distance, pi to pj, center to 4 points
    2. Need check degree -> add d(p1, p2) == sqrt(d(pc, p1)^2, d(pc, p2)^2)

    ### Edge Case:
      1. all 4 points at same position
      2. any 2 points at same position

    ### Key Points:
      1. Condition check (distance and degree)
      2. 

00:01:  Read problem
00:12:  Finish first implementation
00:50:  Debug all the edge cases...

# Note:

    # Center to four points distance 
    -> failed @ case 250/254
            [0,0]
            [5,0]
            [5,4]
            [0,4]
                    >> false

254/254 cases passed (4 ms)
Your runtime beats 93.3 % of cpp submissions
Your memory usage beats 99.29 % of cpp submissions (26.4 MB)

TC: O(1)
SC: O(1)

========================================
Day-24, Leetcode November Challenge Study Room Event
*/
// @lc code=end

