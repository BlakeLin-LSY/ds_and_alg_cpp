#include <iostream>
#include <vector>
using namespace std;

bool isCW(vector<pair<int, int>>& states){
  // states would be [A, B] readings, states number == 2
  // eg:
  //    states = [[0, 0] , [1, 0]]
  
  if(states[0].first == states[0].second){
      // Same state, A change first --> CW;
      if (states[0].first != states[1].first) return true;
      return false;
  }
  else{
      // Different state, B change first --> CW;
      if (states[0].second != states[1].second) return true;
      return false;
  }
}




// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  // vector<pair<int, int>> t_states={{1, 0}, {0, 0}};   // Suppose to be CCW
  vector<pair<int, int>> t_states={{0, 0}, {1, 0}};   // Suppose to be CW
  
  cout << "Test case:\n\t";
  for(auto state:t_states) cout << state.first <<  ", " << state.second << " -> ";

  cout << "\nRotate direction is ";
  if(isCW(t_states)) cout << "CW\n";
  else cout << "CCW\n";

  return 0;
}

/*
: Find the rotating direction (CCW or CW)

white: reading 1
blake: reading 0

// A, B are 90 degrees in between

We need to use,
  1. the initial state
  2. switch state

the initial state:
   1. different state --> [1, 0] at different area
   2. same state --> [1, 1]  at same area 

[A, B]_i : initial state
[A, B]_s : switch state

--> difference of [A, B]_i, [A, B]_s state can tell us the rotating direction

eg.1:
  i: [1, 0]
  s: [1, 1]
  --> [0, 1] --> CW

  i: [0, 0]
  s: [1, 0] 
  --> [1, 0] --> CW

  i: [0, 1]

  [0, 0]

i_state:
  different: 0
  same: 1

  if(i_state): switch CW/CCW state to another



After interview
===========================================
total states of [A, B]
[0, 0]
[1, 1]
[0, 1]
[1, 0]

[0, 0], [1, 1] --> Same state
[0, 1], [1, 0] --> Diff state

Take a example (rotate 360 degrees):
CW:
  [0, 0] -> [1, 0] -> [1, 1] -> [0, 1] ``` -> [0, 0] ```

CCW:
  [0, 0] -> [0, 1] -> [1, 1] -> [1, 0] ``` -> [0, 0] ```


!! Critical Point !!
After [0, 0] or [1, 1]
  A change --> CW
  B change --> CCW

*/
