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

void quickSort(int x[], int L, int R) {
    int i = L, j = R;
    int pivot = (x[L] + x[R]) / 2;
    /* partition */
    while (i <= j) {
        while (x[i] < pivot)
            i++;
        while (x[j] > pivot)
            j--;
        if (i <= j) {
            swap(x[i],x[j]);
            if(i != R)
                i++;
            if(j != L)
                j--;
        }
    }
    /* recursion */
    if (L < (i-1))
        quickSort(x, L, i-1);
    if (i < R)
        quickSort(x, i, R);
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
    quickSort(x,0,length-1);
    for(int i = 0; i < length; i++)
        cout << x[i] << " ";
    cout << endl;
    bool test = true;
    for(int i = 1; i < length; i++)
    {
        if(x[i] < x[i-1])
            test = false;
    }
    if(test == true)
        cout << "Sort Worked" << endl;
    else
        cout << "Sort did not work" << endl;
    return 0;
}
