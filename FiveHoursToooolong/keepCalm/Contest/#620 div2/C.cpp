#include <bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
int l[maxn], r[maxn], t[maxn];
int dp[110][2];
int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		memset(dp, 0, sizeof dp);
		int fl = 1;
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			cin >> t[i] >> l[i] >> r[i];
		}
		t[n + 1] = t[n], l[n + 1] = l[n], r[n + 1] = r[n];
		int nowl = m, nowr = m;
		for (int i = 1; i <= n + 1; i++)
		{
			nowl -= (t[i] - t[i - 1]);
			nowr += (t[i] - t[i - 1]);
			if (nowl > r[i] || nowr < l[i])
				fl = 0;
			if (nowr <= r[i] && nowl >= l[i])
				continue;
			if (nowr >= r[i] && l[i] >= nowl)
			{
				nowl = l[i];
				nowr = r[i];
				continue;
			}
			if (nowl >= l[i] && nowl <= r[i] && r[i] <= nowr)
			{
				nowr = r[i];
				continue;
			}
			if (nowl <= l[i] && nowr >= l[i] && r[i] >= nowr)
			{
				nowl = l[i];
				continue;
			}
		}
		cout << (fl ? "YES" : "NO") << endl;
	}
}