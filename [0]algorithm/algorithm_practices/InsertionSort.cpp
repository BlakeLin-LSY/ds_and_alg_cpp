//  [Insertion Sort]
//      brute force sorting algorithm
//      (compete with "Bubble Sort", "Selection Sort")
//
//  Complexity:
//
//  Time:       O(n^2)
//  Average:    O(n^2)
//  Best:       O(n)    -> when all elements are already sorted (traverse all by 1 time -> O(n))
//  Worst:      O(n^2)
//
//  Space:      O(1)
//  Stability:  Yes

//  Pros:    
//      -   Separated to "sorted" and "unsorted" part, depending on the iteration.
//      -   In-place and stable.
//      -   
//  Cons:    
//      -   Slow
//      -   

// Reference
// https://www.mygreatlearning.com/blog/insertion-sort-algorithm/
// 


#include <iostream>

using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;
}

void InsertionSort(int arr[], int n){
    int tmp;
    for(int j=1; j<n; ++j){
        tmp=arr[j];
        int i=j-1;
        // display(arr, n);
        while(i>=0 && arr[i]>tmp){
            arr[i+1]=arr[i];
            --i;
        }
        arr[i+1]=tmp;
    }
}

int main(){
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);
    cout << "Elements before sorting:\n";
    display(data, size);
    InsertionSort(data, size);
    cout << "Elements after sorting:\n";
    display(data, size);
    return 0;
}
