#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define \n endl
const int N = 1e6 + 100;
vector<vector<int>> e;
vector<int> deg;
int n;
int main()
{
    //ios::sync_with_stdio(false);
    ///cin.tie(nullptr);
    cin >> n;
    e.resize(n);
    deg.resize(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++deg[u], ++deg[v];
    }
    int res = n;
    while (res > 1)
    {
        int u, v;
        for (u = 0; deg[u] != 1; ++u)
        {
            for (v = u + 1; deg[v] != 1; ++v)
            {
                cout << "? " << u + 1 << ' ' << v + 1 << '\n';
            }
        }
        int w;
        cin >> w;
        w--;
        if (w == u || w == v)
        {
            cout << "! " << w + 1 << endl;
            return 0;
        }
        deg[u] = deg[v] = -1;
        for (auto x : e[u])
            --deg[x];
        for (auto x : e[v])
            --deg[x];
        res -= 2;
    }
    int u;
    for (u = 0; deg[u] != 0; u++)
        ;
    cout << "! " << u + 1 << endl;
    return 0;
}