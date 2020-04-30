#include <bits/stdc++.h>
#define N 2050
#define LL long long
using namespace std;
LL t1[N][N], t2[N][N], t3[N][N], t4[N][N];
int n, m;
void Up(int x, int y, int val) {
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= m; j += j & -j) {
            t1[i][j] += (LL)val;
            t2[i][j] += (LL)val * x;
            t3[i][j] += (LL)val * y;
            t4[i][j] += (LL)val * x * y;
        }
}
LL Q(int x, int y) {
    LL ans = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j) {
            ans += (LL)t1[i][j] * (x + 1) * (y + 1);
            ans -= (LL)t2[i][j] * (y + 1);
            ans -= (LL)t3[i][j] * (x + 1);
            ans += (LL)t4[i][j];
        }
    return ans;
}
int main() {
    int pp, qq;
    scanf("%d%d%d%d", &n, &m, &pp, &qq);
    int op, x1, y1, x2, y2;
    for (int i = 0; i < pp; i++) {
        scanf("%d%d%d%d", &op, &x1, &y1, &x2, &y2);
        int val = 1;
        Up(x1, y1, val);
        Up(x1, y2 + 1, -val);
        Up(x2 + 1, y1, -val);
        Up(x2 + 1, y2 + 1, val);
    }
    for (int i = 0; i < qq; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    }
    // while(~scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2)){
    //     if(op==1){
    //         int val; scanf("%d",&val);
    //         Up(x1,y1,val); Up(x1,y2+1,-val);
    //         Up(x2+1,y1,-val); Up(x2+1,y2+1,val);
    //     }
    //     if(op==2){
    //         LL ans = Q(x2,y2) - Q(x2,y1-1) - Q(x1-1,y2) + Q(x1-1,y1-1);
    //         printf("%lld",ans);
    //     }
    // }
    return 0;
}