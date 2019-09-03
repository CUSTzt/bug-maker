/*#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n, m;
int g[N][N];
int f[N * 2][N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            scanf("%d", &g[i][j]);

    for (int k = 2; k <= n + m; k ++ )
        for (int i = max(1, k - m); i <= n && i < k; i ++ )
            for (int j = max(1, k - m); j <= n && j < k; j ++ )
                for (int a = 0; a <= 1; a ++ )
                    for (int b = 0; b <= 1; b ++ )
                    {
                        int t = g[i][k - i];
                        if (i != j) t += g[j][k - j];
                        f[k][i][j] = max(f[k][i][j], f[k - 1][i - a][j - b] + t);
                    }

    printf("%d\n", f[n + m][n][n]);

    return 0;
}
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[110][110],f[220][110][110],n,m;
void Move(int i,int x_1,int x_2,int nx1,int nx2,int y_1,int y_2)
{
    if(nx1==nx2)f[i+1][nx1][nx2]=max(f[i+1][nx1][nx2],f[i][x_1][x_2]+a[nx1][y_1]);
    else f[i+1][nx1][nx2]=max(f[i+1][nx1][nx2],f[i][x_1][x_2]+a[nx1][y_1]+a[nx2][y_2]);
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    f[0][1][1]=a[1][1];
    for(int i=0;i<m+n-2;i++)
        for(int x_1=1;x_1<=min(i+1,m);x_1++)
            for(int x_2=1;x_2<=min(i+1,m);x_2++)
            {
                int y_1=i+2-x_1,y_2=i+2-x_2;
                Move(i,x_1,x_2,x_1,x_2,y_1+1,y_2+1);
                Move(i,x_1,x_2,x_1+1,x_2,y_1,y_2+1);
                Move(i,x_1,x_2,x_1,x_2+1,y_1+1,y_2);
                Move(i,x_1,x_2,x_1+1,x_2+1,y_1,y_2);
            }
    printf("%d\n",f[m+n-2][m][m]);
    return 0;
}

