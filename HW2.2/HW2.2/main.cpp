//
//  main.cpp
//  HW2.2
//
//  Created by Tatiana on 18.06.2018.
//  Copyright © 2018 Tatiana. All rights reserved.
//

#include <iostream>
#include <clocale>
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace std;

inline int Err1(){// Встраиваемая конструкция, встраивается в текст программы во время вызова.
    cout<<endl<<"  Некорректный ввод! повторите ввод"<<endl; //в программе будет использования для сигнализации некорректного ввода данных
    return -1; //присваивает переменной-флагу отрицательное непроходное значение
}

inline void Err2(){ //комментарий по ошибке открытия файла (не существует / не заполнен)
    cout<<endl<<"  Ошибка! Файл не существует или пуст!"<<endl;
    cout<<endl<<"  Программа аварийно завершит свою работу"<<endl;
}

//void Print_task(){
//    fstream f;
//    f.open("task.txt", ios::in | ios::out);
//    string st, tim="";
//    if(!f.is_open()){
//        Err2();
//    }
//    while(!f.eof()){
//        f>>st;
//        if(st.size()==0){
//            Err2();
//        }
//        st+=" ";
//        tim+=st;
//    }
//    cout<<endl<<tim<<endl;
//    f.close();
//}

int num_str(){//Функция запрашивает ввод кол-ва строк в последовательности
    int rez, trg=-1;
    while(trg!=1){
        cout<<endl<<"  Введите кол-во строк"<<endl;
        cout<<"  ";
        cin>>rez;
        if(rez>0){
            cout<<endl<<"  Введено значение: "<<rez<<". Если количество верно, введите 1, в противном случае - 0"<<endl;
            cout<<"  ";
            cin>>trg;
        } else {
            trg=Err1();
        }
    }
    return rez;
}

bool In_symb(char s){
    bool rez;
    switch (s){
        case 'a': rez=true; break;
        case 'A': rez=true; break;
        case 'b': rez=true; break;
        case 'B': rez=true; break;
        case 'c': rez=true; break;
        case 'C': rez=true; break;
        case 'd': rez=true; break;
        case 'D': rez=true; break;
        case 'e': rez=true; break;
        case 'E': rez=true; break;
        case 'f': rez=true; break;
        case 'F': rez=true; break;
        case 'g': rez=true; break;
        case 'G': rez=true; break;
        case 'h': rez=true; break;
        case 'H': rez=true; break;
        case 'i': rez=true; break;
        case 'I': rez=true; break;
        case 'j': rez=true; break;
        case 'J': rez=true; break;
        case 'k': rez=true; break;
        case 'K': rez=true; break;
        case 'l': rez=true; break;
        case 'L': rez=true; break;
        case 'm': rez=true; break;
        case 'M': rez=true; break;
        case 'n': rez=true; break;
        case 'N': rez=true; break;
        case 'o': rez=true; break;
        case 'O': rez=true; break;
        case 'p': rez=true; break;
        case 'P': rez=true; break;
        case 'q': rez=true; break;
        case 'Q': rez=true; break;
        case 'r': rez=true; break;
        case 'R': rez=true; break;
        case 's': rez=true; break;
        case 'S': rez=true; break;
        case 't': rez=true; break;
        case 'T': rez=true; break;
        case 'u': rez=true; break;
        case 'U': rez=true; break;
        case 'v': rez=true; break;
        case 'V': rez=true; break;
        case 'w': rez=true; break;
        case 'W': rez=true; break;
        case 'x': rez=true; break;
        case 'X': rez=true; break;
        case 'y': rez=true; break;
        case 'Y': rez=true; break;
        case 'z': rez=true; break;
        case 'Z': rez=true; break;
        default: rez=false; break;
    }
    return rez;
}

bool In_num(char s){
    bool rez;
    switch(s){
        case '0': rez=true; break;
        case '1': rez=true; break;
        case '2': rez=true; break;
        case '3': rez=true; break;
        case '4': rez=true; break;
        case '5': rez=true; break;
        case '6': rez=true; break;
        case '7': rez=true; break;
        case '8': rez=true; break;
        case '9': rez=true; break;
        default : rez=false; break;
    }
    return rez;
}

bool In_sign(char s){
    bool rez;
    switch(s){
        case '+': rez=true; break;
        case '-': rez=true; break;
        case '*': rez=true; break;
        default: rez=false; break;
    }
    return rez;
}

bool check_correct(string str){
    bool rez=true;
    for(int i=0; (i<str.size() && rez); i++){
        if((In_symb(str[i])) || (In_num(str[i])) || (In_sign(str[i]))){
            rez=true;
        } else {
            rez=false;
        }
    }
    return rez;
}

