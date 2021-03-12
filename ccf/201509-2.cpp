//
// Created by Vsion Chiou on 2021/3/4.
//

#include "201509-2.h"

#include <iostream>
#include <map>

using namespace std;

int getday(){
    map<int, int> month = {{1,31},{3,31},{5,31},{7,31},{8,31},{10,31},{12,31},{4,30},{6,30},{9,30},{11,30}};
    int y;
    int d;
    cin>>y>>d;

    if (y%400==0||(y%4==0&&y%100!=0))
        month[2] = 29;
    else month[2] = 28;

    int i,j;
    for (i = 0,j=1; i < d; j++) {
        if (d>month[j]){
            i+=month[j];
        }else j--;
        if(i+month[j+1]>=d) break;


    }
    printf("%d\n%d",j+1,d-i);
    return 0;


}
/*int main(){
    getday();
    return 0;
}*/

