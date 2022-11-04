/*
Attending Workshops
https://www.hackerrank.com/challenges/attending-workshops/problem
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Workshop{
      int start_time, duration, end_time;
      bool operator <(const Workshop& another) const{
            return end_time < another.end_time;
      }
};

struct Available_Workshops{
    int n;
    vector<Workshop> arr;      
};


Available_Workshops* initialize(int start_time[], int duration[], int n){
    Available_Workshops* workshop = new Available_Workshops;
    workshop->n = n;        // Assign value;
    for(int i=0; i<n; ++i){
        Workshop tmp;
        tmp.start_time=start_time[i];
        tmp.duration=duration[i];
        tmp.end_time=start_time[i]+duration[i];
        workshop->arr.push_back(tmp);
    }
    return workshop;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int res=0;
    sort(ptr->arr.begin(), ptr->arr.end());
    int end_time=-1;
    for(int i=0; i<ptr->n; ++i){
        if(ptr->arr[i].start_time >= end_time){
            ++res;
            end_time=ptr->arr[i].end_time;
        }
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; cin >> n;
    
    int start_time[n], duration[n];
    for(int i=0; i<n; ++i) cin >> start_time[i];
    for(int i=0; i<n; ++i) cin >> duration[i];
    
    Available_Workshops* workshops = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(workshops) << endl;

    return 0;
}

/*
Test case 0:
    Input (stdin)       Expected Output
    6                   4
    1 3 0 5 5 8
    1 1 6 2 4 1
*/