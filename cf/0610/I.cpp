// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 1100 + 100;

int w, h;
char a[N][N];
int vis[N][N];
set<pair<int, int>> s;
int chk(int x, int y) {
    if (x < 1 || x > h || y < 1 || y > w) {
        return 1;
    }
    return 0;
}
int checkA(int zx, int zy, int yx, int yy, set<pair<int, int>> s) {
    zx--, zy--, yx++, yy++;
    for (int i = zx; i <= yx; i++)
        if (chk(i, zy) || chk(i, yy)) return 0;
    for (int i = zy; i <= yy; i++)
        if (chk(zx, i) || chk(yx, i)) return 0;
    set<pair<int, int>> ans;
    int n = yx - zy, m = yy - zy;
    int x = 2 * m - 3 * n + 1, y = 2 * n - m - 1;
    for (int i = zx + 1; i <= yx - 1; i++) {
        for (int j = zy + 1; j <= zy + x; j++) {
            ans.insert({i, j});
        }
        for (int j = zy + 1 + x + y; j <= zy + x * 2 + y; j++) {
            ans.insert({i, j});
        }
    }
    for (int j = zy + 1; j < yy; j++) {
        for (int i = zx + 1; i <= zx + x; i++) {
            ans.insert({i, j});
        }
        for (int i = yx - 1; i >= zx - x; i--) {
            ans.insert({i, j});
        }
    }
    // for(int i = yx-1; i > yx-x;i--){
    //     for(int j = zy + 1; j < yy; j++){
    //         ans.insert({i,j});
    //     }
    // }
    if (ans == s) return 1;
    return 0;
}
int checkB(int zx, int zy, int yx, int yy, set<pair<int, int>> s) {
    zx--, zy--, yx++, yy++;
    for (int i = zx; i <= yx; i++)
        if (chk(i, zy) || chk(i, yy)) return 0;
    for (int i = zy; i <= yy; i++)
        if (chk(zx, i) || chk(yx, i)) return 0;
    set<pair<int, int>> ans;
    int n = yx - zy, m = yy - zy;
    int x = 2 * m - 3 * n + 1, y = 2 * n - m - 1;
    for (int i = zx + 1; i <= yx - 1; i++) {
        for (int j = zy + 1; j <= zy + x; j++) {
            ans.insert({i, j});
        }
        for (int j = zy + 1 + x + y; j <= zy + x * 2 + y; j++) {
            ans.insert({i, j});
        }
        for (int j = yy - x; j < yy; j++) {
            ans.insert({i, j});
        }
    }
    for (int j = zy + 1; j < yy; j++) {
        for (int i = zx + 1; i <= zx + x; i++) {
            ans.insert({i, j});
        }
        for (int i = yx - 1; i >= zx - x; i--) {
            ans.insert({i, j});
        }
    }
    if (ans == s) return 1;
    return 0;
}
int checkC(int zx, int zy, int yx, int yy, set<pair<int, int>> s) {
    for (int i = zx; i <= yx; i++)
        if (chk(i, zy) || chk(i, yy)) return 0;
    for (int i = zy; i <= yy; i++)
        if (chk(zx, i) || chk(yx, i)) return 0;
    set<pair<int, int>> ans;
    int n = yx - zy, m = yy - zy;
    int x = 2 * m - 3 * n + 1, y = 2 * n - m - 1;
    for (int i = zx + 1; i <= yx - 1; i++) {
        for (int j = zy + 1; j <= zy + x; j++) {
            ans.insert({i, j});
        }
        for (int j = yy - x; j < yy; j++) {
            ans.insert({i, j});
        }
    }
    for(int i = zx+1; i <= zx+x; i++){
        for(int j = zy+1; j < yy; y++){
            ans.insert({i, j});
        }
    }
    if (ans == s) return 1;
    return 0;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = dx[i] + x, yy = dy[i] + y;
        if (chk(xx, yy)) continue;
        if (a[xx][yy] == '.') continue;
        if (vis[xx][yy]) continue;
        s.insert({xx, yy});
        vis[xx][yy] = 1;
        dfs(xx, yy);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> h;
    for (int i = 1; i <= h; i++) {
        cin >> a[i] + 1;
    }
    int numa = 0, numb = 0, numc = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; i <= w; i++) {
            if (vis[i][j] == 0 && a[i][j] == '#') {
                dfs(i, j);
                auto pp = s.begin();
                auto qq = s.rbegin();
                int zx = (*pp).first, zy = (*pp).second, yx = (*qq).first,
                    yy = (*qq).second;
                int nn = yx - zx, mm = yy - zy;
                if (checkA(zx, zy, yx, yy, s)) numa++;
                if (checkB(zx, zy, yx, yy, s)) numb++;
                if (checkC(zx, zy, yx, yy, s)) numc++;
                s.clear();
            }
        }
    }
    cout << numa << ' ' << numb << " " << numc << endl;
    return 0;
}