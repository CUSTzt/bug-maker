#include <iostream>
using namespace std;

const int N = 7;
// p为矩阵链，p[0],p[1]代表第一个矩阵的行数和列数，p[1],p[2]代表第二个矩阵的行数和列数......length为p的长度
//所以如果有六个矩阵，length=7，m为存储最优结果的二维矩阵，s为存储选择最优结果路线的
//二维矩阵
void MatrixChainOrder(int *p, int dp[N][N], int s[N][N], int length) {
    int n = length - 1;
    int  i, j, k, q = 0;
    // dp[i][i]只有一个矩阵，所以相乘次数为0，即m[i][i]=0;
    for (i = 1; i < length; i++) {
        dp[i][i] = 0;
    }
    // l表示矩阵链的长度
    // len=2时，计算 dp[i,i+1],i=1,2,...,n-1 (长度l=2的链的最小代价)
    for (int len = 2; len <= n; len++) {
        for (i = 1; i <= n - len + 1; i++) {
            j = i + len - 1;  //以i为起始位置，j为长度为l的链的末位，
            dp[i][j] = 0x7fffffff;
            // k从i到j-1,以k为位置划分
            for (k = i; k <= j - 1; k++) {
                q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i <= j)
                printf("%-10d", dp[i][j]);
            else
                printf("          ");
        }
        cout << endl;
    }
    cout << dp[1][N - 1] << endl;
}
void PrintAnswer(int s[N][N], int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        PrintAnswer(s, i, s[i][j]);
        PrintAnswer(s, s[i][j] + 1, j);
        cout << ")";
    }
}
int main() {
    int p[N] = {30, 35, 15, 5, 10, 20, 25};
    int dp[N][N] = {0}, s[N][N] = {0};
    // cout << "sssss" << dp[1][1] << endl;
    MatrixChainOrder(p, dp, s, N);
    PrintAnswer(s, 1, N - 1);
    return 0;
}