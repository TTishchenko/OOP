//
//  main.cpp
//  LW02
//
//  Created by Учёба. on 12.06.17.
//  Copyright © 2017 Учёба. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    float x, y;
    setlocale(0,"russian");
    
    cout << "Введите х: ";
    cin >> x;
    y = (1-sqrt(1 + abs(sin(x * PI / 180))))/(2 + pow(cos(x * PI / 180),2));
    cout << "Решением уравнения y=(1-pow((1+abs(sin(x)))),1/2))/(2+pow(cos(x),2)) будет  ->  " << y << endl;
    
//    system("pause");
     return 0;
}
