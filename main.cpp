//
// Created by Vsion Chiou on 2021/1/21.
//

#include <iostream>
#include <string>
#include "algorithm"
#include <map>
#include <sstream>
#include <typeinfo>

using namespace std;

void insertSort(int a[], int n){
    int i,j;
    for(i=2;i<=n;i++){
        if(a[i-1]>a[i]){
            for (j = i-1; a[0] < a[j]; j--) {
                a[j+1] = a[j];
            }
            a[j+1] = a[0];
        }
    }
}
/*
int main(){
    stringstream ss;
    int x = 911;
    ss<<x;
    string str;
    str = "str";
//    ss>>str;
    return 0;
}
*/

