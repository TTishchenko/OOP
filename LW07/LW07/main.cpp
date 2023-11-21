//
//  main.cpp
//  LW07
//
//  Created by Учёба. on 14.06.17.
//  Copyright © 2017 Учёба. All rights reserved.
//

#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class num {
    public:
        float m, p;
    void set(float x, float y){
        m=x;
        p=y;
    }
    void print(){
        cout << "Мантисса = " << m << "; Порядок = " << p << endl;
    }
    void score(){
        cout << "Значение числа: "<< m*pow(10, p) << endl;
    }
};

int main(int argc, const char * argv[]) {
    float a[3], b[3];
    num thisn;
    setlocale(0,"russian");
    
    for (int i=0; i<3; i++) {
        cout << "Введите мантиссу: ";
        cin >> a[i];
        cout << "Введите порядок: ";
        cin >> b[i];
        thisn.set(a[i], b[i]);
        thisn.print();
        thisn.score(); 
    }
    
    
    return 0;
}
