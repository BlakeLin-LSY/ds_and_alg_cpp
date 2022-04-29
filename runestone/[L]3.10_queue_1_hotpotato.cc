#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
void hotPotato(vector<string> nameArray, int num){
    queue<string> simq;
    int len = nameArray.size();
    for (int i = 0; i<len; ++i){
        simq.push(nameArray[i]);
    }

    int index = 1;
    while (simq.size() > 1){
        for (int i = 0; i < num; ++i){
            simq.push(simq.front());
            simq.pop();
        }
        cout << index << " : " << simq.front() << endl;
        ++index;
        simq.pop();
    }
    cout << "Survior: " << simq.front() << endl;
    return;

}

int main(){
    queue<int> q;
    queue<int> tmpq;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    tmpq = q;
    cout << "queue = ";
    while (!tmpq.empty()){
        cout << tmpq.front() << ", ";
        tmpq.pop();
    }
    cout << endl;
    cout << "q.back() -> " << q.back() << endl;
    cout << "q.front() -> " << q.front() << endl;
    cout << "q.size() -> " << q.size() << endl;

    q.pop();

    cout << " --- After 1 pop() ---" << endl;
    
    tmpq = q;
    cout << "queue = ";
    while (!tmpq.empty()){
        cout << tmpq.front() << ", ";
        tmpq.pop();
    }
    cout << endl;
    cout << "q.back() -> " << q.back() << endl;
    cout << "q.front() -> " << q.front() << endl;
    cout << "q.size() -> " << q.size() << endl;

    cout << "\n --- HotPotato ---" << endl;

    vector<string> names = {"Bill", "David", "Susan", "Jane", "Kent", "Brad"};
    cout << "Names Queue:\n{\t" << endl;
    for (int i = 0; i < names.size(); ++i){
        cout << names[i] << ", ";
    }
    cout << "\n}" << endl;
    int n;
    cout << "enter execution number n = ";
    cin >> n;
    hotPotato(names, n);

    return 0;
}


/*

empty()
size()

push()
pop()

front()     -> front
back()      -> rear


*/