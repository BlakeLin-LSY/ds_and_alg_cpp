#include <iostream>
#include <vector>
using namespace std;

// implement method that prints the first 100 prime numbers
// A prime number (or a prime) is a natural number greater than 1,
// that has no positive divisors other than 1 and itself. 
// To execute C++, please define "int main()"


bool isPrime(int k, vector<int>& ptable){
  if(k < 2) return false;
  for(size_t i=0; i<ptable.size(); ++i){
    if(k%ptable[i]==0) return false;
  }
  return true;
}

void primeN(int n){
  vector<int> primes;
  int num=2;

  while(n){
    if(isPrime(num, primes)){
      primes.push_back(num);
      n--;
    }
    else num++;
  }

  for(size_t i=0; i<primes.size(); ++i){
    cout << i+1 << ": " << primes[i] << "\n";
  }

}

int main() {
  primeN(100);
  return 0;
}


/*
:
  print first 100 prime number

Prime numbers: can only divide by 1, and itself.

# Idea:

  1. to go "i" from 2 ~ n/2, check n % i != 0
  2. vector of prime_numbers to store primes, and check the primes

  prime_numbers[last_i]

*/