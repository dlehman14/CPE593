//
//  Main.cpp
//  Quicksort
//  Websites - https://www.geeksforgeeks.org/quick-sort/
//  textbooks - Open Data Structures (in C++)
//  Created by David Lehman on 2/14/19.
//  Copyright © 2019 David Lehman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void Quicksort(int x[], int L, int R)
{
    static int a = 0;
    int pivot;
    if (R <= L || R <= 1)
        return;
    if ((R-1) == L && x[R] == x[L])
        return;
    if(a % 2 == 0)
        pivot = x[L];
    else
        pivot = x[R];
    int i = L;
    int j = R;
    while (i<j) {
        while (x[i] < pivot && i < j) {
            i++;
        }
        while (x[j] >= pivot && i < j) {
            j--;
        }
        swap(x[i],x[j]);
    }
    a++;
    /*  if(a < 11)
    {
        cout << a << " " << pivot << "\t";
        cout << i << " " << j << " \t\t";
        cout << L << " " << R << endl;
    }
    if(a < 11){
        for(int i = 0; i < 11; i++)
            cout << x[i] << " ";
        cout << endl;
    } */
    if ((i-1) > L)
        Quicksort(x,L,i-1);
    Quicksort(x,i,R);
}

int main() {
    ifstream fs;
    fs.open("hw3.dat");
    
    string line;
    getline(fs, line);
    int length = stoi(line);
    int x[length];
    for(int i = 0; i < length; i++)
        fs >> x[i];
    Quicksort(x,0,length-1);
    for(int i = 0; i < length; i++)
        cout << x[i] << " ";
    cout << endl;
}
