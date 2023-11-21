//
//  main.cpp
//  DZ2.1
//
//  Created by Tatiana on 15.06.2018.
//  Copyright © 2018 Tatiana. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

int myLength(string s) {
    // получаем длину строки s
    
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

string mySubstr (string s, int startPos, int count) {
    
    //s         - строка из которой вырезаем
    //startpos  - начиная с какой позиции
    //count     - сколько символов
    
    string newstring = "";
    for (int i = 0; i < count; i++) {
        newstring += s[startPos + i];
    }
    return newstring;
}

int myFind (string s, char search, int startpos) {
    
    //s         - строка в которой ищем
    //search    - что ищем
    //startpos  - начиная с какой позиции искать

    for (int i = startpos; i < myLength(s); i++) {
        if (s[i] == search) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    time_t t1, t2;
    string input1;
    vector<string> fullist;
    fullist.reserve(10);    // резервируем место для 10 элементов сразу, иначе будет при добавлении каждого элемента пересчитывать размерность. не обязательно)
    
    printf("Дана последовательность строк, содержащая данные о сотрудниках некоторого учреждения, записанные по образцу: Фамилия  Имя Отчество. Написать программу, обеспечивающую ввод строк и их корректировку. Корректировка заключается в записи данных по образцу\nА) Имя Отчество Фамилия;\t\tБ) Фамилия И.О.\nВывести на печать исходную и скорректированную последовательности строк. Реализовать как с использованием библиотечных функций работы со строками, так и с помощью собственной их реализации. Оценить время выполнения программы разными реализациями.\n\n");
    
    while(true) {
        cout << "Введите Фамилию Имя Отчество: ";
        getline(cin, input1);
        if(input1.empty()) break;
        fullist.push_back(input1);
    }
    
    //cout << "Всего записей: " << fullist.size();
    
    cout << "_____________своими функциями______________" << endl << endl;
    
    time(&t1);
    for (int i = 0; i < fullist.size(); i++) {
        string tmp[3];
        string fullname = fullist[i];
        
        //фамилия
        int pos = myFind(fullname, ' ', 0);
        tmp[0] =  mySubstr(fullname, 0, pos);
        
        //имя
        int pos1 = myFind(fullname, ' ', pos + 1);
        tmp[1] = mySubstr(fullname, pos + 1, pos1-pos-1);
        string short1 = mySubstr(tmp[1], 0, 1);
        
        //отчество
        tmp[2] = mySubstr(fullname, pos1 + 1, (myLength(fullname)-pos1));
        string short2 = mySubstr(tmp[2], 0, 1);
        
        cout << setw(41) << left << tmp[1] + " " + tmp[2] + " " + tmp[0] << setw(21) << right << tmp[0] + " " + short1 + "." + short2 + "."  << endl;
    }
    
    time(&t2);
    cout << "Время: " << difftime(t2, t1) << endl << endl;
    
    cout << "____________стандартными функциями_______________" << endl << endl;
    time(&t1);
    for (int i = 0; i < fullist.size(); i++) {
        string tmp[3];
        string fullname = fullist[i];
        
        //фамилия
        long pos = fullname.find(" ");
        tmp[0] = fullname.substr(0, pos);
        
        //имя
        long pos1 = fullname.find(" ", pos + 1);
        tmp[1] = fullname.substr(pos + 1, pos1-pos-1);
        string short1 = tmp[1].substr(0, 1);
        
        //отчество
        tmp[2] = fullname.substr(pos1 + 1);
        string short2 = tmp[2].substr(0, 1);
        
        cout << setw(41) << left << tmp[1] + " " + tmp[2] + " " + tmp[0] << setw(21) << right << tmp[0] + " " + short1 + "." + short2 + "."  << endl;
    }
    
    time(&t2);
    cout << "Время: " << difftime(t2, t1) << endl << endl;
    
    return 0;
    
}
