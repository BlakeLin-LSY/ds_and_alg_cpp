/*
    2.5 hr to finish...

# Finished:
            hh:mm:ss
    Total:  01:08:29
            00:11:10                # Problem understanding
            00:17:28    slowest     # Algorithm construction
            00:07:49    fatest      # Write the check conditions & pseudo code
            00:16:46                # Write the code
            00:15:13                # Check test case

# Debug to pass all test cases:
        >   01:30:00    
*/

/*
Record Breaker (5pts, 7pts)

Problem
    Isyana is given the number of visitors at her local theme park on N consecutive days. 
    The number of visitors on the i-th day is Vi. 
    A day is record breaking if it satisfies both of the following conditions:

    Either it is the first day, or the number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
    Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
    Note that the very first day could be a record breaking day!
    Please help Isyana find out the number of record breaking days.

Input
    The first line of the input gives the number of test cases, T. 
    T test cases follow. Each test case begins with a line containing the integer N. 
    The second line contains N integers. 
    The i-th integer is Vi and represents the number of visitors on the i-th day.

Output
    For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of record breaking days.

Limits
    Time limit: 20 seconds.
    Memory limit: 1 GB.
    
    1≤T≤100.
    0≤Vi≤2×10^5, for all i.
    
    Test Set 1
    1≤N≤1000.

    Test Set 2
    1≤N≤2×10^5, for at most 10 test cases.
    For the remaining cases, 1≤N≤1000.

Sample
    Sample Input                        Sample Output
        4
        8                               Case #1: 2
        1 2 0 7 2 0 2 0
        6                               Case #2: 1
        4 8 15 16 23 42                 
        9                               Case #3: 3
        3 1 4 1 5 9 2 6 5
        6                               Case #4: 0
        9 9 9 9 9 9

    In Sample Case #1, the underlined numbers in the following represent the record breaking days: 1 2–– 0 7–– 2 0 2 0.

    In Sample Case #2, only the last day is a record breaking day: 4 8 15 16 23 42–––.

    In Sample Case #3, the first, the third, and the sixth days are record breaking days: 3–– 1 4–– 1 5 9–– 2 6 5.

    In Sample Case #4, there is no record breaking day: 9 9 9 9 9 9.
*/


/*
# Problem understanding:
    - Find number of record breaking day 
        following the rules --> find-peaks
    - Could be solved using "greedy algorithm" or "dynamic programming"
    - Input: T, N, Vi  --> input complexity == N

--- 11:10 --- Time costed

# Algorithm construction:
    - 

Go check test cases first:
    #1
        1 2 0 7 2 0 2 0
          x   x     x
                            >> 3
    #2
        4 8 15 16 23 42
                      x
                            >> 1
    #3
        3 1 4 1 5 9 2 6 5
        x   x     x   x
                            >> 4
    #4
        9 9 9 9 9 9
                            >> 0
    
    Something misunderstood --> check rules again.
    #1 & #3 --> last peak not taken into account.
    !!Note: peak not > previous peak
--- 17:28 --- Time costed

# Write the check conditions & pseudo code:
    1. Max_peak, arr[i-1], arr[i], arr[i+1], count
    
    check condition:
    - arr[i] > arr[i+1]
        - arr[i] > max_peak
        - arr[i-1] < arr[i]

Time complexity: O(N) --> for each test case (N)
Space complexity: O(N)

--- 7:49 --- Time costed

# Write the code
--- 16:46 --- Time costed

# Check test case
        8                               Case #1: 2
        1 2 0 7 2 0 2 0
                    -
i=6
Max_peak=7
prev=0
cur=2
next=0
count=2
        6                               Case #2: 1
        4 8 15 16 23 42           
                  -
i=4
Max_peak=4
prev=16
cur=23
next=42
count=1
        9                               Case #3: 3
        3 1 4 1 5 9 2 6 5

--> add first peak at arr[0] check
        6                               Case #4: 0
        9 9 9 9 9 9

--- 15:13 --- Time costed


# Finished:
            hh:mm:ss
    Total:  01:08:29
            00:11:10                # Problem understanding
            00:17:28    slowest     # Algorithm construction
            00:07:49    fatest      # Write the check conditions & pseudo code
            00:16:46                # Write the code
            00:15:13                # Check test case



# Submit test:  "Can't pass test cases"
    Attempt 1
    Sample Failed: WA
    Aug 31 2022, 16:58

    >> Output format error.... missing space "Case#1" --> "Case #1"

    Attempt 2
    S
    WA
    remove_circle_outline
    Aug 31 2022, 17:00


# Check analysis


# Fix bug
    1. Output error
    2. Edge cases
        1. the very first day [2000, 2000] or [0, 2000] or [2000, 0]
        2. single day [0] or [2000] ...
    3. Functionalize result --> void solve() >> int solve();

    - txt input test --> using #include<fstream> 

--- 1.5 hr... ---

*/

#include<iostream>
#include<fstream>

using namespace std;

int solve(int N, int arr[]){
    if(N < 2) return 1;

    int Max_peak=arr[0];
    int next = arr[1], prev, cur, count;
    count = 0;
    if(arr[1] < arr[0]) count++;

    for(int i=1; i<N-1; ++i){
        next=arr[i+1];
        prev=arr[i-1];
        cur=arr[i];

        if(cur > next){
            if(cur > Max_peak){
                Max_peak = cur;
                if(prev < cur) count++;
            }
        }
    }

    // Check last
    if(next > Max_peak) count++;

    return count;
}

int main(){
    string fileName;
    fileName="ts1_input.txt";
    // fileName="fin.txt";
    ifstream file(fileName);
    string line;

    if (file.is_open())
    {
        int T;
        file >> T;
        int res[T];
        int N;        
        for(int i=0; i<T; ++i){
            file >> N;
            int arr[N];
            for (int i=0; i<N; ++i){
                file >> arr[i];
            }
            cout << "Case #" << i+1 << ": " << solve(N, arr) << endl;
        }

    }

    return 0;
}