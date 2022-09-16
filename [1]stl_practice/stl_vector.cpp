#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    for(int i=0; i<50; ++i){
        vec.push_back(i);
        cout<<"i : " << i;
        cout<<"\t capacity:" << vec.capacity() << endl;
    }

    return 0;
}