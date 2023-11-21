//
//  main.cpp
//  RK1
//
//  Created by Tatiana on 22.06.2018.
//  Copyright © 2018 Tatiana. All rights reserved.
//

#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

std::vector<int> a(4);
int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int b[4][4], i, j;
    
    cout<<"Исходный массив:\n";
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            b[i][j]=rand()%9+1;
            a[i]=a[i]+b[i][j];
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
    
    cout<<"\n\nСформированный вектор:\n";
    for (i=0; i<4; i++) {
        cout<<a[i]<<' ';
    }
    
    cout<<"\n\nАдресса элементов вектора:\n";
    for (i=0; i<4; i++) {
        cout<<&a[i]<<endl;
    }
    
    return 0;
}
