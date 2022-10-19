/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
    static bool my_comp(pair<string, int>& p1, pair<string, int>& p2){
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> ump;
        for(auto word:words) ump[word]++;

        // priority_queue<pair<string, int>, vector<pair<string, int>>, my_comp> pq;
        vector<pair<string, int>> v1;
        for(auto it=ump.begin(); it!=ump.end(); ++it){
            v1.push_back({it->first, it->second});
        }

        sort(v1.begin(), v1.end(), my_comp);
        
        // vector<string> ans(k);
        vector<string> ans;
        for(int i=0; i<k; ++i){
            ans.push_back(v1[i].first);
        }

        return ans;
    }
};


/*
:
    Frequency count, order by alphabetic if same count.

    Return:
        strings in array

# Idea:
    Data structure choose:
        1. ordered, hash --> <map>
        2. sort count number descending with value of map
    
    Strategy:
        1. unordered_map<string, int>
        2. sort<map->value, descending>
        3. push to vector

TC: O(N*logN) --> sort(logN)
SC: O(N) --> the map
*/
// @lc code=end

