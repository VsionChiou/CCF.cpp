//
// Created by Vsion Chiou on 2021/3/7.
//

#include "201512-2.h"

#include <iostream>

using namespace std;

int findSimilar(){
    int arr[31][31] = {-1};
    int count[31][31];
    for (int i = 0; i < 31; ++i) {
        for (int j = 0; j < 31; ++j) {
            count[i][j] = 1;
        }
    }
    int x_simi = 0;
    int y_simi = 0;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j]==arr[i][j+1]||arr[i][j]==arr[i+1][j]){
                x_simi = 0;
                y_simi = 0;
                for (int k = j+1; k < m; ++k) {
                    if (arr[i][j]==arr[i][k]) x_simi++;
                    else break;
                }
                for (int k = i+1; k < n; ++k) {
                    if (arr[i][j]==arr[k][j]) y_simi++;
                    else break;
                }
                if (x_simi>1){
                    for (int k = 0; k < x_simi+1; ++k) {
                        count[i][j+k] = 0;
                    }
                }
                if(y_simi>1){
                    for (int k = 0; k < y_simi+1; ++k) {
                        count[i+k][j] = 0;
                    }
                }
            }

        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (count[i][j]) cout<<arr[i][j];
            else cout<<0;
            if (j<m-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

/*int main(){
    findSimilar();
    return 0;
}*/

