/*
 * @lc app=leetcode id=1224 lang=cpp
 *
 * [1224] Maximum Equal Frequency
 */

// @lc code=start
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> num2freq;
        for(auto num:nums) num2freq[num]++;

        unordered_map<int, int> freq2count;
        for(auto [num, freq]:num2freq) freq2count[freq]++;

        int freqCounts=0;
        for(int i=nums.size()-1; i>=0; --i){
            freqCounts=freq2count.size();
            if(freqCounts==1){
                auto [freq, count] = *freq2count.begin();
                if(count==1 || freq==1){
                    return i+1;
                }
            }else if(freqCounts==2){
                vector<pair<int, int>>tmp(freq2count.begin(), freq2count.end());
                sort(tmp.begin(), tmp.end());

                if(tmp[1].first==tmp[0].first+1 && tmp[1].second==1){
                    return i+1;
                }
                if(tmp[0].first==1 && tmp[0].second==1){
                    return i+1;
                }
            }

            int x=nums[i];          // number
            int y=num2freq[x];      // frequency

            num2freq[x]-=1;
            if(num2freq[x]==0) num2freq.erase(x);

            freq2count[y]-=1;
            if(freq2count[y]==0) freq2count.erase(y);

            if(y-1>0) freq2count[y-1]++;
        }
        return 2;
    }
};
/*
:
    return longest length of prefix num;

    constraints:
        1. Remove exactly one element
        2. the rest numbers in num have same occurences.

# Ideas
    - hash map to count occurences
    
    // (x) not working since not only from the end, but also the front
    - reverse (remove the last elemnt) --> to check occurences
    
    unordered_map<pair<int, vector<int>>> --> exist only 2,  
        1 for the occurence once, 
        the rest for the other same occurences

No further idea
>> check tutorial
    https://www.youtube.com/watch?v=xs4oc3icbgE

TC:O(N)
SC:O(N)
*/
// @lc code=end

