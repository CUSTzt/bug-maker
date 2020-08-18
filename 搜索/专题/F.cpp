// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 200;
struct node {
    int x, y, z, step;
    /* data */
} now;
int a, b, c, t;
int s[N][N][N], vis[N][N][N];
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dz[] = {0, 0, 1, -1, 0, 0};

void up() {
    cin >> a >> b >> c >> t;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                cin >> s[j][k][i];
                vis[i][j][k] = 0;
            }
        }
    }
    int ans = -1;
    now.x = 1, now.y = 1; now.z = 1, now.step = 0;
    queue<node> q;
    q.push(now);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        if (now.step > t) break;
        if (now.x == b && now.y == c && now.z == a) {
            // cout << "times == " << now.step << endl;
            if (now.step < t) ans = now.step;
            break;
        }
        node zz;
        for (int i = 0; i < 6; i++) {
            zz.x = now.x + dx[i], zz.y = now.y + dy[i], zz.z = now.z + dz[i];
            if (zz.x <= 0 || zz.x > b || zz.y <= 0 || zz.y > c || zz.z <= 0 || zz.z > a || s[zz.x][zz.y][zz.z]) {
                continue;
            }
            if (vis[zz.x][zz.y][zz.z]) continue;
            vis[zz.x][zz.y][zz.z] = 1;
            zz.step = now.step + 1;
            q.push(zz);
            // cout << "x == " << zz.x << "  y == " << zz.y << "  z == " << zz.z << "  zz.step == " << zz.step <<endl;
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) up();
    return 0;
}