#include <bits/stdc++.h>
#define N 200100
using namespace std;
int tmp[18];
bool cmp(int i, int j) { return tmp[i] < tmp[j]; }
int main() {
    int n, a[2][18], b[18];
    int ans = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    for (int i = 0; i < (1 << n); i++) {
        vector<int> s[2];
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tmp[j] = a[1][j];
                s[(j & 1) ^ 1].push_back(j);
            } else {
                tmp[j] = a[0][j];
                s[j & 1].push_back(j);
            }
        }
        if (s[1].size() != n / 2) continue;
        for (int j = 0; j < 2; j++) {
            stable_sort(s[j].begin(), s[j].end(), cmp);
        }
        bool flag = false;
        for (int j = 1; j < n; j++) {
            if (tmp[s[j & 1][j >> 1]] < tmp[s[(j - 1) & 1][(j - 1) >> 1]])
                flag = true;
        }
        int tans = 0;
        if (!flag) {
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (s[j & 1][j >> 1] > s[k & 1][k >> 1]) tans++;
                }
            }
            if (tans < ans || ans < 0) ans = tans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
