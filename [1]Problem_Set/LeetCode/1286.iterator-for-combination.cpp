/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
class CombinationIterator {
public:
    vector<string> v;
    int i=0;
    CombinationIterator(string characters, int combinationLength) {
        generateCombination(characters, combinationLength, 0, "");
    }
    
    void generateCombination(string s, int len, int start, string res){
        if(s.empty()) return;
        if(res.size()==len){
            v.push_back(res);
            return;
        }
        for(int j=start; s[j]; ++j) generateCombination(s, len, j+1, res+s[j]);
    }

    string next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i<v.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
:
    CombinationIterator Class design
    1. Initialize sorted characters, length of combinations
    (combinationLength <= characters.size() <= 15)
    2. next()
    3. hasNext()

# Idea:
    ## 1st
        Finish initialization function (constructor), create combination vector, check combinations
    1. Sort unique characters   --> already sorted
    2. Create space to store combinations (with given length and characters)
    3. How to create a combinations with lexicographical order

    ### Edge Case:
      1. length == 1  --> return sorted character list
      2. 

    ### Key Points:
      1. All characters are unique
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

# Note:
    Reference:
    https://leetcode.com/problems/iterator-for-combination/solutions/1166357


for initialization
TC: O(N*logN + N!/(N-k)!/k!)       --> k == combinationLength
SC: O(N!/(N-k)!/k!)

========================================
Day-09(extra), Leetcode November Challenge Study Room Event
    backtrack, dfs
*/
// @lc code=end

