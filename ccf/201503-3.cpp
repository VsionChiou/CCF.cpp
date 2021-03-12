//
// Created by Vsion Chiou on 2021/3/3.
//

#include "201503-3.h"

#include <iostream>
#include <map>

using namespace std;

typedef struct date{
    int year{0};
    int month{0};
    int day{0};
}date;
int getDate(){
    date date[5000];
    map<int, int> month = {{1, 31},{3, 31},{5,31},{7,31},{8,31},{10,31},{12,31},
                           {4,30},{6,30},{9,30},{11,30}
                           };
    int a,b,c,y1,y2;
    int day_gap1 = 0;
    int day_gap2;
    cin>>a>>b>>c>>y1>>y2;

    //get year
    for (int i = 1850; i < y1; ++i) {
        if (i<y1){
            if (i%400==0||(i%4==0&&i%100!=0)){
                day_gap1+=366;
            }else day_gap1+=365;
        }
    }
    day_gap2 = day_gap1;
    for (int i = y1; i <= y2; ++i) {
        day_gap1 = day_gap2;
        bool i_run;
        if (i%400==0||(i%4==0&&i%100!=0)){
            i_run = 1;
            month[2] = 29;
        }else{
            i_run = 0;
            month[2] = 28;
        }
        //get month
        for (int j = 1; j < a; ++j) {
            day_gap1 += month[j];
        }

        int weekday1 = 2+day_gap1%7;
        if (weekday1>7) weekday1 %=7;
        int day1 = 0;
        int end_day1;

        for (int k = weekday1; k <= 14; ++k) {
            day1++;
            if(k>7) k%=7;
            if (k==c) break;
        }
        if (b>1) end_day1 = 7*(b-1)+day1;
        else end_day1 = day1;
        if (end_day1>month[a]) end_day1=0;
        date[i-y1].year = i;
        date[i-y1].month = a;
        date[i-y1].day = end_day1;

        if (i_run) day_gap2+=366;
        else day_gap2+=365;
    }

    for (int i = 0; i <= y2-y1; ++i) {
        if (date[i].day) printf("%04d/%02d/%02d\n",date[i].year,date[i].month,date[i].day);
        else cout<<"none"<<endl;
    }

    return 0;
}

/*int main(){
    getDate();
    return 0;
}*/

