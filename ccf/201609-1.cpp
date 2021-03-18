//
// Created by Vsion Chiou on 2021/3/17.
//

#include "201609-1.h"

#include <iostream>

using namespace std;

int getMax(){
    int arr[1001];
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int max = 0;
    for (int i = 1; i < n; ++i) {
        if (abs(arr[i-1]-arr[i])>max) max = abs(arr[i-1]-arr[i]);
    }
    cout<<max;
    return 0;
}

/*
int main(){
    getMax();
    return 0;
}
*/


