//
// Created by Vsion Chiou on 2021/1/21.
//



#include <iostream>

using namespace std;

int find_smallest(){
    int num;
    int count;
    cin>>num;
    int arr[10001] = {0};
    for (int i = 0; i < num; ++i) {
        cin>>count;
        arr[count]++;

    }
    int max_num = 0;
    int max_count = 0;
    for (int i = 1; i < 10001; ++i) {
        if (arr[i]>max_num){
            max_num = arr[i];
            max_count = i;

        }
    }
    cout<<max_count<<endl;
    return max_count;

}

/*

int main(){
    int num;
    int count;
    cin>>num;
    int arr[10001] = {0};
    for (int i = 0; i < num; ++i) {
        cin>>count;
        arr[count]++;

    }
    int max_num = 0;
    int max_count = 0;
    for (int i = 1; i < 10001; ++i) {
        if (arr[i]>max_num){
            max_num = arr[i];
            max_count = i;

        }
    }
    cout<<max_count;
    return 0;
}


*/
