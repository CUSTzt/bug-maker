// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

char c[N];
int A[N];
void up() {
    cin >> c;
    int tot = 0;
    for (int a = 1; a <= 12; a++) {
        int b = 12 / a;
        if (b * a ^ 12) continue;
        for (int i = 0; i < b; i++) {
            int Flag = 1;
            for (int j = 0; j < a; j++)
                if (c[j * b + i] ^ 'X') {
                    Flag = 0;
                    break;
                }
            if (Flag) {
                A[tot++] = a;
                break;
            }
        }
    }
    printf("%d ", tot);
    for (int i = 0; i < tot; i++) printf("%dx%d ", A[i], 12 / A[i]);
    printf("\n");
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