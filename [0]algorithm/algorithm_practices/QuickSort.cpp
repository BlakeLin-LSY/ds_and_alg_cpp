//  [Quick Sort]
//      one of the most widely used sorting algorithms, fast in practice.
//      usually use Recursion in quicksort implementation.
//      A "pivot" choosing is important.
// 
//  [Personal Note]
//      Like Insertion Sort, but more efficient(strategical with partition and recursion).
//      Pivot-choosing can have variants of implements.
//      In practice, 
//          quicksort > merge sort >> selection sort & insertion sort.
//
//  Complexity:
//
//  Time:       O(nlogn)
//  Average:    O(nlogn)
//  Best:       O(nlogn)
//  Worst:      O(n^2)  --> pivot is always the smallest or largest elemnt
//              O(nlogn)--> picking pivot with "median" assures the worst case O(nlogn)
//
//  Space:      O(n)    --> can be reduced to O(logn)
//  Stability:  No

//  Pros:    
//      -   One of the most efficient sorting algorithm - O(nlogn)
//      -   Divide and conquer (split into sub-problems, then merge)
//      -   
//  Cons:    
//      -   Not a stable sort --> the swap could lead to un-stability.
//      -   Not suitable for small size array sorting. (insertion sort is efficient enough)
//      -   

//  Related Questions:
//      -   Rearrange numbers (Positive, Negative, Pos..., Neg..., ...)
//      -   Move all 0’s (to the end of the array while maintaining the relative order of the non-zero elements)
//      -   Find the kth largest

// Reference
// 
// https://iq.opengenus.org/quick-sort/
// https://www.mygreatlearning.com/blog/quick-sort-algorithm/       -> check this to find related questions
// https://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html


#include <iostream>

using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int Partition(int arr[], int front, int end){
    int pivot=arr[end];
    int i=front-1;
    for(int j=front; j<end; ++j){
        if(arr[j] <= pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i], arr[end]);

    return i;
}

void QuickSort(int arr[], int front, int end){
    if(front < end){
        int pivot=Partition(arr, front, end);
        QuickSort(arr, front, pivot-1);
        QuickSort(arr, pivot+1, end);
    }
}


int main(){

    int n = 9;
    // int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    int arr[] = {9, 2, 1, 6, 3, 3, 8, 2, 5};
    std::cout << "original:\n";
    display(arr, n);

    QuickSort(arr, 0, n-1);

    std::cout << "sorted:\n";
    display(arr, n);
    return 0;
}
