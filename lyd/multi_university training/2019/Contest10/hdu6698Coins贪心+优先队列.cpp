/****************************************************************
# @Author:      miniLCT
# @DateTime: 2019年11月25日 星期一 15时31分21秒
# @Description: You build it. You run it
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include<bits/stdc++.h>

//给你一个n对物品，每对物品可以花费1元得到ai的价值，或者花费2元得到ai+bi的价值。求输出从1到2n 元时每次能获取的最高价值。
//a≥b ，肯定先取 a 再取 b ，直接贪心；
//a<b ，有一个显然的结论是，只有当奇数的时候才会出现一个 a 的情况，其余的一定是一组一起出现。而出现一个 a 的情况，一定是最大的几组和一个剩下的中的 a 或者最大的几组中去掉一个最小的 b ，两种情况取 max 。
//思路：显然不能dp  因为时间和空间消耗太大了
// n 从 n-2转移过来，一定是最优的 动态维护两类优先队列，每次贪心的取
using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
typedef long long ll;
typedef pair<int, int> pi;
const int maxn = 2e6 + 100;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
int a[maxn], b[maxn], c[maxn];
priority_queue<pi> se[2], sb[2];
int ans[maxn];
int mark[2][maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        rep(i, 0, 1)
        {
            while (!se[i].empty()) se[i].pop();
            while (!sb[i].empty()) sb[i].pop();
        }
        int N;
        scanf("%d", &N);
        rep(i, 0, 5 * N)
        mark[0][i] = mark[1][i] = ans[i] = a[i] = b[i] = 0;
        rep(i, 1, N)
        {
            scanf("%d %d", &a[i], &b[i]);
            c[i] = a[i] + b[i];
            se[0].push(make_pair(a[i], i));
            se[1].push(make_pair(a[i], i));
            sb[0].push(make_pair(c[i], i));
            sb[1].push(make_pair(c[i], i));
        }
        int f = 0, id, now1, now2;
        pi tmp;

        //1
        tmp = se[1].top();
        ans[1] = tmp.first;
        mark[1][tmp.second] = 1;
        se[1].push(make_pair(b[tmp.second], tmp.second + N));

        rep(i, 2, 2 * N)
        {
            now1 = 0, now2 = 0;
            pi s1, s2, s3;
            while (!se[f].empty() && mark[f][se[f].top().second] == 1) se[f].pop();
            while (!sb[f].empty() && mark[f][sb[f].top().second] == 1) sb[f].pop();
            if (!se[f].empty()) {
                s1 = se[f].top();
                se[f].pop();
                while (!se[f].empty() && mark[f][se[f].top().second] == 1) se[f].pop();
                if (se[f].empty()) {
                    se[f].push(s1);
                } else {
                    s2 = se[f].top();
                    se[f].pop();
                    now1 = (s1.first + s2.first);
                }
            }
            if (!sb[f].empty()) {
                s3 = sb[f].top();
                sb[f].pop();
                now2 = s3.first;
            }

            if (now1 >= now2) {
                ans[i] = ans[i - 2] + now1;
                int id1 = s1.second;
                int id2 = s2.second;
                mark[f][id1] = 1;
                mark[f][id2] = 1;
                se[f].push(make_pair(b[id1], id1 + N));
                se[f].push(make_pair(b[id2], id2 + N));
                if (now2) {
                    sb[f].push(s3);
                }
            } else {
                ans[i] = ans[i - 2] + now2;
                mark[f][s3.second] = 1;
                if (now1) {
                    se[f].push(s1);
                    se[f].push(s2);
                }
            }
            f = f ^ 1;
        }

        rep(i, 1, 2 * N - 1)
        printf("%d ", ans[i]);
        printf("%d\n", ans[2 * N]);
    }
}


/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/

