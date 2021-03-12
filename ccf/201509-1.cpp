//
// Created by Vsion Chiou on 2021/3/4.
//

#include "201509-1.h"

#include <iostream>

using namespace std;

int arraySplite(){
    int arr[1001];
    for (int & i : arr) {
        i = -2;
    }
    int n;
    int count = 0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        //if (arr[i]>1000||arr[i]<0) return 0;
    }
    for(int i=0;i<n;i++){
        if (arr[i] == arr[i+1]){
            continue;
        }else count++;
    }
    cout<<count;
    return 0;

}

/*int main(){
    arraySplite();
    return 0;
}*/


