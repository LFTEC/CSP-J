#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100
using namespace std;

int T, N, M;

int data[MAXN][MAXN];


bool calc(int day, int& remain, int& earned)
{
    if (remain <= 0) return false;

    int profit = 0, mem = 0, r0 = 0;
    for (int i = 0; i < N; i++)
    {
        if (data[day][i] < remain && data[day][i] < data[day + 1][i])
        {
            auto res = (remain / data[day][i]) * (data[day + 1][i] - data[day][i]);            
            auto r = (remain % data[day][i]);

            calc(day, r, res);
            if (res + remain > profit)
            {
                profit = res + remain;
                r0 = r;
                mem = i;
            }
        }
    }

    if (profit)
    {        
        earned += profit - remain;
        remain = r0;
    }
    else
        return false;
}

int main()
{
    if(scanf("%d%d%d", &T, &N, &M)!= 3 ) return -1;

    memset(data, 0, sizeof(data));

    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    int money = M, earned = 0;
    for (int i = 0; i < T - 1; i++)
    {
        auto remain = money;
        earned = 0;

        calc(i, remain, earned);
        money += earned;
    }

    printf("%d", money);
    return 0;
}