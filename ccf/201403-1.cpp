//
// Created by Vsion Chiou on 2021/1/24.
//

#include "201403-1.h"

#include <iostream>

using namespace std;

void getZero(){
    int n, count = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (arr[i]==(0-arr[j])){
                count++;
            }

        }
    }
    cout<<count;
}


