//
// Created by Vsion Chiou on 2021/3/7.
//

#include "201512-1.h"

#include <iostream>

using namespace std;

int getSum(){
    long long n;
    long long sum = 0;
    cin>>n;
    for (int i = 0; n>0; ++i) {
        sum += n%10;
        n /= 10;
    }
    cout<<sum;

    return 0;
}
/*

int main(){
    getSum();
    return 0;
}
*/


