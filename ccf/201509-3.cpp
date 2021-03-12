//
// Created by Vsion Chiou on 2021/3/4.
//

#include "201509-3.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;

int createTemplete(){
    int m,n;
    string content[101];
    string key;
    string value;
    map<string, string> varies;
    cin>>m>>n;
    cin.get();
    for (int i = 0; i < m; i++) {
        getline(cin,content[i]);
    }

    for (int i = 0; i < n; ++i) {
        cin >> key;
        getline(cin, value);
        varies.insert(pair<string, string>(key, value.substr(2, value.length()-3)));
    }


    for (int i = 0; i < m; ++i) {
        int first;
        int end;
        int k = 0;
        while (content[i].find("{{", k)!=-1&&content[i].find("}}", k)!=-1){

            string flag;
            key = "";
            first = content[i].find("{{", k);
            end = content[i].find("}}", k);
            if (first>=0&&end>=0){
                key = content[i].substr(first + 3, end - first - 4);
                content[i].replace(first, end-first+2,varies.count(key)?varies[key]:"");
                k = varies.count(key)?first+(int)varies[key].size():k;
            }
            else break;

        }


    }
    for (int i = 0; i < m; ++i) {
        cout<<content[i]<<endl;
    }

    return 0;
}

/*int main(){
    createTemplete();
    return 0;
}*/
/*

#include <vector>
#include "map"
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<string>text;
    string key,val;
    map<string,string>dict;
    int n,m;
    string str;
    cin>>n>>m;
    cin.get();///吃掉换行符
    for(int i=0; i<n; i++) {
        getline(cin,str);
        text.push_back(str);
    }
    for(int i=0; i<m; i++) {
        cin>>key;
        getline(cin,val);
        int lv = val.size();
        dict[key]=val.substr(2,val.size()-3);
    }
    ///替换字符串并输出
    for(int i=0; i<n; i++) {
        int pre=0,next;
        while(1) {
            ///string的find(s,pre)表示从下标为pre的位置查找字符串ｓ，若未找到返回-1
            if((pre=text[i].find("{{ ",pre))==-1) break;
            if((next=text[i].find(" }}",pre))==-1) break;///若找到一个pre,从pre后查找"}}"
            key=text[i].substr(pre+3,next-pre-3);///将{{     }}里的字符串key提出
            text[i].replace(pre,next-pre+3,dict.count(key)?dict[key]:"");///替换
            pre+=dict.count(key)?dict[key].size():0;///避免重复替换
        }
        cout<<text[i]<<endl;
    }
    return 0;
}
*/
