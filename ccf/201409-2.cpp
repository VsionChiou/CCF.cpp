//
// Created by Vsion Chiou on 2021/1/30.
//

#include "201409-2.h"

#include <iostream>
#include <cstring>

using namespace std;

void area() {
    int n;
    cin>>n;
    int arr[n][4];
    int area=0;
    bool flag[101][101];
    memset(flag,false,sizeof(flag));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin>>arr[i][j];
        }
        area += (arr[i][3]-arr[i][1])*(arr[i][2]-arr[i][0]);
        for (int j = arr[i][0]; j < arr[i][2]; ++j) {
            for (int k = arr[i][1]; k < arr[i][3]; ++k) {
                if (flag[j][k]) area -= 1;
                else flag[j][k] = true;
            }

        }

    }
    cout<<area;
}




/*


#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][4];
    int area=0;
    bool flag[101][101];
    memset(flag,false,sizeof(flag));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin>>arr[i][j];
        }
        area += (arr[i][3]-arr[i][1])*(arr[i][2]-arr[i][0]);
        for (int j = arr[i][0]; j < arr[i][2]; ++j) {
            for (int k = arr[i][1]; k < arr[i][3]; ++k) {
                if (flag[j][k]) area -= 1;
                else flag[j][k] = true;
            }

        }

    }
    cout<<area;
    return 0;
}

*/
