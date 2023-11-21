//
//  main.cpp
//  LW05
//
//  Created by Учёба. on 13.06.17.
//  Copyright © 2017 Учёба. All rights reserved.
//

#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, const char * argv[]) {
    printf("Проверить правильность расположения в тексте круглых скобок (количество открывающихся и закрывающихся скобок должно совпадать). Пользуясь указателями определить и вывести на экран адреса символов, расположенных между 2й открывающейся и ближайшей закрывающейся скобками.\n\n");
    bool f = true;
    char str[50], *p;
    setlocale(0,"russian");
    
    cout << "Введите строку с круглыми скобками:" << endl;
    cin >> str;

    int n(0), m(0), i;
    for (i=0; i < strlen(str)-1; i++){
        if (str[i] == '(') n++;
        if (n == 2 && f){
            i++;
            cout<<"Адреса символов находящихся между второй парой скобок:"<<endl;
            do {
                p = &str[i];
                printf("str[%i] = %c = %p\n", i, str[i], p);
                i++;
            } while (str[i] !=')');
            f=false;
        }
        if (str[i] == ')')  m++;
    }
    if (n == m) cout << "Одинаковое количество скобок" << endl;
    else cout << "Не одинаковое количество скобок" << endl;

    return 0;
}

