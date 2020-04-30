// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e3 + 100;
char str[N][N];
int vis[N][N], n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
//char tmp[] = {'U', 'D', 'L', 'R'};
//char tmpp[] = {'D', 'U', 'R', 'L'};
char tmp[] = {'L', 'R', 'U', 'D'};
char tmpp[] = {'D', 'U', 'R', 'U'};
int cnt, nowx, nowy;
pair<int, int> a[N][N];
bool check(int x, int y)
{
    if (x >= 1 && x <= n && y <= n && y >= 1 && !vis[x][y])
        return true;
    return false;
}
void bfs()
{
    queue<pair<int, int>> q;
    while (q.size())
        q.pop();
    str[nowx][nowy] = 'X';
    q.push({nowx, nowy});
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int x = pr.ff, y = pr.ss;
        if (vis[x][y])
            continue;
        cnt++;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny))
            {
                if (a[nx][ny].ff == nowx && a[nx][ny].ss == nowy)
                {
                    q.push({nx, ny});
                    str[nx][ny] = tmpp[i];
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j].ff >> a[i][j].ss;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j].ff == -1 && a[i][j].ss == -1)
            {
                vis[i][j] = 1;
                cnt++;
                int fl = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 1 && nx <= n && ny <= n && ny >= 1 && a[nx][ny].ff == -1 && a[nx][ny].ss == -1)
                    {
                        fl = 1;
                        str[i][j] = tmp[k];
                        break;
                    }
                }
                if (!fl)
                {
                    return cout << "INVALID", 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vis[i][j] && a[i][j].ff == i && a[i][j].ss == j)
            {
                nowx = i, nowy = j;
                bfs();
            }
        }
    }
    if (cnt == n * n)
    {
        cout << "VALID\n";
        for (int i = 1; i <= n; i++)
        {
            cout << str[i] + 1 << endl;
        }
    }
    else
        return cout << "INVALID", 0;
}