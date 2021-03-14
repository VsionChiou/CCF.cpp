//
// Created by Vsion Chiou on 2021/3/12.
//

#include "201604-3.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int path_resolve(){
    int n;
    int cur = 0;
    string current;
    string temp;
    vector<string> now, path;
    cin>>n;
    cin.get();
    getline(cin, current);
    for (char & i : current) {
        if (i=='/') i = ' ';
    }
    stringstream ss(current);
    while (ss>>temp){
        now.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        getline(cin, temp);
        if (temp[0]!='/'){
            path = now;
        }
        for (char &j:temp) {
            if (j=='/') j = ' ';
        }
        stringstream re(temp);
        while(re>>current){
            if (current.find("..")==0) {
                if (!path.empty()) {
                    path.pop_back();
                }else {
                    continue;
                }
            }else if (current.find('.')==0){
                continue;
            }else{
                path.push_back(current);
            }
        }
        for (vector<string>::iterator it = path.begin(); it!=path.end(); it++) {
            cout<<"/"<<(*it);
        }
        cout<<endl;
        path.clear();
    }

    return 0;
}

int main()
{
    path_resolve();
    return 0;
}

/*

int main()
{
    int n;
    cin >> n;
    string path, s, str;
    cin >> path;
    cin.get();  // 用getline时千万要注意吸收这个换行符
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        if (str == "") str = path;
        if (str[0] != '/') str = path + '/' + str;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == '/') str[j] = ' ';
        }
        vector<string> sta;
        stringstream ss(str);
        while (ss >> s) {
            if (s == ".") continue;
            else if (s == ".." && !sta.empty()) sta.pop_back();
            else if (s != "..") sta.push_back(s);
        }
        cout << '/';
        for (int j = 0; j < sta.size(); ++j) {
            if (j) cout << '/';
            cout << sta[j];
        }
        cout << endl;
    }
}

*/
