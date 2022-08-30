/*

Sherlock and Watson Gym Secrets (12pts, 20pts)

Problem
    Watson and Sherlock are gym buddies.

    Their gym trainer has given them three numbers, A, B, and N, 
    and has asked Watson and Sherlock to pick two different strictly positive integers i and j, where i and j are both less than or equal to N. 
    Watson is expected to eat exactly iA sprouts every day, and Sherlock is expected to eat exactly jB sprouts every day.

    Watson and Sherlock have noticed that if the total number of sprouts eaten by them on a given day is divisible by a certain integer K, then they get along well that day.

    So, Watson and Sherlock need your help to determine how many such pairs of (i,j) exist, where i≠j and they get along well that day. As the number of pairs can be really high, please output it modulo 109+7(1000000007).

Input
    The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of one line with 4 integers A, B, N and K, as described above.

Output
    For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the required answer.

Limits
    Time limit: 60 seconds.
    Memory limit: 1 GB.

    1≤T≤100.
    0≤A≤106.
    0≤B≤106.

    Test Set 1
    1≤K≤10^4.
    1≤N≤10^3.

    Test Set 2
    1≤K≤10^5.
    1≤N≤10^18.

Sample
    Sample Input            Sample Output
    3
    1 1 5 3                 Case #1: 8
    1 2 4 5                 Case #2: 3
    1 1 2 2                 Case #3: 0
    

In Case #1, the possible pairs are (1,2), (1,5), (2,1), (2,4), (4,2), (4,5), (5,1), and (5,4).

In Case #2, the possible pairs are (1,2), (1,3), and (4,1).

In Case #3, No possible pairs are there, as i≠j.
*/