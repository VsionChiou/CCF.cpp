//
// Created by Vsion Chiou on 2021/3/10.
//

#include "201604-1.h"

#include <iostream>

using namespace std;

int count(){
    int n;
    int data[1001] = {-1};
    int num=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>data[i];
    }
    for (int i = 1; i < n-1; ++i) {
        if ((data[i-1]>data[i]&&data[i]<data[i+1])||(data[i-1]<data[i]&&data[i]>data[i+1])){
            num++;
        }else continue;
    }
    cout<<num;
    return 0;
}

/*int main(){
    count();
    return 0;
}*/


