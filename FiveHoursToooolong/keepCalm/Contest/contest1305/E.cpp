// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e7 + 100;
int n, m, a[N], sum[N];
bool check(int n, int m)
{
    ll s = 0;
    for (int i = n - 2; i >= 1; i -= 2)
    {
        s += i;
    }
    if (s < m)
        return true;
    return false;
}
int main()
{
    cin >> n >> m;
    if (check(n, m))
    {
        return cout << -1, 0;
    }
    a[1] = 1;
    int last = 0;
    for (int i = 2; i <= n; i++)
    {
        int t = a[i - 1] + 1;
        while (m < sum[t])
            t++;
        a[i] = t;
        m -= sum[t];
        for (int j = 1; j < i; j++)
            if (a[j] + a[i] <= 30000000)
                sum[a[j] + a[i]]++;
    }
    if (m != 0)
        return cout << -1, 0;
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}