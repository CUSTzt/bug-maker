#include <cstdio>
#include <iostream>

using namespace std;
const int N = 4;
pair<int, int> mat[10];  // 记录矩阵的大小

int dp[10][10], p[10]={0, 10, 20, 25, 15, 5};
//存放矩阵链计算的最优值，d[i][j]为第i个矩阵到第j个矩阵的矩阵链的最优值
int separate[10][10];  //最佳分开位置
int main() {}