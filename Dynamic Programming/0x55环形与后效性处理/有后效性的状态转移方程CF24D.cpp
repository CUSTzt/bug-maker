#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
using namespace std;
/*
-------------Broken robot------codeforces 24D----------
题意：求机器人从起点走到最后一行任意位置所需行动次数的数学期望值
解法：期望dp+高斯消元（环形与后效性处理）
 
状态转移方程式:
1、机器人在第一列时不能再向左走
F[i, 1] = 1 / 3 * (F[i, 1] + F[i, 2] + F[i + 1, 1]) + 1;
2、机器人在第M列时不能再向左走
F[i, M] = 1 / 3 * (F[i, M] + F[i, M - 1] + F[i + 1, M]) + 1;
3、当2 <= j <= M - 1时
F[i, j] = 1 / 4 * (F[i, j] + F[i, j - 1] + F[i, j + 1] + F[i + 1, j]) + 1;
 
初值：任意j属于[1,M],F[N,j]=0,目标：F[x,y]
 
----化简可得------>f[i][m]=(3+A+f[i+1][m])/(2-B);
--------很多数学期望dp都会采取倒推的方式执行-----------
*/
const int maxn = 1010;
double f[maxn][maxn] = { 0 }, a[maxn] = { 0 }, b[maxn] = { 0 };
int main()
{
	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	n = n - x + 1;
	if (m == 1)
		f[1][y] = (n - 1) * 2;
	else
	{
		for (int i = n - 1; i; i--)
		{
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			a[1] = (3 + f[i + 1][1]) / 2.0;
			b[1] = 1.0 / 2;
			for (int j = 2; j < m; j++)
			{
				double c = f[i + 1][j];
				a[j] = (4.0 + a[j - 1] + c) / (3 - b[j - 1]);
				b[j] = 1.0 / (3 - b[j - 1]);
			}
			f[i][m] = (3.0 + a[m - 1] + f[i + 1][m]) / (2.0 - b[m - 1]);
			for (int j = m - 1; j; j--)
			{
				f[i][j] = a[j] + b[j] * f[i][j + 1];
			}
		}
	}
	printf("%.10lf\n", f[1][y]);
}