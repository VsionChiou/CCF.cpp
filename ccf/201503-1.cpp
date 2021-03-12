//
// Created by Vsion Chiou on 2021/3/2.
//

#include "201503-1.h"

#include <iostream>

using namespace std;
int rotation(){
    int n,m;

    cin>>n>>m;
    if (n<1||n>1000||m<1||m>1000) return 0;
    int photo[1001][1001];
    int newphoto[1001][1001];
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; ++j) {
            cin>>photo[i][j];
            if (photo[i][j]<0||photo[i][j]>1000) return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            newphoto[m-i-1][j]=photo[j][i];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<newphoto[i][j];
            if (j+1!=n){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;

}
/*

int main(){
    rotation();
    return 0;
}
*/

//总结：二维数组定义时，直接将行列定为超出许可范围即可得满分，否则系统评测结果会出错。
