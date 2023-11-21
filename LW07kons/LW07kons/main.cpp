//
//  main.cpp
//  LW07kons
//
//  Created by Учёба. on 15.06.17.
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
    num(float x, float y){
        cout << "Конструктор" << endl;
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
    setlocale(0,"russian");
    for (int i=0; i<3; i++) {
       cout << "Введите мантиссу: ";
        cin >> a[i];
        cout << "Введите порядок: ";
        cin >> b[i];
        num thisn(a[i], b[i]);
        thisn.print();
        thisn.score(); 
    }
        
    
    return 0;
}

