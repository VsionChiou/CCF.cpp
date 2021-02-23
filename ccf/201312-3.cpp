//
// Created by Vsion Chiou on 2021/1/23.
//

#include "201312-3.h"

#include <iostream>
#include <list>

using namespace std;

//solution 1

void biggestRectangle1(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int height, area, max = 0;
    for (int i = 0; i < n; ++i) {
        height = arr[i];
        for(int j = i; j<n; j++){
            if(height>arr[j]){
                height = arr[j];
                area = height* (j-i+1);
                if (max<area) max = area;
            }
        }
    }
    cout<<max;
}

void get_min(list<int> &total, int arr[], int low, int high){

    if (low> high) return;
    int min = arr[low];
    int pivot = low;
    for (int i = low; i <= high; ++i) {
        if (min>arr[i]){
            min = arr[i];
            pivot = i;
        }

    }
    total.push_back(min*(high-low+1));

    get_min(total, arr, low, pivot-1);
    get_min(total, arr, pivot+1, high);
}
void biggestRectangle(){
    int n;
    cin>>n;
    if (n<1||n>1000) return;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        if (x>=1&&x<=10000) arr[i] = x;
        else return;
    }


//    cout<<max;


}

/*


#include <iostream>
#include <list>
using namespace std;

void get_min(list<int> &total, int arr[], int low, int high){
    if (low> high) return;

    int min = arr[low];
    int pivot = low;
    for (int i = low; i <= high; ++i) {
        if (min>arr[i]){
            min = arr[i];
            pivot = i;
        }

    }
    total.push_back(min*(high-low+1));

    get_min(total, arr, low, pivot-1);
    get_min(total, arr, pivot+1, high);
}
int main(){
    int n;
    cin>>n;
    if (n<1||n>1000) return 0;
    int arr[1001];
    list<int> total;
    list<int>::iterator itor;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int low = 0, high = n-1;
    get_min(total, arr, low, high);
    itor=total.begin();
    int max = 0;
    while(itor!=total.end())
    {
        if (max<*itor) max = *itor;
        *itor++;
    }
    cout<<max;
    return 0;
}


*/

