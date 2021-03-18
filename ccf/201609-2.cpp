//
// Created by Vsion Chiou on 2021/3/17.
//

#include "201609-2.h"

#include <iostream>
#include <vector>

using namespace std;

int train_ticket(){
    vector<vector<int>> seat(20);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 5; ++j) {
            seat[i].push_back(0);
        }
    }
    int n;
    cin>>n;

    int temp;

    for (int i = 0; i < n; ++i) {
        cin>>temp;
        int irrelate = 0;
        bool irflag = false;
        bool flag = false;

        vector<pair<int, int>> arr;
        vector<pair<int, int>> irarr;
        for (int j = 0; j < 20; ++j) {
            int relate = 0;
            bool first_come = false;
            for (int k = 0; k < 5; ++k) {
                if (!seat[j][k]) {
                    if (!first_come) relate = 5-k;
                    first_come = true;
                    irarr.push_back({j, k});
                    irrelate++;
                }
            }
            if (relate>=temp) {
                for (int m = 5-relate; m < 5&&arr.size()<=temp; ++m) {
                    arr.push_back({j, m});
                }
                flag = true;
                break;
            }
        }
        if (irarr.size()>=temp) irflag = true;
        if (flag){
            for (int j = 0; j < temp; ++j) {
                seat[arr[j].first][arr[j].second] = 1;
                cout<<(arr[j].first)*5+(arr[j].second+1)<<" ";
            }
        }else if (irflag){
            for (int j = 0; j < temp; ++j) {
                seat[irarr[j].first][irarr[j].second] = 1;
                cout<<(irarr[j].first)*5+(irarr[j].second+1)<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
int main(){
    train_ticket();
    return 0;
}*/

/*

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int main(){
    int n,t,a[21][7];
    memset(a,0,sizeof(a));
    for(int i=0;i<20;i++) a[i][5]=5;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        int flag=0;
        for(int i=0;i<20;i++){
            if(a[i][5]>=t){
                a[i][5]-=t;
                for(int j=0;j<5;j++){
                    if(!a[i][j]){
                        a[i][j]=1;
                        t--;
                        if(t) printf("%d ",i*5+j+1);
                        else{
                            if(n) printf("%d\n",i*5+j+1);
                            else printf("%d",i*5+j+1);
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(flag) break;
        }
        if(!flag){//无连续的座位
            for(int i=0;i<20;i++){
                for(int j=0;j<5;j++){
                    if(!a[i][j]){
                        a[i][j]=1;
                        t--;
                        a[i][5]--;
                        if(t) printf("%d ",i*5+j+1);
                        else{
                            if(n) printf("%d\n",i*5+j+1);
                            else printf("%d",i*5+j+1);
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
        }
    }
    return 0;
}
*/
