#include<iostream>
#include<unordered_map>     // Hash Table -> maps the "key" to the "value"
#include<string>

using namespace std;

int main(){
    cout << "...unordered_map (Hash Table)..." << endl;

    unordered_map<string, string> map_numbers;
    map_numbers = { {"one", "uno"},
                    {"two", "dos"}};
    map_numbers["three"] = "tres";
    map_numbers["four"] = "cuatro";


    cout << "one is ";
    cout << map_numbers["one"] << endl;

    cout << "size is ";
    cout << map_numbers.size() << endl;

    for(auto i=map_numbers.begin(); i!=map_numbers.end();++i){
        cout << i->first << ":";
        cout << i->second << endl;
    }

    cout << "Count of the key: one";
    cout << map_numbers.count("one") << endl;

    return 0;
}

// Hash Table:
//     "Key" & "Value" pairs

//     Usage
//     .first -> "key"
//     .second -> "value"

//     Operations:
//         count() -> Return "true" if "key" is in the map.
//         erase()
//         begin()
//         end()


// Pros:
//     Lookup "Fast"

// What is "Hash"?
