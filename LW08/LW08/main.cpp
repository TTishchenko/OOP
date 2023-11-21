//
//  main.cpp
//  LW08
//
//  Created by Учёба. on 15.06.17.
//  Copyright © 2017 Учёба. All rights reserved.
//

#include <stdio.h>
#include <locale.h>
#include <iostream>
using namespace std;

class symbol{
    public:
        char s;
    symbol(char symb){ s=symb; };
    symbol();
    void print(){
        cout << "Значение символа: " << s << endl;
    };
    void stoi(){
        cout << "значение символьного поля: " << s << endl << "Числовой код символа: " << (int)s << endl;
    };
};

class ssymbol: public symbol {
    public:
    
    ssymbol(char symb):symbol(symb){  };
    void prints(){
        print();
    };
    void stoiands(){
        stoi();
        cout << "Размер: 8 байт" << endl;
    };
};

int main(int argc, const char * argv[]) {
    char sym;
    setlocale(0,"russian");
    
    cout << "Введите символ: ";
    cin >> sym;
    cout << "Первый объект: " << endl;
    symbol Q(sym);
    Q.print();
    Q.stoi();
    cout << "Второй объект: " << endl;
    ssymbol Z(sym);
    Z.prints();
    Z.stoiands();
    
    return 0;
}
