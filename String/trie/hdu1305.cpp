// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int a[N][2], fl, cnt, ed[N], ha[N];
char s[N];
int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ks = 0;
    while (~scanf("%s", s + 1)) {
        fl = 0, cnt = 0;
        a[0][1] = a[0][0] = 0;
        while (s[1] != '9') {
            int p = 0, len = strlen(s + 1);
            for (int i = 1; i <= len; i++) {
                if (fl) break;
                int x = s[i] - '0';
                if (!a[p][x]) {
                    a[p][x] = ++cnt;
                    a[cnt][0] = 0;
                    a[cnt][1] = 0;
                    ha[cnt] = 0;
                    ed[cnt] = 0;
                }
                p = a[p][x];
                if (ha[p]) fl = 1;
                if (i == len) {
                    if (ed[p]) fl = 1;
                    ha[p] = 1;
                }
                ed[p] = 1;
            }
            scanf("%s", s + 1);
        }
        if (fl) {
            printf("Set %d is not immediately decodable\n", ++ks);
        } else {
            printf("Set %d is immediately decodable\n", ++ks);
        }
    }
    return 0;
}
