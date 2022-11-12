/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
    priority_queue<int> small;  // Max-Heap, max value at top
    priority_queue<int, vector<int>, greater<int>> large;  // Min-Heap, min value at top
    double ans=0;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(small.size()>=large.size()){
            small.push(num);
            large.push(small.top());
            small.pop();
        }else{
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size()==large.size()){
            return (double(small.top())+double(large.top()))/2.0;
        }else{
            if(small.size()>large.size()){
                return small.top();
            }else{
                return large.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*
:


# Idea:

(x)
    ## 1st
        Directly store into a vector (which can access value O(1))
    1. Constructor -> do nothing
    2. addNum() add to vector<int> nums
    3. findMedian() -> check nums.size() first, then return median

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. "Ordered List" -> new added num should follow the order
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 
>> Not get the key point of the problem

# Note:

    https://cplusplus.com/reference/queue/priority_queue/
    Using two priority queue to store numbers, max-heap and min-heap.



TC: O(N*logN)
SC: O(N)

========================================
Day-12, Leetcode November Challenge Study Room Event
*/
// @lc code=end

