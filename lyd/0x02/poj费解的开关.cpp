#include <bits/stdc++.h>
using namespace std;
char a[6][6];
int dx[] = {0, 0, -1, 0, 1}, dy[] = {0, -1, 0, 1, 0};
void turn(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 0 && tx < 5 && ty >= 0 && ty < 5) a[tx][ty] ^= 1;
    }
}
void work() {
    int ans = 0x3f3f3f3f, res, j;
    char t[6][6];
    memcpy(t, a, sizeof a);
    for (int i = 0; i < 1 << 5; i++) {
        res = 0;
        for (int j = 0; j < 5; j++)
            if (i >> j & 1) res++, turn(0, j);
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 5; k++)
                if (a[j][k] == '0') {
                    res++;
                    turn(j + 1, k);
                }
        for (j = 0; j < 5; j++)
            if (a[4][j] == '0') break;
        if (j == 5 && res <= 6) ans = min(ans, res);
        memcpy(a, t, sizeof t);
    }
    if (ans != 0x3f3f3f3f)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 5; i++) cin >> a[i];
        work();
    }
    return 0;
}