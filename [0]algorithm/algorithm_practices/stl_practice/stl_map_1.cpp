#include<iostream>
#include<algorithm>

#include<map>
#include<string>

using namespace std;

void check(map<string, string> _mp){
    
    cout << "Max_size(): " << _mp.max_size() << endl;
    cout << "size(): " << _mp.size() << endl;
    cout << "empty(): " << _mp.empty() << endl;

    cout << "Elements:\n";
    for(auto i=_mp.begin(); i!=_mp.end();++i){
        cout << "\t" << i->first << ":";
        cout << "\t" << i->second << endl;
    }
    cout << endl;
}

void display(map<int, int> _mp){
    cout << "Elements:\n";
    for(auto i=_mp.begin(); i!=_mp.end(); ++i){
        cout << "\t" << i->first << ":";
        cout << "\t" << i->second << endl;
    }
}

int main(){
    cout << "...map (<algorithm>)..." << endl;

    map<string, string> mp;
    check(mp);

    mp["two"]="dos";
    mp["one"]="uno";
    mp.insert({"three", "tres"});
    mp.insert({"four", "cuatro"});
    check(mp);

    mp.erase(mp.find("three"));
    check(mp);




    map<int, int> mp2;
    mp2[0]=4;
    mp2[1]=5;
    mp2[2]=6;
    mp2[3]=7;
    mp2[4]=8;
    display(mp2);
    map<int, int>::iterator iter = mp2.find(2);
    mp2.erase(mp2.find(3));

    display(mp2);
    

    return 0;
}
