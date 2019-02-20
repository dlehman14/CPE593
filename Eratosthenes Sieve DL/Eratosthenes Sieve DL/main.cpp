//
//  main.cpp
//  Eratosthenes Sieve DL
//  collaborators - KC Vasilas, Justin Trugman
//  Websites used - https://www.geeksforgeeks.org/sieve-of-eratosthenes/
//  Created by David Lehman on 1/28/19.
//  Copyright © 2019 David Lehman. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int seive (int n){
    bool sieve[n];
    int count = 1;
    for(int i = 3; i <= n; i+=2)
        sieve[i] = true;
  //  for(int i = 4; i <= n; i+=2)
    //    sieve[i] = false;
    for(int i = 3; i <= n; i+=2)
    {
        if (sieve[i])
        {
            count ++;
            for(int j = i*i; j <= n; j += 2*i)
                sieve[j] = false;
        }
    }
    return count;
}
int main() {
    cout << seive(25) << endl;
    
}
