//  [ShellSort]
//      A variant of "Insertion Sort" -> separate list into "sub-lists" with the gap.
//      
//
//  Complexity:
//
//  Time:       O(nlogn^2)
//  Average:    O(nlogn^2)
//  Best:       O(nlogn)
//  Worst:      O(nlogn^2)
//
//  Space:      O(1)
//  Stability:  Yes

//  Pros:    
//      -   With advanced time complexity better than insertion sort.
//      -   
//      -   
//  Cons:    
//      -   Conplex algorithm than others.
//      -   Limited to use for "small" size arrays as the performance decreases with an increase in array size.
//      -   
//      -   

// Reference
// https://www.softwaretestinghelp.com/shell-sort/
// https://iq.opengenus.org/shell-sort/
// https://www.geeksforgeeks.org/shellsort/
// https://www.techgeekbuzz.com/tutorial/data-structure/what-is-shell-sort/


#include <iostream>

using namespace std;

void display(int arr[], int n){
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
    cout << endl;
}

void ShellSort(int arr[], int n){
    int tmp, j;
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; ++i){
            tmp = arr[i];
            for(j=i; j>=gap && arr[j-gap] > tmp; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = tmp;
        }
    }
}


int main(){
    
    int arr[] = {12, 34, 54, 2, 3};  
    int n = sizeof(arr)/sizeof(arr[0]);
  
    cout << "Array before sorting: \n";
    display(arr, n);
  
    ShellSort(arr, n);
  
    cout << "\nArray after sorting: \n";
    display(arr, n);
  
    return 0;
}
