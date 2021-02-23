//
// Created by Vsion Chiou on 2021/1/31.
//

#include "201412.h"

#include <iostream>
#include <stack>

using namespace std;

int banner(){
    int n;
    int x;
    int arr[1001] = {0};
    cin>>n;

    int ans[n];
    for (int i = 0; i < n; ++i) {
        cin>>x;
        if (x>n||x<=0) return 0;
        ans[i]=++arr[x];
    }
    for (int i = 0; i < n; ++i) {
        if (i!=n-1) cout<<ans[i]<<" ";
        else cout<<ans[i];
    }
    return 0;
}

int z_scanner(){
    int n;
//    stack<int> reverse;
    cin>>n;
    int arr[n][n];
    int ans[n*n];
    int k=0;
    int x=0;
    int flag = 1;
    bool nflag[n][n];


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>arr[i][j];
            nflag[i][j] = false;
        }
    }
    int i=0,j=0;
    while (k!=n*n){
        while (flag){
            if(k==n*n) break;

            if (i>=0&&j>=0&&i<n&&j<n&&!nflag[i][j]){
                ans[k++] = arr[i][j];
                nflag[i][j] = true;
                i--;
                j++;
            }
            else{
                if (nflag[i][j]&&i>=0&&i<n&&j>=0&&j<n){
                    if (i+1==n){
                        j++;
                    }else i++;
                    break;
                }
                if (j<0) j++;
                else if (i<0) i++;

                if (i>=n){
                    i--;
                    j++;
                }else if (j>=n){
                    j--;
                    i++;
                }
                flag=0;
            }
        }
        while (!flag){
            if (k==n*n) break;
            if (i>=0&&j>=0&&i<n&&j<n&&!nflag[i][j]){
                ans[k++] = arr[i][j];
                nflag[i][j] = true;
                i++;
                j--;
            }else{
                if (nflag[i][j]&&i>=0&&i<n&&j>=0&&j<n){
                    if (i+1==n){
                        j++;
                    }else i++;
                    break;
                }
                if (j<0) j++;
                else if (i<0) i++;

                if (i>=n){
                    i--;
                    j++;
                }else if (j>=n){
                    j--;
                    i++;
                }
                flag=1;
            }
        }
    }
    for (int y = 0; y < n*n; ++y) {
        cout<<ans[y]<<" ";
    }
    return 0;
}

