#include <iostream>
#include <cstring>
// #include "sort.h"
#include "star.h"
using namespace std;

void line(){ cout << endl; }

int main() {
    cout << "u4bi c++ algorithm" <<endl;
    //Sort sort;
    //sort.bubble();
    //sort.insertion();
    //sort.quick();
    Star star;
    star.triangle(0);
    line();
    star.triangle(1);
    line();
    star.triangle(2);
    line();
    star.triangle(3);
    line();
    star.pyramid();
    line();
    star.diamond();
    
    return 0;
}