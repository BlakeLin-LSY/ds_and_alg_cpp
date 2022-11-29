/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> valueToIndex;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valueToIndex.count(val)) return false;
        else{
            int id=nums.size();
            nums.push_back(val);
            valueToIndex[val]=id;
            return true;
        }
    }
    
    bool remove(int val) {
        if(valueToIndex.count(val)){
            int id=valueToIndex[val];
            valueToIndex[nums.back()]=id;
            swap(nums[id], nums.back());
            nums.pop_back();
            valueToIndex.erase(val);
            return true;
        }else return false;
    }
    
    int getRandom() {
        int id=rand()%nums.size();
        return nums[id];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
/*
:
    Set function implementation -> in average O(1) time complexity
    1. Insert
    2. Remove
    3. GetRandom

# Idea:
    ## 1st
        Initialize, choose proper data structure, implement insert, remove and random
    1. Using hash map to check existance
    2. Insertion to vector
    3. Remove in O(1) -> hash map can be done, but how about randomize
    4. Random generator by size of total set

    >> How about directly using "unordered_set" ?

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. Design
      2. 

00:02:  Read problem
00:11:  Finish 1st idea go through
--> Check unordered_set & set
https://cplusplus.com/reference/set/set/
https://cplusplus.com/reference/unordered_set/unordered_set/
00:14:  Dropped -> check others solution
00:25:  Fisrt Implementation (after read the idea)
00:36:  Passed (update the back index with to-be-removed id)

# Note:

    所以，如果我们想在 O(1) 的时间删除数组中的某一个元素 val，
    可以先把这个元素交换到数组的尾部，然后再 pop 掉。

    !! Need to update swapped value index

19/19 cases passed (363 ms)
Your runtime beats 72.04 % of cpp submissions
Your memory usage beats 58.37 % of cpp submissions (97.1 MB)

TC: O(1)
SC: O(N) -> depends on the insert counts

========================================
Day-29, Leetcode November Challenge Study Room Event
*/
// @lc code=end

