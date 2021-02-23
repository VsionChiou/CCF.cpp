//
// Created by Vsion Chiou on 2021/1/21.
//

#include <iostream>
#include "typeinfo.h"


using namespace std;

string isbn(){
    string isbn;
    cin>>isbn;

    int arr[9];
    int a = 0;
    int sum = 0;
    for (int i = 0; i < 11; ++i) {
        if(int(isbn[i])-48>=0)
            arr[a++] = int(isbn[i])-48;
    }

    for (int i = 0;i<9;i++) {
        sum += arr[i]*(i+1);
    }
    if (sum%11 != 10){
        if(sum%11 == int(isbn[12])-48) cout<<"Right";
        else{
            for (int i = 0; i < 12; ++i) {
                cout<<isbn[i];
            }
            cout<<sum%11;
        }
    }else{
        if (isbn[12] == 'X') cout<< "Right";
        else{
            for (int i = 0; i < 12; ++i) {
                cout<<isbn[i];
            }
            cout<<'X';
        }
    }

    return isbn;
}
/*


#include <iostream>
#include <string>

using namespace std;

int main(){
    string isbn;
    cin>>isbn;

    int arr[9];
    int a = 0;
    int sum = 0;
    for (int i = 0; i < 11; ++i) {
        if(int(isbn[i])-48>=0)
            arr[a++] = int(isbn[i])-48;
    }

    for (int i = 0;i<9;i++) {
        sum += arr[i]*(i+1);
    }
    if (sum%11 != 10){
        if(sum%11 == int(isbn[12])-48) cout<<"Right";
        else{
            for (int i = 0; i < 12; ++i) {
                cout<<isbn[i];
            }
            cout<<sum%11;
        }
    }else{
        if (isbn[12] == 'X') cout<< "Right";
        else{
            for (int i = 0; i < 12; ++i) {
                cout<<isbn[i];
            }
            cout<<'X';
        }
    }
    return 0;
}
*/
