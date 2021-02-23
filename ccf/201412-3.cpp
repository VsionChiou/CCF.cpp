//
// Created by Vsion Chiou on 2021/2/21.
//

#include "201412-3.h"

#include <iostream>

using namespace std;

typedef struct deal {
    string type;
    float price{0};
    int count{0};
} deal;

int stock(){
    deal data[1500];
    int i=0;
    int row;
    while (i<1500||){
        cin>>data[i].type;
        if(data[i].type=="cancel"){
            cin>>row;
            data[row-1].type="";
            data[row-1].price=0;
            data[row-1].count=0;
            i-=2;
        }else{
            cin>>data[i].price>>data[i].count;
        }

        i++;
    }
    for (int j = 0; j < i; ++j) {
        cout<<data[j].type<<endl;
    }
}

