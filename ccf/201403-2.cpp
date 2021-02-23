//
// Created by Vsion Chiou on 2021/1/24.
//

#include "201403-2.h"

#include <iostream>

using namespace std;


void window(){
    int n, m;
    cin>>n>>m;
    int arr[n][4];
    int arr1[m][2];
    int priority[n];
    int copy[n];
    int order[n];
    int ans[m];
    int max=-1;
    int flag = -1;
    for(int i = 0;i<m;i++){
        ans[i] = -1;
    }
    for(int i = 0;i<n;i++){
        priority[i] = i;
        for(int j=0;j<4;j++){
            cin>>arr[i][j];

        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>arr1[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            copy[j] = priority[j];
        }
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                if(copy[j]>max&&copy[j]>=0){
                    max = copy[j];
                    flag = j;
                }

            }
            if (flag>=0&&arr1[i][0]>=arr[flag][0]&&arr1[i][0]<=arr[flag][2]
                                          &arr1[i][1]>=arr[flag][1]&&arr1[i][1]<=arr[flag][3]){

                ans[i] = flag+1;
                for (int j = 0; j < n; ++j) {
                    if (priority[j]>max){
                        priority[j]--;
                    }
                    else if(j==flag){
                        priority[j]=n-1;
                    }
                }
                break;
            }
            copy[flag] = -1;
            max = -1;
        }

    }
    for (int i = 0; i < m; ++i) {
        if (ans[i]>=0)
            cout<<ans[i]<<endl;
        else cout<<"IGNORED"<<endl;

    }
}


/*

#include "201403-2.h"

#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int arr[n][4];
    int arr1[m][2];
    int priority[n];
    int copy[n];
    int order[n];
    int ans[m];
    int max=-1;
    int flag = -1;
    for(int i = 0;i<m;i++){
        ans[i] = -1;
    }
    for(int i = 0;i<n;i++){
        priority[i] = i;
        for(int j=0;j<4;j++){
            cin>>arr[i][j];

        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>arr1[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            copy[j] = priority[j];
        }
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                if(copy[j]>max&&copy[j]>=0){
                    max = copy[j];
                    flag = j;
                }

            }
            if (flag>=0&&arr1[i][0]>=arr[flag][0]&&arr1[i][0]<=arr[flag][2]
                                                   &arr1[i][1]>=arr[flag][1]&&arr1[i][1]<=arr[flag][3]){

                ans[i] = flag+1;
                for (int j = 0; j < n; ++j) {
                    if (priority[j]>max){
                        priority[j]--;
                    }
                    else if(j==flag){
                        priority[j]=n-1;
                    }
                }
                break;
            }
            copy[flag] = -1;
            max = -1;
        }

    }
    for (int i = 0; i < m; ++i) {
        if (ans[i]>=0)
            cout<<ans[i]<<endl;
        else cout<<"IGNORED"<<endl;

    }
    return 0;
}

*/


