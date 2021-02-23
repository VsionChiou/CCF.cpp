//
// Created by Vsion Chiou on 2021/1/30.
//

#include "201409-1.h"

#include <iostream>

using namespace std;


void neighbor(){
    int n;
    int count=0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];

    }
    for(int i=0;i<n;i++){
        for (int j = i; j < n; ++j) {
            if (arr[i]-arr[j]==1||arr[i]-arr[j]==-1){
                count++;
            }

        }
    }
    cout<<count;
}



/*


#include <iostream>

using namespace std;


int main(){
    int n;
    int count=0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];

    }
    for(int i=0;i<n;i++){
        for (int j = i; j < n; ++j) {
            if (arr[i]-arr[j]==1||arr[i]-arr[j]==-1){
                count++;
            }

        }
    }
    cout<<count;
    return 0;
}
*/
