#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    ofstream fs;
    fs.open("HW4.dat");
    srand(time(NULL));
    int l = 10000;
    fs << l << endl;
    for(int i = 0; i < l; i++)
    {
        int num = rand()%500;
        fs << num << " ";
    }
    fs.close();
    return 0;
}
