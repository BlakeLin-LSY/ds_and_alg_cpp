/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        Iterator tmp=*this;
		return tmp.next();		
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		return Iterator::next();		// Override with Iterator::next()
	}
	
	bool hasNext() const {
	    return Iterator::hasNext();		// Override with Iterator::hasNext()
	}
};/*
:
	PeekingIterator class
		next()
		hasNext()
		peek()

# Idea:
    ## 1st
        Straight forward to build
    1. constructor -> initialize the nums (with Iterator interface)
    2. peek() -> return current value, but not moving iterator
	3. next() -> return current value, and moving iterator
	4. hasNext() -> check is iterator at the end

    ### Edge Case:
      1. 
      2. 

    ### Key Points:
      1. Iterator use
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 

# Note:

	https://cplusplus.com/reference/iterator/

========================================
Day-11(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

