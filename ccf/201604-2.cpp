//
// Created by Vsion Chiou on 2021/3/10.
//

#include "201604-2.h"

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int RassianRectangle(){
    vector<vector<int>> blank(15);
    vector<pair<int, int>> data;
    int x;
    int left = 0;
    int i,j;
    bool met;
    int height;
    for (i = 0; i < 15; ++i) {
        for (j = 0; j < 10; ++j) {
            cin>>x;
            blank[i].push_back(x);
        }
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            cin>>x;
            if (x) {
                data.emplace_back(i, j);
                height = i;
            }
        }
    }
    cin>>left;
//    坐标重定向
    for (i = 0; i < 4; i++) {
        data[i].second+=left-1;
    }
    for (i = 0; i+height < 15; i++) {
        met = false;
        for (j = 0; j < 4; j++) {
            met |= blank[i+data[j].first][data[j].second];

        }
        if (met) break;

    }
    i--;
    for (j = 0; j < 4; j++) {
        blank[i+data[j].first][data[j].second] = 1;
    }

    for (i = 0; i < 15; ++i) {
        for (j = 0; j < 10; ++j) {
            cout<<blank[i][j];
            if (j!=9){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
int main(){
    RassianRectangle();
    return 0;
}*/

/*

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //FILE *stream;
    //freopen_s(&stream, "data.txt", "r", stdin);

    vector<vector<int>> map(15); //存储15*10的地图
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int temp;
            cin >> temp;
            map[i].push_back(temp);
        }
    }
    vector<pair<int, int>> coor; //存储方块在4*4板块中的坐标
    int deep; //记录方块在板块中的最深坐标用来控制循环
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int temp;
            cin >> temp;
            if(temp) { coor.push_back({i, j}); deep = i; }
        }
    }
    int x, y; //检验地图中的坐标
    cin >> y;
    y--; //由于输入的坐标是从1开始故需要自减
    for(x = 0; x + deep < 15; x++)
    {
        int check = 0;
        for(int i = 0; i < 4; i++)
            check |= map[x + coor[i].first][y + coor[i].second];
        if(check) break; //check非零说明已经发生了碰撞，故退出循环
    }
    x--; //x恢复到碰撞前的坐标
    for(int i = 0; i < 4; i++) //由坐标修改地图
        map[x + coor[i].first][y + coor[i].second] = 1;
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 10; j++)
            cout << map[i][j] << ' ';
        cout << endl;
    }

    //fclose(stream);

    return 0;
}

*/
