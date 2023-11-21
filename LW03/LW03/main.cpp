//
//  main.cpp
//  LW03
//
//  Created by Учёба. on 12.06.17.
//  Copyright © 2017 Учёба. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    
    div_t divresult;
    int x, y;
    setlocale(0,"russian");
    
    cout << "Введите натуральное число: ";
    cin >> x;
    cout << x << endl;
    y = 0;
    while (x > 0){
        divresult = div(x,10);
        y = y + divresult.rem;
        x = divresult.quot;
    }
    cout << "Сумму цифр заданного натурального числа будет равна ->  " << y << endl;
    
    //    system("pause");
    return 0;
}

