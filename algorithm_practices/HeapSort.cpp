//  Heap sort
//      No extra space, in-place sort, efficient sorting algorithm.
//      another very efficient general purpose in-place comparison-based sort algorithm. (compete with "quick sort")
//
//  Complexity:
//
//  Time:       O(nlogn)
//  Average:    O(nlogn)
//  Best:       O(nlogn)
//  Worst:      O(nlogn)
//
//  Space:      O(1)
//  Stability:  No

//  Pros:    
//      -   Easy implementation
//      -   No extra memory use
//      -   
//  Cons:    
//      -   poor locality of reference (the accesses to the implicit tree are widely scattered and mostly random)
//      -   inherently serial nature (no straightforward way to convert it to parallel algorithm)
//      -   
//      -   not too much applications (since Quicksort and Mergesort are better in practice)
//          well-implemented quicksort is usually 2–3 times faster than heapsort

// Reference
// https://www.mygreatlearning.com/blog/heap-sort/
// https://www.programiz.com/dsa/heap-sort

// heap sort --> using heap data structure to do the sorting, with 'max-heap'/'min-heap' property
// : Max-heap property --> parent > child node.
// : Min-heap property --> parent < child node.

// heapify --> reshaping 'binary tree' into 'heap' data structure;
// : A heap should always be a 'complete binary tree' --> all the tree levels are filled.


#include<iostream>

using namespace std;

// Max-heap
void heapify(int arr[], int n, int i){
    int max_i = i;              // as root
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;

    if (left_child < n && arr[left_child] > arr[max_i]) max_i = left_child;

    if (right_child < n && arr[right_child] > arr[max_i]) max_i = right_child;

    if (max_i != i){
        swap(arr[i], arr[max_i]);
        heapify(arr, n, max_i);     // heapify the affected sub-tree recursively;
    }
}

// Bottom-up to build heap -> using max-heap
void pulldown(){

}

// Top-down to build heap -> using min-heap
void pullup(){

}

void HeapSort(int arr[], int n){
    for(int i=n/2-1; i >=0; --i){
        heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; --i){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; ++i)  cout << arr[i] << " ";
    cout << endl;
}


int main(){
    int arr[] = {11, 34, 9, 5, 16, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original arr:" << endl;
    display(arr, n);
    cout << "Heap-sorted arr:" << endl;
    HeapSort(arr, n);
    display(arr, n);

    return 0;
}