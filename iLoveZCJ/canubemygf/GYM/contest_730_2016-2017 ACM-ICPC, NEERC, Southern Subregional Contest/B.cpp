//others
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define clr(a, x) memset(a, x, sizeof a)

const int MAXN = 105;

pii a[MAXN];

void solve() {
    int cnt = 0, n;
    scanf("%d", &n);
    for (int i = 1; i < n; i += 2) {
        printf("? %d %d\n", i, i + 1);
        fflush(stdout);
        char op[5];
        scanf("%s", op);
        if (op[0] == '<')
            a[++cnt] = pii(i, i + 1);
        else
            a[++cnt] = pii(i + 1, i);
    }
    if (n & 1) a[++cnt] = pii(n, n);
    for (int i = 1; i < cnt; ++i) {
        printf("? %d %d\n", a[i].first, a[i + 1].first);
        fflush(stdout);
        char op[5];
        scanf("%s", op);
        if (op[0] == '<') a[i + 1].first = a[i].first;
        printf("? %d %d\n", a[i].second, a[i + 1].second);
        fflush(stdout);
        scanf("%s", op);
        if (op[0] == '>') a[i + 1].second = a[i].second;
    }
    printf("! %d %d\n", a[cnt].first, a[cnt].second);
    fflush(stdout);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}