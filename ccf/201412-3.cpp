//
// Created by Vsion Chiou on 2021/2/21.
//

#include "201412-3.h"

#include <iostream>
#include <math.h>
using namespace std;

typedef struct deal {
    string type;
    float price{0};
    long long count{0};
    bool cancel{false};
} deal;

int stock(){
    deal data[5001];
    int i=0;
    int row;
    while (cin>>data[i].type){
        if (i>5000) return 0;

        if(data[i].type=="cancel"){
            cin>>row;
            if (row<1||row>i) return 0;
            data[row-1].cancel = true;
        }else{
            if (data[i].type=="buy"||data[i].type=="sell"){
                cin>>data[i].price;
                if (data[i].price>10000) return 0;
                cin>>data[i].count;
                if (data[i].count>pow(10,8)) return 0;
            }else return 0;

        }

        i++;
    }


    float end_price = 0.00;
    long long sum[5001];
    long long buy_sum=0,sell_sum=0;

    for (int j = 0; j < i; ++j) {
        if (!data[j].cancel){
            end_price = data[j].price;
            for (int k = 0; k < i; ++k) {
                if (data[k].cancel) continue;
                if (data[k].type=="buy"&&data[k].price>=end_price){
                    buy_sum+=data[k].count;
                }else if(data[k].type=="sell"&&data[k].price<=end_price){
                    sell_sum+=data[k].count;
                }

            }
            sum[j] = min(buy_sum,sell_sum);
            buy_sum=0;
            sell_sum = 0;
        }

    }
    float max_price=0;
    long long max=0;
    for (int j = 0; j < i; ++j) {
        if (sum[j]>max&&!data[j].cancel){
            max = sum[j];
            max_price = data[j].price;
        }
        if (sum[j]==max){
            if(data[j].price>max_price) max_price = data[j].price;
        }

    }
    printf("%.2lf %lld",max_price, max);
    return 0;
}

//空间换时间
/*

#include <iostream>
#include <math.h>
#include "algorithm"
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

typedef struct deal {

    string name;
    double price{0.00};
    long long count{0};
}deal;

bool cmp(deal a, deal b){
    return a.price<b.price;
}

int main(){
    int i,n,j;
    int a[5001]={0};
    deal p[5001],sell[5001],buy[5001];
    int is=0,ib=0;
    double mpr=0,repr=0;
    long long mam=0,ream=0;
    long long alls=0.00,allb=0.00;
    n=1;
    while (cin>>p[n].name){
        if (p[n].name!="cancel"){
            cin>>p[n].price>>p[n].count;
            a[n++]=0;
        }else{
            int del;
            cin>>del;
            a[del]=1;
            n++;
        }
    }
    for (i = 1;  i<n ; i++) {
        if(a[i]==0){
            if (p[i].name=="buy"){
                buy[ib].name = "buy";
                buy[ib].count = p[i].count;
                buy[ib].price = p[i].price;
                ib++;
            }else if(p[i].name=="sell"){
                sell[is].name="sell";
                sell[is].count=p[i].count;
                sell[is].price = p[i].price;
                is++;
            }
        }

    }

    sort(sell,sell+is,cmp);
    sort(buy,buy+ib,cmp);

    for (i=ib-1; i >= 0; i--) {
        allb+=buy[i].count;
        mpr = buy[i].price;
        alls = 0.00;
        for (j = 0;  j< is; j++) {
            if(sell[j].price>mpr) break;
            alls+=sell[j].count;

        }
        mam = min(alls, allb);
        if (mam>ream){
            ream = mam;
            repr = mpr;
        }
    }
    printf("%.2lf %lld\n",repr, ream);
    return 0;

}

*/


/*
测试样例：
sell 8.88 100
sell 8.88 175
sell 9.00 400
buy 8.88 400
cancel 1
sell 100.00 50
8.88 175
buy 9.25 100
buy 8.88 175
buy 9.00 400
sell 8.88 400
cancel 1
buy 100.00 50
9.00 400
buy 9.25 100
buy 8.88 175
buy 9.00 400
sell 8.79 1501
cancel 1
cancel 2
9.00 400
buy 9.25 110
buy 8.88 300
buy 18.88 200
sell 8.88 201
sell 9.25 100
9.25 301
*/




