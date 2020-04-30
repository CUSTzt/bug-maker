#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6 + 100;
char a[N], b[N];
int nxt[N];
void kmp(int n, char *a, int m, char *b) {
    int i, j;
    for (nxt[0] = j = -1, i = 1; i < n; nxt[i++] = j) {
        while (~j && a[j + 1] != a[i]) j = nxt[j];
        if (a[j + 1] == a[i]) j++;
    }
    cout << 1 << endl;
    for (j = -1, i = 0; i < m; i++) {
        while (~j && a[j + 1] != b[i]) j = nxt[j];
        if (a[j + 1] == b[i]) j++;
        if (j == n - 1) cout << i << endl, j = nxt[j];
    }
}
int main() {
    scanf("%s %s", a , b );
    int n = strlen(a ), m = strlen(b );
    cout << n << " " << m << endl;
    n++, m++;
    kmp(n, a, m, b);
    for (int i = 1; i <= n; i++) cout << nxt[i] << ' ';
}