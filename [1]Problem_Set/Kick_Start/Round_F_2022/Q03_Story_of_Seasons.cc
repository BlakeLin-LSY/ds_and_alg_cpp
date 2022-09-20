#include<iostream>
#include<string>
using namespace std;

int main(){

    return 0;
}


/*
Problem
    You are a super farmer with some vegetable seeds and an infinitely large farm. 
    In fact, not only are you a farmer, but you are also secretly a super programmer! 
    As a super programmer, you hope to maximize the profit of your farming using your programming skills.

    Since your daily energy is limited, you can plant at most X seeds each day. 
    In the beginning, you have N kinds of vegetable seeds. 
    The number of seeds of the i-th kind of vegetable is Qi, and each seed of this kind needs Li days to mature from the day it is planted. 
    Once it matures, you can sell it for Vi dollars. Assume that no energy or time is required for harvesting and selling vegetables. 
    Also, your farm is infinitely large so the growing vegetables do not crowd out each other.

    Notice that although the area of your farm is infinite, the number of days that you can plant seeds is limited. 
    The warm season only lasts D days, and after that, the harsh winter comes. 
    Any vegetable that has not matured yet will die immediately and cannot be turned into profit. 
    The remaining seeds that were not planted cannot be turned into profit either.

    As a super farmer and a super programmer, you want to come up with a perfect planting plan that will maximize your profit. 
    :
        Find the total amount of profit you will earn.

Input
    The first line of the input gives the number of test cases, T. T test cases follow.
    The first line of each test case contains three integers 
        D, N, and X: 
            the number of days of the warm season, 
            the number of kinds of vegetable seeds you have to start with, and 
            the maximum number of seeds you can plant each day, respectively.
    The next N lines describe the seeds. The i-th line contains three integers 
        Qi, Li, and Vi: 
            the quantity of this kind of seed, 
            the number of days it needs to mature, and 
            the value of each matured plant, respectively.

Output
    For each test case, output one line containing 
        Case #x: y, where 
            x is the test case number (starting from 1) and 
            y is the maximum amount of money you can earn by optimizing your farming plan.

Limits
    Memory limit: 1 GB.
    1≤T≤100.
    1≤Vi≤10^6, for all i.
    1≤Li≤D, for all i.

Test Set 1
    Time limit: 20 seconds.
    2≤D≤1000.
    1≤N≤15.
    X=1.
    Qi=1, for all i.

Test Set 2
    Time limit: 60 seconds.
    2≤D≤10^5.
    1≤N≤10^5.
    1≤X≤10^9.
    1≤Qi≤10^6, for all i.

Test Set 3
    Time limit: 60 seconds.
    2≤D≤10^12.
    1≤N≤10^5.
    1≤X≤10^9.
    1≤Qi≤10^6, for all i.
    D×X≤10^18.

Sample
    Note: there are additional samples that are not run on submissions down below.

    Sample Input            Sample Output
    save_alt
    content_copy
    2
    5 4 1                   Case #1: 18
    1 2 3
    1 3 10
    1 4 5
    1 2 2
    5 1 1                   Case #2: 1
    1 1 1


    In Sample Case #1, there are D=5 days, N=4 kinds of vegetables and you can plant at most X=1 seed each day. 
    Supposing the 4 kinds of vegetables are spinach, pumpkin, carrot and cabbage, we have that

        Spinach needs 2 days to grow, each matured one is worth 3 dollars, and you start with 1 spinach seed.
        Pumpkin needs 3 days to grow, each matured one is worth 10 dollars, and you start with 1 pumpkin seed.
        Carrot needs 4 days to grow, each matured one is worth 5 dollars, and you start with 1 carrot seed.
        Cabbage needs 2 days to grow, each matured one is worth 2 dollars, and you start with 1 cabbage seed.

    The maximum profit you can make is 18 dollars. One of the schedules you can use is:
    Day 1: plant 1 carrot
    Day 2: plant 1 pumpkin
    Day 3: plant 1 spinach
    Day 4: plant 1 cabbage
    Day 5: do nothing

    And with this schedule, the vegetables will mature and turn into profit as following days:
    Day 1: nothing harvested
    Day 2: nothing harvested
    Day 3: nothing harvested
    Day 4: nothing harvested
    Day 5: 1 spinach, 1 pumpkin and 1 carrot harvested, you earn 18 dollars

    Note that the cabbage is supposed to mature on day 6, but it will actually die because of the winter.

Additional Sample - Test Set 2
    The following additional sample fits the limits of Test Set 2. It will not be run against your submitted solutions.

    Sample Input        Sample Output
    1
    5 3 4               Case #1: 45
    5 2 3
    2 3 10
    2 4 5

    In Additional Sample Case #1, there are D=5 days, N=3 kinds of vegetables and you can plant at most X=4 seeds each day. 
    Supposing the 3 kinds of vegetables are spinach, pumpkin and carrot, we have that

        Spinach needs 2 days to grow, each matured one is worth 3 dollars, and you start with 5 spinach seeds.
        Pumpkin needs 3 days to grow, each matured one is worth 10 dollars, and you start with 2 pumpkin seeds.
        Carrot needs 4 days to grow, each matured one is worth 5 dollars, and you start with 2 carrot seeds.

    The maximum profit you can make is 45 dollars. One of the schedules you can use is:
    Day 1: plant 1 pumpkin, 2 carrots and 1 spinach
    Day 2: plant 2 spinach and 1 pumpkin
    Day 3: plant 2 spinach
    Day 4: do nothing
    Day 5: do nothing

    And with this schedule, the vegetables will mature and turn into profit as following days:
    Day 1: nothing harvested
    Day 2: nothing harvested
    Day 3: 1 spinach harvested, you earn 3 dollars
    Day 4: 2 spinach and 1 pumpkin harvested, you earn 16 dollars
    Day 5: 2 spinach, 1 pumpkin and 2 carrots harvested, you earn 26 dollars
*/