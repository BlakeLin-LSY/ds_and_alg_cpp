/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double res;
        if(n==0) return double(1.0);
        if(n==-1) return double(1.0)/x;
        
        res=myPow(x*x, n/2);
        
        if(n%2){
            if(n<0) res/=x;
            else res*=x;
        } 
        return res;
    }
};
/*
:
    power function, note the limit(boundary);

# Idea:
    ## 1st
        Math formula to compute power value, divide and conquer
    1. split n by 2 --> x^n == x(n/2) * x(n/2), reduce half compute time
    2. recursive function myPow

    ### Edge Case:
      1. Base case (n==0 --> return 1)
      2. Negative n --> x^(-2)=1/(x^2)
      3. Negative n from -1 to -val (using recursive)
      **4**. -1/2 --> still -1 instead of 0;
      **5**. n==INT_MIN or INT_MAX; --> TLE

    ### Key Points:
      1. negative number with odd power n --> give negative value
      2. storage range for the number --> int (10^9) --> however, x^n range is confined.
      3. large n (-2^31 ~ 2^31-1) --> can not use for loop (will cause TLE)

    ### Any Improvement Ideas / Related Questions:
      - Space complexity
      - Cleaner (more consice) code

# Note:

TC: O(logN)
SC: O(logN) --> recursive, which can be improved

========================================
Day-01(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

