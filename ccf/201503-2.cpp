//
// Created by Vsion Chiou on 2021/3/2.
//

#include "201503-2.h"

#include <iostream>


using namespace std;

int digitalsort(){
    int number;
    int count[1001]={0};
    int n;
    cin>>n;
    if (n<1||n>1000) return 0;
    for (int i = 0; i < n; ++i) {
        cin>>number;
        if (number>1000||number<0) return 0;
        count[number]++;
    }
    int max=0;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1001; ++j) {
            if (count[j]>0&&count[j]>max){
                max = count[j];
                num = j;
            }

        }
        if (max>0){
            printf("%d %d\n",num,max);
            count[num] = 0;
            max = 0;
            num = 0;
        }

    }
    
    return 0;

}
/*int main(){
    digitalsort();
    return 0;
}*/


