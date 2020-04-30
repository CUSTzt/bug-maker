#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2000 + 5;
#define MAX(x, y) 
((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
int G[maxn][maxn];
char s[maxn][maxn];
int right[maxn][maxn], left[maxn][maxn], up[maxn][maxn];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        for (int _i = 0; _i < 26; _i++) {
            int m, n;
            scanf("%d%d", &m, &n);
            int idx = -1, idy = 1;
            for (int i = 0; i < m; i++) scanf("%s", s[i]);
            ;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    G[i][j] = s[i][j] != _i + 'A' ? 1 : 0;
                }
            // int res=0;
            int Mx1 = 0, Mx2 = 0;
            for (int i = 0; i < m; i++) {
                int lo = -1, ro = n;
                for (int j = 0; j < n; j++)
                    if (G[i][j] == 1) {
                        up[i][j] = left[i][j] = 0;
                        lo = j;
                    } else {
                        up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
                        left[i][j] =
                            i == 0 ? lo + 1 : MAX(left[i - 1][j], lo + 1);
                    }
                int tp = 0;
                int lax = -1, lay = -1, laz = -1;
                for (int j = n - 1; j >= 0; j--) {
                    if (G[i][j] == 1) {
                        right[i][j] = n;
                        ro = j;
                    } else {
                        right[i][j] =
                            i == 0 ? ro - 1 : MIN(right[i - 1][j], ro - 1);
                        ans = MAX(
                            ans, MIN(up[i][j], (right[i][j] - left[i][j] + 1)));
                        // printf("%d %d %d %d %d
                        // %d\n",i,j,up[i][j],right[i][j],left[i][j],tp);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
