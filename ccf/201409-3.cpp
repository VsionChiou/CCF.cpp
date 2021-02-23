//
// Created by Vsion Chiou on 2021/1/31.
//

#include "201409-3.h"

#include <iostream>
#include <string>

using namespace std;

void str(){
    string str;
    int mode;
    int num;
    string arr[101];
    string content;
    int l = 0;
    cin>>str>>mode>>num;
    for (int i = 0; i < num; ++i) {
        cin>>content;
        for (int j = 0,k = 0; j < content.length()&&k<str.length(); ++j) {
            if (mode){
                if (content[j]==str[k]) k++;
                else k = 0;
            }else{
                if (content[j]>='a'&&content[j]<='z'){
                    if(str[k]>='a'&&str[k]<='z'){
                        if (str[k]==content[j]) k++;
                        else k=0;
                    }else{
                        if (str[k]==content[j]-32) k++;
                        else k = 0;
                    }
                }else{
                    if (str[k]>='a'&&str[k]<='z'){
                        if (str[k]-32==content[j]) k++;
                        else k = 0;
                    }else{
                        if (str[k]==content[j]) k++;
                        else k = 0;
                    }
                }
            }

            if (k==str.length()) arr[l++] = content;
        }
    }
    for (int i = 0; i < l; ++i) {
        cout<<arr[i]<<endl;
    }

}


/*

#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int mode;
    int num;
    string arr[101];
    string content;
    int l = 0;
    cin>>str>>mode>>num;
    for (int i = 0; i < num; ++i) {
        cin>>content;
        for (int j = 0,k = 0; j < content.length()&&k<str.length(); ++j) {
            if (mode){
                if (content[j]==str[k]) k++;
                else k = 0;
            }else{
                if (content[j]>='a'&&content[j]<='z'){
                    if(str[k]>='a'&&str[k]<='z'){
                        if (str[k]==content[j]) k++;
                        else k=0;
                    }else{
                        if (str[k]==content[j]-32) k++;
                        else k = 0;
                    }
                }else{
                    if (str[k]>='a'&&str[k]<='z'){
                        if (str[k]-32==content[j]) k++;
                        else k = 0;
                    }else{
                        if (str[k]==content[j]) k++;
                        else k = 0;
                    }
                }
            }

            if (k==str.length()) arr[l++] = content;
        }
    }
    for (int i = 0; i < l; ++i) {
        cout<<arr[i]<<endl;
    }

    return 0;

}
*/

