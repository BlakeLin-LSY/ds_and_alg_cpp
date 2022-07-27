#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double Similarity(vector<char> & v1, vector<char> & v2) {
    double count = 0.;
    double Avg = (v1.size() + v2.size()) / 2.;
    sort(v1.begin(), v1.end());     // in-place sorting, if not allowed, --> create temporary to store.
    sort(v2.begin(), v2.end());

    // for (auto x : v1){
    //     cout << x << ", ";
    // }cout << " <-- v1" << endl;
    // for (auto x : v2){
    //     cout << x << ", ";
    // }cout << " <-- v2" << endl;

    int i = 0, j = 0;
    while(i < v1.size()){
        
        // The following 2-lines can only apply(work) for "sorted vectors"
        while (v1[i] < v2[j]) ++i;                          // Since v1 & v2 are already sorted, speed up;
        if (i >= v1.size() || j >= v2.size()) break;        // early-stop/break for comparing --> once no possibility

        if (v1[i] == v2[j]){
            // cout << "v1[" << i << "] = " << v1[i] << endl;
            // cout << "v2[" << j << "] = " << v2[j] << endl;
            ++i;
            ++j;
            ++count;
            }
        else ++j;
    }

    // cout << "==== Count: " << count << endl;
    // cout << "==== Avg: " << Avg << endl;
    return count / Avg;
}

int main()
{
    vector<char> test_a0 ={'a', 'b', 'c', 'c', 'e'};
    vector<char> test_a1 ={'a', 'c', 'c', 'k', 'm'};

    vector<char> test_b0 ={'a', 'm'};
    vector<char> test_b1 ={'w', 'x', 'y', 'z'};
    
    vector<char> test_c0 ={'j', 'k', 'k'};
    vector<char> test_c1 ={'k', 'z'};
    
    vector<char> test_d0 ={'f', 'c'};
    vector<char> test_d1 ={'a', 'c', 'c', 'd', 'e'};

    cout << test_a0.size() << endl;
    for(auto x : test_d0){
        cout << x << ", ";
    }
    cout << endl;

    sort(test_d0.begin(), test_d0.end());
    for(auto x : test_d0){
        cout << x << ", ";
    }
    cout << endl;

    cout << Similarity(test_a0, test_a1) << endl;
    cout << Similarity(test_b0, test_b1) << endl;
    cout << Similarity(test_c0, test_c1) << endl;
    cout << Similarity(test_d0, test_d1) << endl;



    return 0;
}