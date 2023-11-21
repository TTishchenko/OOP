//
//  main.cpp
//  HW2.3
//
//  Created by Tatiana on 18.06.2018.
//  Copyright © 2018 Tatiana. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <locale>
#include <math.h>
#include <limits.h>
#include <string>
using namespace std;

int randomNumber() { return (rand()%30 + 1); }  //генерируем случайное число от 1 до 30
int main(){
    unsigned int const countRec = 15;
    srand ( unsigned ( time(NULL) ) );
    unsigned int i;
    int x;
    printf("Организовать программным способом файл F, компоненты которого являются целыми числами. Получить в файле G все компоненты файла F, делящиеся на 3 и не делящиеся на 7. Порядок следования чисел сохраняется. Вывести на экран оба файла.\n\n");
    
    FILE *pFile1 = fopen("/Volumes/Macintosh HD/Бомонка/семестр 2/ООП/HW/HW2.3/f.txt", "w");
    if (!pFile1){
        printf("Файл не может быть открыт!\n");
        return 1;
    }
    
    for (i=0; i<countRec ;++i)
        fprintf(pFile1, "%d ", randomNumber ());
    fclose(pFile1);
    
    pFile1 = fopen("/Volumes/Macintosh HD/Бомонка/семестр 2/ООП/HW/HW2.3/f.txt", "r");        //считываем и записываем требуемые значения
    FILE *pFile2 = fopen("/Volumes/Macintosh HD/Бомонка/семестр 2/ООП/HW/HW2.3/g.txt", "w");
    if (!pFile1 || !pFile2){
        printf("Файл не может быть открыт!\n");
        return 1;
    }
    
    string s, sym; //char *sym;//создание строки для вывода на экран
    cout<<"Файл F:"<<endl;
    for (i = 0; i <countRec; i++){
        fscanf(pFile1, "%d", &x);
        cout << x << ' ';
        if (x % 3 ==0 && x % 7 != 0)
        {
            fprintf(pFile2, "%d ", x);
//            itoa(x, sym, 10);
            sym = std::to_string(x);
            s += sym;
            s += ' ';
        }
    }
    cout<<endl<<"Файл G:"<<endl<<s<<endl;
    
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

