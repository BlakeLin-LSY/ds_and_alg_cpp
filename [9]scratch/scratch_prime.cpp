#include<iostream>
#include<string>
#include<vector>

using namespace std;

// ======= TLE ======= 
// int countPrimes(const int& n) {
//     int ans=0;
//     int i=2;
//     vector<int> primes;
//     while(i<n){
//         cout << "i= " << i << ", ";
//         bool isPrime=true;
//         for(int j=0; j<primes.size(); ++j){
//             isPrime=false;
//             if(i%primes[j]==0) break;
//             isPrime=true;
//         }
//         if(isPrime) primes.push_back(i);
//         cout << isPrime << endl;
//         ++i;
//     }
//     cout << "ans= " << primes.size() << endl;
//     return primes.size();
// }

int countPrimes(const int& n) {
    int count=0;
    vector<bool> isPrime(n, true);
    for(int i=2; i*i<n; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<n; j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=2; i<n; ++i){
        if(isPrime[i]) ++count;
    }

    return count;
}

int main()
{
    int x=499979;
    // int x=20;
    int res=countPrimes(x);
    cout << "input N= " << x << endl;
    cout << "ans= " << res << endl;

    return 0;
}