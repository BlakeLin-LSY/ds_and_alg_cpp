//  [Selection Sort]
//      Select(pick) the min/max value, and put it at the right place.
//      
//
//  Complexity:
//
//  Time:       O(n^2)
//  Average:    O(n^2)
//  Best:       O(n^2)  -> O(n) if we made some modification for checking "sorted" array.
//  Worst:      O(n^2)
//
//  Space:      O(1)
//  Stability:  No

//  Pros:    
//      -   Select one-by-one --> easy to find k-th smallest
//      -   No extra space needed.
//      -   
//  Cons:    
//      -   Not efficient
//      -   Not a stable sort (swap may mess up the order)
//      -   

// Reference
// https://www.mygreatlearning.com/blog/selection-sort-algorithm/
// https://en.wikipedia.org/wiki/Sorting_algorithm#Stability


#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n){
    int min;
    for(int j=0; j<n-1; ++j){
        min=j;
        for(int i=j+1; i<n; ++i){
            if(arr[i]<arr[min]){
                min=i;
            }
        }
        swap(arr[j], arr[min]);
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {20, 12, 10, 15, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Elements before sorting:\n";
    display(arr, n);
    SelectionSort(arr, n);
    cout << "Elements after sorting:\n";
    display(arr, n);
    return 0;
}
