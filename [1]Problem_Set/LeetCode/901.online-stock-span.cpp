/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
public:
    vector<pair<int, int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int curSpan=1;

        while(st.size()!=0 && st.back().first<=price){
            auto [prevPrice, prevSpan]=st.back();
            st.pop_back();
            curSpan+=prevSpan;
        }
        st.push_back({price, curSpan});
        return curSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 *
 * /

/*
:
    Return span of the price (comparing to previous prices, count number)
    "monotonic stack"

# Idea:
    ## 1st
        Constructor, member function create
    1. Simple for loop to go through vector --> TLE @ 99/99 cases
    2. Accumulate spans, else(b)

    ### Edge Case:
      1. First price edge case, always return 1
      2. 

    ### Key Points:
      1. Constrcutor initialization
      2. Member function implementation

    ### Any Improvement Ideas / Related Questions:
      - TLE if not optimized vector to stack
      - 

# Note:
    1. *Consecutive* day  >> [60, 60, 75, 60]  // [1, 2, 3, 1]

    Reference:
    https://leetcode.com/problems/online-stock-span/solutions/640396/
    https://leetcode.com/problems/online-stock-span/solutions/2178516/

TC: O(N)
SC: O(N)

========================================
Day-09, Leetcode November Challenge Study Room Event
*/
// @lc code=end

