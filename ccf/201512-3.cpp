//
// Created by Vsion Chiou on 2021/3/8.
//

#include "201512-3.h"

#include <iostream>

using namespace std;


void full(string **b, int m, int n, int x, int y, char &c){
    if (x>=0&&x<n&&y>=0&&y<m){
        if ((*b)[x][y]!='-'&&(*b)[x][y]!='|'&&(*b)[x][y]!='+'&&(*b)[x][y]!=c){
            (*b)[x][y] = c;
            full(b, m, n, x+1, y, c);
            full(b, m, n, x-1, y, c);
            full(b, m, n, x, y+1, c);
            full(b, m, n, x, y-1, c);
        }else return;
    }
}

int paint(){
    int  m,n,q;
    string *blank;
    int opt[6] = {-1};
    char character;
    cin>>m>>n>>q;
    blank = new string[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            blank[i] += '.';
        }
    }

    int mod;
    int start;
    int end;
    for (int i = 0; i < q; ++i) {
        cin>>mod;
        if (mod){
            for (int j = 0; j < 2; ++j) {
                cin>>opt[j];
            }
            cin>>character;cin.get();
            int x = n-opt[1]-1;
            int y = opt[0];
            full(&blank, m, n, x, y, character);
        }else if (!mod){
            for (int j = 0; j < 4; ++j) {
                cin>>opt[j];
            }
            if (opt[0]-opt[2]){
                if (opt[0]-opt[2]>0){
                    start = opt[2];
                    end = opt[0];
                }else{
                    start = opt[0];
                    end = opt[2];
                }
                for (int j = start; j <= end; ++j) {
                    if (blank[n-opt[1]-1][j]=='|'||blank[n-opt[1]-1][j]=='+') blank[n-opt[1]-1][j] = '+';
                    else blank[n-opt[1]-1][j] = '-';

                }
            }else{
                if (opt[1]-opt[3]>0){
                    start = n-opt[1]-1;
                    end = n-opt[3]-1;
                }else{
                    start = n-opt[3]-1;
                    end = n-opt[1]-1;
                }
                for (int j = start; j <= end; j++) {
                    if (blank[j][opt[0]]=='-'||blank[j][opt[0]]=='+') blank[j][opt[0]] = '+';
                    else blank[j][opt[0]] = '|';

                }
            }

        }
        for (int j = 0; j < 6; ++j) {
            opt[j] = -1;
        }
        start = -1;
        end = -1;
    }
    for (int i = 0; i < n; ++i) {
            cout<<blank[i]<<endl;
    }
    return 0;
}
/*

int main(){
//    paint();
    string str[8];
    str[0][0] = 'e';
    cout<<str[0][1];
    return 0;
}
*/

/*
//大佬A
#include<bits/stdc++.h>
using namespace std;
char s[105][105];
int m,n,q;
void TianChong(int x,int y,char ch){
    //cout<<m<<" "<<n<<endl;
    if(x>=0&&x<m&&y>=0&&y<n){
        //cout<<(s[x][y]!='-'&&s[x][y]!='|'&&s[x][y]!='+')<<endl;
        if(s[x][y]!='-'&&s[x][y]!='|'&&s[x][y]!='+'&&s[x][y]!=ch){
            s[x][y]=ch;
            TianChong(x+1,y,ch);
            TianChong(x-1,y,ch);
            TianChong(x,y+1,ch);
            TianChong(x,y-1,ch);
        }
    }else{
        return;
    }
}
int main(){
    cin>>m>>n>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            s[i][j]='.';
    }
    for(int i=0;i<q;i++){
        int flag;
        cin>>flag;
        if(flag==0){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2&&y1!=y2){
                if(y1>y2){
                    int temp_i=y1;
                    y1=y2;
                    y2=temp_i;
                }
                for(int j=y1;j<=y2;j++){
                    if(s[x1][j]!='-'&&s[x1][j]!='+')
                        s[x1][j]='|';
                    else
                        s[x1][j]='+';
                }
            }else{
                if(x1>x2){
                    int temp_i=x1;
                    x1=x2;
                    x2=temp_i;
                }
                for(int j=x1;j<=x2;j++){
                    if(s[j][y1]!='|'&&s[j][y1]!='+')
                        s[j][y1]='-';
                    else
                        s[j][y1]='+';
                }
            }
        }else{
            int x,y;
            char ch;
            cin>>x>>y>>ch;
            TianChong(x,y,ch);
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++)
            cout<<s[j][i];
        cout<<endl;
    }
    return 0;
}
*/



/*
//大佬B
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Insert Character
void fillplant(string **plant, int m, int n,int x,int y,char temp)
{
    //Out Of Memory
    if (y < 0 || y >= n)
        return;
    if (x < 0 || x >= m)
        return;
    if ((*plant)[y][x] == '-' || (*plant)[y][x] == '|' || (*plant)[y][x] == '+' || (*plant)[y][x] == temp)
    {
        return;
    }
    (*plant)[y][x] = temp;
    //Insert Around
    fillplant(plant, m, n, x - 1, y, temp);
    fillplant(plant, m, n, x + 1, y, temp);
    fillplant(plant, m, n, x, y - 1, temp);
    fillplant(plant, m, n, x, y + 1, temp);
}

int main() {
    int m, n, q;
    int mod;
    int x1, y1, x2, y2;
    char temp;
    string *plant;
    cin >> m >> n >> q; getchar();
    plant = new string [n];
    //Init '.'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            plant[i] = plant[i] + '.';
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> mod;
        if (!mod)
        {
            cin >> x1 >> y1 >> x2 >> y2; getchar();
            if (x1 == x2)
            {
                //y1!=y2
                for (int i = min(y1, y2); i <= max(y1, y2); i++)
                {
                    if (plant[i][x1] != '-' && plant[i][x1] != '+')
                        plant[i][x1] = '|';
                    else
                        plant[i][x1] = '+';
                }
            }
            else if (y1 == y2)
            {
                //x1!=x2
                for (int i = min(x1, x2); i <= max(x1, x2); i++)
                {
                    if (plant[y1][i] != '|' && plant[y1][i] != '+')
                        plant[y1][i] = '-';
                    else
                        plant[y1][i] = '+';
                }
            }
        }
        else
        {
            cin >> x1 >> y1 >> temp; getchar();
            fillplant(&plant, m, n, x1, y1, temp);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {	//Reverse output
        cout << plant[i] << endl;
    }
    //getchar();
    return 0;
}
*/

