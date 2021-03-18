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
    string current, last, temp;
    vector<string> path;
    cin>>n;
    cin>>last;
    cin.get();
    for (int i = 0; i < n; ++i) {
        getline(cin, temp);
        if (temp[0]!='/') temp = last + "/"+ temp;
        for (char &j:temp) if (j=='/') j = ' ';
        stringstream re(temp);
        while(re>>current){
            if (current==".."&&!path.empty()) path.pop_back();
            else if (current==".") continue;
            else path.push_back(current);
        }
        if (path.empty()) cout<<"/";
        for (vector<string>::iterator it = path.begin(); it!=path.end(); it++) {
            cout<<"/"<<(*it);
        }
        cout<<endl;
        path.clear();
    }

    return 0;
}
/*int main()
{
    path_resolve();
    return 0;
}*/

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