string *Gen_posl(int n){// функция генерирует последовательность из заданного кол-ва строк
    string *arr=new string[n], ssss;// переменная strok нужна для корректной работы функции getline
    int trg_all=-1, trg; // строки также автоматически проверяются на корректность (все ли символы принадлежат
    while(trg_all!=1){ // заданным в условии множествам)
        for(int i=0; i<n; i++){
            cout<<endl<<"  Вводите строку номер "<<i+1<<endl;
            trg=-1;
            while(trg!=1){
                cout<<"  ";
                cin>>ssss;
                if(check_correct(ssss)){
                    cout<<endl<<"  Вы ввели строку:"<<endl<<"  "<<ssss<<endl<<"  Если строка введена корректно - введите 1, в проивном случае - 0"<<endl;
                    cout<<"  ";
                    cin>>trg;
                } else {
                    trg=Err1();
                }
            }
            arr[i]=ssss;
        }
        cout<<endl<<endl<<"  Вы ввели следующую последовательность строк: "<<endl<<endl;
        for(int i=0; i<n; i++){
            cout<<"  "<<arr[i]<<endl;
        }
        cout<<endl<<"  если все строки введены корректно, введите 1, в противном случае - 0."<<endl;
        cout<<"  ";
        cin>>trg_all;
    }
    return arr;
}

struct inp{
    int num;
    string *arr;
};

int num_s(){
    int rez=0;
    fstream f;
    string s;
    f.open("/Volumes/Macintosh HD/Бомонка/семестр 2/ООП/HW/HW2.2/text.txt", ios::in | ios::out);
    if(!f.is_open()){
        Err2();
    }
    while(!f.eof()){
        f>>s;
        if(s.size()==0){
            Err2();
        }
        rez++;
    }
    f.close();
    return rez;
}

string *arrr(int n){
    string *rez=new string[n], str;
    fstream f;
    int i=0;
    f.open("/Volumes/Macintosh HD/Бомонка/семестр 2/ООП/HW/HW2.2/text.txt", ios::in | ios::out);
    while(!f.eof()){
        f>>str;
        rez[i]=str;
        i++;
    }
    f.close();
    return rez;
}

inp* Enter(){
    int v=-1;
    inp *rez=new inp;
    while((v!=1) && (v!=2)){
        cout<<endl<<"  Вы можете ввести строки вручную, для этого введите 1"<<endl;
        cout<<"  Для чтения строк из файла введите 2"<<endl;
        cout<<"  ";
        cin>>v;
        if(v==1){
            rez->num=num_str();
            rez->arr=Gen_posl(rez->num);
        }
        if(v==2){
            rez->num=num_s();
            rez->arr=arrr(rez->num);
        }
        if((v!=1) && (v!=2)){
            v=Err1();
        }
    }
    return rez;
}

void start(){
    printf("Дана последовательность строк. Каждая строка состоит из групп букв, цифр и знаков +,-,*. Группой букв называется группа, которой не предшествует и за которой не следует буква. Группой цифр называется группа, которой не предшествует и за которой не следует цифра. Группой знаков называется группа, которой не предшествует и за которой не следует знак. Написать программу, определяющую в каждой строке количество групп цифр. Если таких групп четное количество, то заменить все группы цифр последовательностью символов «&&&&&&». Если количество групп цифр нечетное, оставить все без изменения. Если искомых групп в строке нет, то выдать сообщение. Вывести на печать исходную и скорректированную последовательность строк.\n\n");
}

void finish(){
    cout<<endl<<endl<<"Программа завершила свою работу"<<endl;
}

int num_num_groups(string str){
    int *s=new int[str.size()], counter=0;
    for(int i=0; i<str.size(); i++){//символ - 1, цифра - 2, знак - 3
        if(In_symb(str[i])){
            s[i]=1;
        }
        if(In_num(str[i])){
            s[i]=2;
        }
        if(In_sign(str[i])){
            s[i]=3;
        }
    }
    if(In_num(str[str.size()-1])){
        counter++;
    }
    for(int i=0; i<str.size()-1; i++){
        if((s[i]==2) && (s[i]!=s[i+1])){
            counter++;
        }
    }
    return counter;
}

string redakt(string s){
    string rez="";
    int num=num_num_groups(s);
    if(num==0){
        rez=s+" не содержит групп цифр";
    } else if((num%2)==1){
        rez=s;
    } else {
        for(int i=0; i<s.size(); i++){
            if(!In_num(s[i])){
                rez+=s[i];
            } else {
                rez+="&&&&&&";
                while(In_num(s[i])){
                    i++;
                }
                i--;
            }
        }
    }
    return rez;
}

void print_arr(string *arr, int n){
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<"  ";
        cout<<arr[i]<<endl;
    }
}

//void work(){
//    start();
//    inp* work_set=Enter();
//    cout<<endl<<"  Введено: "<<endl;
//    print_arr(work_set->arr, work_set->num);
//    for(int i=0; i<work_set->num; i++){
//        work_set->arr[i]=redakt(work_set->arr[i]);
//    }
//    cout<<endl<<endl<<endl<<"  после обработки: "<<endl;
//    print_arr(work_set->arr, work_set->num);
//    finish();
//}

int main(){
//    work();
    
    start();
    inp* work_set=Enter();
    cout<<endl<<"  Введено: "<<endl;
    print_arr(work_set->arr, work_set->num);
    for(int i=0; i<work_set->num; i++){
        work_set->arr[i]=redakt(work_set->arr[i]);
    }
    cout<<endl<<endl<<endl<<"  после обработки: "<<endl;
    print_arr(work_set->arr, work_set->num);
    finish();
    
    return 0;
}


