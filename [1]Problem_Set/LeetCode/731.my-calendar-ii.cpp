/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int, int> diff;
    bool book(int start, int end) {
        diff[start]++;
        diff[end]--;
        int count=0;
        for(auto x:diff){
            count+=x.second;
            if(count >=3 ){
                diff[start]--;
                diff[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

