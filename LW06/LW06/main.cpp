//
//  main.cpp
//  LW06
//
//  Created by Учёба. on 15.06.17.
//  Copyright © 2017 Учёба. All rights reserved.
//

//#include <stdio.h>
//#include <locale.h>
//#include <iostream>
//using namespace std;
//
//struct comp{
//    char ln[20];
//    int score;
//    comp *p;
//};
//
//int main(int argc, const char * argv[]) {
//    comp *first, *next, *prev;
//    char lname[20];
//    int rez, fl;
//    
//    setlocale(0,"russian");
//    
//    cout << "Введите фамилии участников: " << endl;
//    
//    for (int i=0;i<9;i++){
//        
//        
//    }
//    
//    fl=1;
//    while (fl!=0){
//        fl=0;
//        for(i=0; i<9; i++)
//            if (strcmp(laba[i].name, laba[i+1].name)>0) {
//                tmp=wed[i];
//                wed[i]=wed[i+1];
//                wed[i+1]=tmp;
//                fl++;
//            }
//    }
//    
//    return 0;
//}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
struct zap {char sl[15];zap *p;};

int main(int argc, char* argv[]){
    zap *dop1, *dop2, *cur, *prev, *first, *firstc;
    char stres[20];
    int fl;
    
    // создаем первую запись
    puts ("Vvedite stroky slov razdelennyx probelami. tochka - konec vvoda:");
    prev=new zap;
    first=new zap;
    firstc=new zap;
    strcpy (first->sl,"testing");
    
    
    // организуем цикл обработки слов
    while ((strcmp(stres,"")!=0) & (strlen(stres)!=1)){
        scanf ("%s", stres);                    //вводим очередное слово
        cur=new zap;
        
        if (strstr (stres,".")!=NULL){
            fl=strlen(stres);
            stres[fl-1]='\0';
            strcpy (cur->sl,stres);
            strcpy (stres,"");             //если последнее слово, вырезаем точку
        }
        else strcpy (cur->sl,stres);
        
        cur->p=NULL;                                                               //заносим его в указатель cur
        if (strcmp(first->sl,"testing")!=0){
            prev->p=cur;
            if (strcmp(cur->sl,first->sl)<0){
                prev->p=NULL;
                cur->p=first;
                first=cur;
                cur=prev;
                firstc=first;
            } else {
                dop1=first;
                fl=0;
                while ((dop1->p!=NULL) & (fl==0)){
                    dop2=dop1;
                    dop1=dop1->p;
                    if (strcmp(cur->sl,dop1->sl)<0){
                        prev->p=NULL;
                        cur->p=dop1;
                        dop2->p=cur;
                        cur=prev;
                        fl=1;
                    }
                }
            }
            prev=cur;                                                        //если не первый элемент
        }
        
        else {                            //если первый элемент
            first=cur;
            prev=cur;
            firstc=first;
        }
        //параметр выхода из цикла
    }
    
    
    //проверка верности упорядочивания очереди
    {puts ("");puts ("Slova stroki po alfavitu:");
        cur=firstc; fl=1;
        while (cur!=NULL){
            printf ("%2d) %s\n",fl,cur->sl);
            cur=cur->p;
            fl++;
        }
        
        
        //подсчет слов начинающихся на "а" и "м"
        puts ("");
        cur=firstc; fl=0;
        while (cur!=NULL){
            if ((cur->sl[0]=='a') || (cur->sl[0]=='m')) {
                printf("Slovo na 'a' ili 'm': %s \n",cur->sl);
                fl++;
            }
            cur=cur->p;
        }
        
        if (fl>0) printf ("Naideno %d slov na 'a' ili 'm'\n",fl);
        else puts ("Slov nachinaushihsya na bukvu 'a' ili 'm' ne naideno");
        
        getch();         return 0;
    }
}
