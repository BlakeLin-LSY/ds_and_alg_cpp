/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA=(ax2-ax1)*(ay2-ay1);
        int areaB=(bx2-bx1)*(by2-by1);

        int x_ab=0, y_ab=0;

        if(ax2<bx1 || ax1>bx2) x_ab=0;
        else if(ay2<by1 || ay1>by2) y_ab=0;
        else{
            x_ab=(ax2-ax1)+(bx2-bx1)-abs((bx1-ax1))-abs((bx2-ax2)); // 0 -> overlapp entirely, <0 -> no overlap
            y_ab=(ay2-ay1)+(by2-by1)-abs((by1-ay1))-abs((by2-ay2));

            x_ab/=2;
            y_ab/=2;
            
            if(x_ab<0 || y_ab<0) return areaA+areaB;
        }

        return areaA+areaB-(x_ab*y_ab);

    }
};
/*
:
    Return
        total area, covered by the two rectangles

        Rectangles are presented by bottom-left corner and top-right corner

# Idea:
    ## 1st
        Math, A1 + B1 - Union(A1, B1)
    1. Transfer ax1, ax2, ay1, ay2, bx1, bx2, by1, by2 -> to pairs
    2. find [ax1, ax2] intersection with [bx1, bx2]
    3. find [ay1, ay2] intersection with [by1, by2]
    4. compute A1 + B1 - Union(A1, B1)
    >> |ax1-ax2|*|ay1-ay2| + |bx1-bx2|*|by1-by2| - x_ab*y_ab

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. x_a+x_b - abs(x_a1b1) - abs(xa2b2) = 2* x_ab
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

00:05:  Read problem and constrcut 1st idea
00:25:  Implement the relation fomula (but not verified yet)

# Note:

3080/3080 cases passed (22 ms)
Your runtime beats 27.16 % of cpp submissions
Your memory usage beats 95.59 % of cpp submissions (5.7 MB)

TC: O(1)
SC: O(1)

========================================
Day-17, Leetcode November Challenge Study Room Event
*/
// @lc code=end

