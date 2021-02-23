//
// Created by Vsion Chiou on 2021/1/27.
//

#include "201403-3.h"

#include <iostream>
#include <map>

using namespace std;


void cmd(){
    string cmd;
    map<char, int> comd;
    map<string, string> ans;
    cin>>cmd;
    for (int i = 0; i < cmd.length(); ++i) {
        if (i<cmd.length()-1&&cmd[i+1]==':'){
            comd[cmd[i]] = 2;
        }
        else if(cmd[i]!=':'){
            comd[cmd[i]] = 1;
        }
    }

    int n;
    int flag = 0;

    cin>>n;
    string str;
    string final[n+1];
    for (int i = 0; i <= n; ++i) {
        getline(cin, str);
        int nflag=0;
        int sp1, sp2;
        string cm,last_cm;
        while ((sp1 = str.find(' '))!=-1){
            str[sp1] = '0';
            sp2 = str.find(' ');
            if(sp2==-1) sp2 = str.length();
            cm = str.substr(sp1+1, sp2-sp1-1);
            if (cm[0]=='-'&&flag!=2){
                if(comd[cm[1]]==1){
                    last_cm = cm;
                    ans[cm]='#';
                } else if (comd[cm[1]]==2){
                    last_cm = cm;
                    flag = 2;
                }else break;
            }
            else{
                if (flag==2){
                    ans[last_cm]=cm;
                    flag = 0;
                }else break;
            }
        }
        map<string, string>::iterator an;
        for (an=ans.begin();an!=ans.end();an++) {
            if (an->second=="#") {
                final[i]+=" ";
                final[i]+=an->first;
            }
            else {
                final[i]+=" ";
                final[i]+=an->first;
                final[i]+=" ";
                final[i]+=an->second;
            }

        }
        ans.clear();
    }
    for (int i = 1; i <= n; ++i) {
        cout<<"Case "<<i<<":"<<final[i]<<endl;
    }


 }


/*


#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    string cmd;
    map<char, int> comd;
    map<string, string> ans;
    cin>>cmd;
    for (int i = 0; i < cmd.length(); ++i) {
        if (i<cmd.length()-1&&cmd[i+1]==':'){
            comd[cmd[i]] = 2;
        }
        else if(cmd[i]!=':'){
            comd[cmd[i]] = 1;
        }
    }

    int n;
    int flag = 0;

    cin>>n;
    string str;
    string final[n+1];
    for (int i = 0; i <= n; ++i) {
        getline(cin, str);
        int nflag=0;
        int sp1, sp2;
        string cm,last_cm;
        while ((sp1 = str.find(' '))!=-1){
            str[sp1] = '0';
            sp2 = str.find(' ');
            if(sp2==-1) sp2 = str.length();
            cm = str.substr(sp1+1, sp2-sp1-1);
            if (cm[0]=='-'&&flag!=2){
                if(comd[cm[1]]==1){
                    last_cm = cm;
                    ans[cm]='#';
                } else if (comd[cm[1]]==2){
                    last_cm = cm;
                    flag = 2;
                }else break;
            }
            else{
                if (flag==2){
                    ans[last_cm]=cm;
                    flag = 0;
                }else break;
            }
        }
        map<string, string>::iterator an;
        for (an=ans.begin();an!=ans.end();an++) {
            if (an->second=="#") {
                final[i]+=" ";
                final[i]+=an->first;
            }
            else {
                final[i]+=" ";
                final[i]+=an->first;
                final[i]+=" ";
                final[i]+=an->second;
            }

        }
        ans.clear();
    }
    for (int i = 1; i <= n; ++i) {
        cout<<"Case "<<i<<":"<<final[i]<<endl;
    }


    return 0;
}
*/
