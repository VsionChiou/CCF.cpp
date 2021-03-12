//
// Created by Vsion Chiou on 2021/1/21.
//

#include <iostream>
#include <string>
#include "algorithm"
#include <map>

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
    int array[9] = {-1, 9, 2, 5, 8, 3, 7, 6, 1};
    insertSort(array, 8);
    for (int i = 1; i < 9; ++i) {
        cout<<array[i]<<endl;

    }
    return 0;
}*/

