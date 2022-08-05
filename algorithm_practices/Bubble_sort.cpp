//  Bubble sort
//      Brute force sorting algorithm
//      Compete with "Insertion sort", "Selection sort"
//
//  Complexity:
//
//  Time:       O(n^2)
//  Average:    O(n^2)
//  Best:       O(n^2) -> O(n) if adding a flag variable
//  Worst:      O(n^2)
//
//  Space:      O(1)
//  Stability:  Yes

//  Pros:    
//      -   Easy and straightforward
//      -   In-place algorithm (no extra space needed)
//      -   
//  Cons:    
//      -   Worst efficiency as "too many swaps" are required in comparison to selection and insertion
//      -   

// Reference
// https://www.mygreatlearning.com/blog/bubble-sort/
// 


#include <iostream>

using namespace std;

// For ascending order
void bubblesort(int arr[], int n){
    for(int i=0; i<n-1; ++i){
        for(int j=0; j<n-i-1; ++j){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

// modified bubble-sort T(O) == O(n) in best case;
void bubblesort_m(int arr[], int n){
    int flag;
    for(int i=0; i<n-1; ++i){
        flag=0;
        for(int j=0; j<n-i-1; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag=1;
            }
        }
        if(flag=0) break;
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {-2, 45, 0, 11, -9};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    
    cout << "Original array :\n";
    display(arr, size);
    bubblesort(arr, size);
    cout << "Sorted array :\n";
    display(arr, size);
    return 0;
}
