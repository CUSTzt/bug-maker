#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxp = 2 * 200 * (1 << 10) + 5;
int T, n, k, p[maxp];
vector<int> a[maxp];
int main(void) {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        int len = 2 * n * (1 << k);
        int m = 1 << k;
        for (int i = 1; i <= m; i++) a[i].clear();
        for (int i = 1; i <= len; i++) {
            scanf("%d", &p[i]);
            a[m].push_back(p[i]);
        }
        reverse(a[m].begin(), a[m].end());
        for (int t = 0; t < k; t++)
            for (int i = m - (1 << t) + 1, j = i - 1; i <= m; i++, j--) {
                int size = (int)(a[i].size()) / 2;
                while (size--) {
                    a[j].push_back(a[i].back());
                    a[i].pop_back();
                }
            }
        int dep = a[m].size();
        for (int d = 1; d <= dep; d++) {
            for (int i = 1; i <= m; i++) {
                printf("%d", a[i].back());
                a[i].pop_back();
                if (d == dep && i == m && a[i].size() == 0)
                    printf("\n");
                else
                    printf(" ");
            }
        }
    }
    return 0;
}
