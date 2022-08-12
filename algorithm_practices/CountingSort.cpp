//  [Counting Sort]
//      sort elements in linear time.
//      works just like hashing.
//
//  Complexity:
//
//  Time:       O(n+k)
//  Average:    O(n+k)
//  Best:       O(n+k)
//  Worst:      O(n+k)
//
//  Space:      O(Max)  --> max is the value of the maximum in the array
//  Stability:  Yes

//  Pros:    
//      -   O(n+k) time complexity
//      -   
//      -   
//  Cons:    
//      -   Extra space needed, and could be large.
//      -   Values in array sholud be positive (or it could need to create larger size of counting array)
//      -   
//      -   

// Reference
// 
// 


#include <iostream>

using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;
}

void CountSort(int arr[], int n){
    int max_v=arr[0];
    int arr1[n]={0};
    for(int i=0; i<n; ++i){
        if (arr[i] > max_v) max_v=arr[i];
    }

    int c_arr[max_v+1]={0};
    for(int i=0; i<=n; ++i){
        c_arr[arr[i]]+=1;
    }
    display(c_arr, max_v+1);

    for(int i=1; i<=n; ++i){
        c_arr[i]+=c_arr[i-1];
    }

    display(c_arr, max_v+1);

    for(int i=1; i<=n; ++i){
        c_arr[arr[i]]-=1;
        arr1[c_arr[arr[i]]]=arr[i];
    }

    // Replace to original array
    for(int i=0; i<n; ++i){
        arr[i]=arr1[i];
    }
}


int main(){
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original Array: " << endl;
    display(arr, n);
    
    CountSort(arr, n);

    cout << "Sorted Array: " << endl;
    display(arr, n);
    return 0;
}
