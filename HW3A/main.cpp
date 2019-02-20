//
//  main.cpp
//  Hw3a
//  https://stackoverflow.com/questions/17724925/parse-string-containing-numbers-into-integer-array
//  https://www.geeksforgeeks.org/insertion-sort/
//  Created by David Lehman on 2/7/19.
//  Copyright © 2019 David Lehman. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> insertionSort(int length, vector<int> values)
{
    vector<int> sorted;
    sorted.push_back(values.at(0));
    bool inserted;
    int count = 1;
    for(int i = 1; i < length; i++)
    {
        inserted = false;
        for(int j = 0; j < i; j++){
            if(sorted.at(j) > values.at(i)){
                sorted.insert(sorted.begin()+j,values.at(i));
                inserted = true;
                break;
            }
        }
        if(inserted == false)
            sorted.push_back(values.at(i));
        count++;
    }
    for(int i = 0; i < count; i++){
        cout << sorted.at(i) << " ";
    }
    cout << endl;
    return sorted;
}

int main() {
    //Open the file
    ifstream fs;
    fs.open("hw3.dat");
    
    //Read the first line and convert it to int
    string line;
    getline(fs, line);
    int length = stoi(line);
    
    vector<int> values;
    int n;
    
    //Read the Second line and convert it to a vector of ints
    while(getline(fs, line))
    {
        stringstream stream(line);
        while(stream >> n)
            values.push_back(n);
    }
    vector<int> sorted = insertionSort(length,values);
    bool test = true;
    for(int i = 1; i < length; i++)
    {
        if(sorted.at(i) < sorted.at(i-1))
        {
            test = false;
            cout << i << endl;
        }
    }
    if(test == true)
        cout << "Sort Worked" << endl;
    else
        cout << "Sort did not work" << endl;
    return 0;
}
