/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length(), k=needle.length();
        if(k<1) return 0;
        if (n<0||n<k) return -1;     // Pattern is smaller than match string.

        
        int i, pos=0;
        vector<int> lps(k, 0);
        for(i=1; i<k; ++i){
            if(needle[i]==needle[pos]){
                ++pos;
                lps[i]=pos;
            }else if(pos>0){
                pos=lps[pos-1];     // retrieve previous index
                --i;                // Keep i, not forward
            }else{
                lps[i]=0;           // Reset to start from the beginning.
            }
        }
        // for(auto x:needle){
        //     cout << x << " ";
        // }cout << endl;
        // for(auto x:lps){
        //     cout << x << " ";
        // }cout << endl;

        for(i=0, pos=0; i<n; ++i){
            // cout << haystack[i] << ", " << needle[pos] << endl;
            if(haystack[i]==needle[pos]) ++pos;
            else if(pos > 0) {
                pos=lps[pos-1];
                --i;                // Keep current index i to compare
            }

            if(pos==k) return i-pos+1;
        }

        return -1;
    }
};
/*
:
    KMP algorithm, find LPS(longest prefix suffix)

TC:O(N+k)       --> N is the String length, k is the pattern string length.
SC:O(k)
*/
// @lc code=end

