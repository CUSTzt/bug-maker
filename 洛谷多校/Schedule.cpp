#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10011;
int n, q;

char cn[MAXN][100];
char mp[255];
int sch[5][13][MAXN][2]; // [weekday][sl][week][course/el]

int main() {
    scanf("%d\n", &n);
    mp['o'] = 0, mp['u'] = 1, mp['e'] = 2, mp['h'] = 3, mp['r'] = 4;
    for (int i = 1; i <= n; i++) {
        cin.getline(cn[i], 100);
        cn[i][strlen(cn[i]) - 1] = '\0';
        int sw, ew, sl, el, wd;
        char dn[10];
        while (scanf("%d-%d%s%d-%d\n", &sw, &ew, dn, &sl, &el) == 5) {
            wd = mp[dn[1]];
            for (int j = sw; j <= ew; j++) {
                sch[wd][sl][j][0] = i;
                sch[wd][sl][j][1] = el;
            }
        }
        if (i == n) q = sw;
    }
    while (q--) {
        int wk, wd;
        char dn[10];
        scanf("%d%s", &wk, dn);
        wd = mp[dn[1]];
        for (int i = 1; i <= 12; i++) {
            auto x = sch[wd][i][wk];
            if (x[0]) printf("%d-%d %s\n", i, x[1], cn[x[0]]);
        }
        if (q) puts("");
    }
}
