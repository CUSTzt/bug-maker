#include <bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int, int>
#define ULL unsigned long long
using namespace std;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1), eps = 1e-10;
const int maxn = 1 << 17;
const int N = 5e3 + 10, M = N * 40;
int n, k, q, x[maxn], sum, vis[maxn];
int ans;
void dfs(int cnt, int now)
{
    if (cnt == k && sum == q)
    {
        ans++;
    }
    for (int i = now; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1, sum += x[i];
            dfs(cnt + 1, i + 1);
            vis[i] = 0;
            sum -= x[i];
        }
    }
}
int main()
{
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << ans << endl;
}
/*
1
6 7
0 0 0 0 0 0
0 1 0 3 0 1
2 9 1 2 1 2
8 7 1 3 4 3
1 0 2 2 7 7
0 1 0 0 1 0
0 0 0 0 0 0
*/