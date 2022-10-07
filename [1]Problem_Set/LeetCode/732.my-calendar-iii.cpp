/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int, int> diff;
    int book(int start, int end) {
        diff[start]++;
        diff[end]--;

        int cur=0, res=0;
        for(auto x:diff){
            cur+=x.second;
            res=max(cur, res);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

