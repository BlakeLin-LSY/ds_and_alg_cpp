//  [Merge Sort]
//      One of "Divide and Conquer" sorting algorithm.
//      Divide & Merge --> two index
//
//  Complexity:
//
//  Time:       O(nlogn)
//  Average:    O(nlogn)
//  Best:       O(nlogn)
//  Worst:      O(nlogn)
//
//  Space:      O(n)
//  Stability:  Yes

//  Pros:    
//      -   O(nlogn) time complexity in all Average, Worst, Best case.
//      -   
//  Cons:    
//      -   Extra space needed
//      -   


// Related Questions:
//  -   Inversion count problem
//  -   External sorting
//  -   E-commerce applications

// Reference
// https://www.programiz.com/dsa/merge-sort
// https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort
// 


#include <iostream>

using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int l, int r, int mid){
    int n1=mid-l+1;
    int n2=r-mid;

    int arr1[n1], arr2[n2];
    for(int i=0; i<n1;++i) arr1[i]=arr[l+i];
    for(int i=0; i<n2;++i) arr2[i]=arr[mid+1+i];

    int i, j, k;
    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            arr[k]=arr1[i];
            ++i;
        }
        else{
            arr[k]=arr2[j];
            ++j;
        }
        ++k;
    }

    // Run out one of the array(arr1 or arr2)
    while(i<n1){
        arr[k]=arr1[i];
        ++i;
        ++k;
    }

    while(j<n2){
        arr[k]=arr2[j];
        ++j;
        ++k;
    }
}

void MergeSort(int arr[], int l, int r){
    int mid=l+(r-l)/2;
    if(l<r){
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        merge(arr, l, r, mid);
    }
}

void MergeSort_it(int arr[], int l, int r){

}




int main(){
    // int arr[] = {6, 5, 12, 10, 9, 1};
    int arr[] = {14, 7, 3, 12, 9, 11, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: \n";
    display(arr, size);

    MergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    display(arr, size);
    return 0;
    return 0;
}
