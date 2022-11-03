/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:
    int help(string s1){
        int i=s1[0]-'a', j=s1[1]-'a';
        if(i==j) return 0;
        if(i>j) return -(j*26+i);
        return i*26+j;
    }
    int longestPalindrome(vector<string>& words) {
        if(words.size()==0) return 0;
        unordered_map<string, int> identical;
        unordered_map<int, int> diff;

        int tmp=0;
        for(auto word:words){
            tmp=help(word);
            if(tmp==0) identical[word]++;
            else diff[tmp]++;
        }

        int ans=0;
        bool isCenter=false;            // Is Palindrome with center identical
        for(auto [word, cnt]:identical){
            if(!isCenter && cnt % 2) {  // Only need one check, only one can put in the center
                isCenter=true;          // Must have a sole identical center "~~aa~~"
            }
            ans += 4*(cnt/2);           // "aa" + "aa" -> two as a pair
        }

        for(auto [val, cnt]:diff){
            if(val>0 && diff[-val]>0) ans += 4*min(diff[val], diff[-val]);
        }

        return isCenter ? ans+2:ans;
    }
};
/*
:
    Find longest palindrome length from words.
    the palindrome is concatenate from word in words.

# Idea:
    ## 1st
        Compute a number for every word, check possibility.
    1. x=min(word[0]-'a', word[1]-'a'), y=max(word[0]-'a', word[1]-'a') --> the value for each word
        val = x*26+y
    2. v1+v2 = 0 --> to make a palindrome
        "ab" + "ba" == (26-52) + (52-26) == 0
        "aa" + "aa" == (26-26) + (26-26) == 0
    3. count "xx" numbers --> %2==0 , result + 4

    ### Edge Case:
      1. No possible palindrome
        1. words.size() == 0
        2. all word are in same character
      2. "aa" , "bb", "cc" ... same character, but have multiple count like "aa", "aa"
      3. extra identical word (sole identical == palindrome center)

    ### Key Points:
      1. Each word have only 2 elements, and all in lowercase. (Return value %2 == 0)
      2. The hash value of each word

    ### Any Improvement Ideas / Related Questions:
      - Better help function
      - Concise logic to examine palindrome
      - Could it be extended to word.size() != 2 ?
      >> No...

# Note:
    1. diff pairs number not the same. count["ab"] = 3, count["ba"] = 4 --> take 3
    2. identical pairs counting
    3. collision of help function

    Palindrome:
        0. (~.size() % 2 == 0) is confined in this question -> even number
        1. sub-units --> made up of two characters 
            1. Identical  --> "aa", "bb", ... "zz"
            2. Difference --> "ax", "bs", ...
        2. Make pair to be in a palindrome
            1. Identical: (can exist in center or either)
                - Every 2 count, can be in the palindrome
                // "aa"+"abba"+"aa"  --> except from the center
                - In the center --> can only exist one
            2. Difference: (only exist in "prefix" or "posfix")
                - "ab" , "ba" --> make a pair
                // Find a function to make "ab" == "ba"

TC: O(N)
SC: O(1)    -> 26^2 + 26 (at most)

========================================
Day-03, Leetcode November Challenge Study Room Event
    string, math, hash
*/
// @lc code=end

