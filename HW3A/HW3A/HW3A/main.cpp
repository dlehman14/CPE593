//
//  main.cpp
//  HW3A
//
//  Created by David Lehman on 2/7/19.
//  Copyright © 2019 David Lehman. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream fs;
    fs.open("hw3.dat");
    string line;
    getline(fs, line);
    cout << line << endl;
}
