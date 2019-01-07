//
//  main.cpp
//  Saolei
//
//  Created by 曹广 on 2019/1/7.
//  Copyright © 2019年 曹广. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int disbomb[10][10];
int a[10][10] = {0};
int count_b = 10;

void makebomb()
{
    srand((int)time(0));
    while (count_b > 0)
    {
        int x=(rand()%(9-1+1))+1;
        int y=(rand()%(9-1+1))+1;
        if (disbomb[x][y]!= 1)
        {
            disbomb[x][y] = 1;
            count_b --;
        }
    }
    int i,j;
    for (i = 0; i<10; i++)
    {
        for (j = 0; j<10;j++)
        {
            a[i][j] = -1;
        }
    }
}

void print_count()
{
    int i,j;
    for (i = 0; i<10; i++)
    {
        for (j = 0; j<10;j++)
        {
            if (a[i][j] == -1)
                cout<<"* ";
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void game_over()
{
    int i,j;
    for (i = 0; i<10; i++)
    {
        for (j = 0; j<10;j++)
        {
            cout<<disbomb[i][j]<<" ";
        }
        cout<<endl;
    }
}

int count_bomb(int X,int Y)
{
    X --;
    Y --;
    int num = 0;
    if (disbomb[X][Y] == 1)
        return 0;
    else
    {
        if (X-1 >= 0 and disbomb[X-1][Y])
            num ++;
        if (X +1 <= 9 and disbomb[X+1][Y])
            num ++;
        if (X-1>=0 and Y-1 >=0 and disbomb[X-1][Y-1])
            num ++;
        if (Y-1>=0 and disbomb[X][Y-1])
            num ++;
        if (X+1<=9 and Y-1>=0 and disbomb[X+1][Y-1])
            num ++;
        if (X-1>=0 and Y+1<=9 and disbomb[X-1][Y+1])
            num ++;
        if (Y+1<=9 and disbomb[X][Y+1])
            num ++;
        if (X+1<=9 and Y+1<=9 and disbomb[X+1][Y+1])
            num ++;
        a[X][Y] = num;
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    cout<< "Welcome to SaoLei game!"<<endl;
    makebomb();
    int X, Y;
    int history = 0;

    // start playing
    print_count();
    while (1)
    {
        if (history < 10*10-10)
        {
            cout<<"Please enter X and Y: "<<endl;
            cin>>X;
            cin>>Y;
            if (count_bomb(X,Y) == 0)
            {
                cout<<"Game over"<<endl;
                game_over();
                break;
            }
            else
            {
                cout<<"Good step!"<<endl;
                print_count();
            }
            history ++;
        }
        else
            cout<<"Congratulations! You win!"<<endl;
    }
    
    return 0;
}
