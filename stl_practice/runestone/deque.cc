#include <iostream>
#include <deque>

using namespace std;


int main(){
    deque<int> dq;

    cout << "Deque empty? " << dq.empty() << endl;

    dq.push_back(31);
    cout << "Deque empty? " << dq.empty() << endl;

    dq.push_front(1);
    dq.push_front(2);
    dq.push_back(50);
    dq.push_back(51);

    cout << "Deque size: " << dq.size() << endl;
    cout << "front = " << dq.front() << endl;
    cout << "back = " << dq.back() << endl;

    cout << "\nItems in the Deque:\n";
    for (int i = 0; i < dq.size(); ++i){
        cout << dq.at(i) << " ";
    }
    cout << endl;

    dq.pop_back();
    dq.pop_front();

    cout << "=== After pop_back, pop_front once ===\n";
    cout << "Deque size: " << dq.size() << endl;
    cout << "front = " << dq.front() << endl;
    cout << "back = " << dq.back() << endl;

    cout << "\nItems in the Deque:\n";
    for (int i = 0; i < dq.size(); ++i){
        cout << dq.at(i) << " ";
    }
    cout << endl;

    return 0;
}