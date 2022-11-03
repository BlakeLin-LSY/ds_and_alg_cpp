/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
public:
    bool isOneMutation(const string &s1, const string &s2){
        int count=0;
        for(int i=0; i<8; ++i){
            if(s1[i]!=s2[i]) ++count;
        }
        return count==1 ? true:false;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if(bank.size()==0) return -1;
        unordered_map<string, int> seen;        // To be ignored genes (already visited)
        unordered_map<string, int> check;       // To be checked genes
        
        ++check[end];                           // Start from end to find 1 mutation genes.
        int cntNextCheck=1;                     // Start with end, must be one run
        int cnt=0;
        while(cntNextCheck>0){
            vector<string> tmp;
            for(auto gene1:bank){
                if(!check[gene1]) continue;     // only examine wanted genes
                ++seen[gene1];

                if(isOneMutation(gene1, start)) return ++cnt;

                for(auto gene2:bank){
                    if(seen[gene2]) continue;   // ignore visited
                    if(isOneMutation(gene1, gene2)){
                        tmp.push_back(gene2);   // Move out to the first for-loop
                        ++cntNextCheck;
                    }
                }
                --check[gene1];                 // Reset the check gene table;
            }
            for(auto x:tmp) ++check[x];
            tmp.clear();
            --cntNextCheck;                     // Outside for-loop >> edge case (end not in bank)
            ++cnt;
        }
        return -1;

    }
};
/*
:
    gene string (8-characters), consisting of ["A", "C", "G", "T"]
    start: gene string (start string)
    end: gene string (end string)
    bank: valid gene strings -> otherwise cannot have mutation

# Idea:
    ## 1st
        from end to start
    1. sub function to check if two string only one mutation
    2. hash_table to store seen(checked) gene mutations
    3. vector<string> to check start

    ### Edge Case:
      1. bank size == 0
      2. end not in the bank;
      2. Max mutation time == 8 --> yes, but it depends on the bank

    ### Key Points:
      1. Every mutation need to be contained in the bank
      2. Find minimum mutation time

    ### Any Improvement Ideas / Related Questions:
      - Using "queue" to through the search
      - Cleaner or more concise ?

# Note:
    checkGenes could be in the wrong loop, careful (line36)

TC: O(N^2)      --> O(N^2*8)      // N is the bank.length, 8 is the start/end.length
SC: O(N)        --> O(2*N)

========================================
Day-02, Leetcode November Challenge Study Room Event
*/
// @lc code=end

