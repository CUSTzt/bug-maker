
const int N = 3e5 + 10;
int a, b, q, lcmm;
int s[N];
int calc(int x) { return s[lcmm] * (x / lcmm) + s[x % lcmm]; }
signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> q;

        lcmm = a * b / gcd(a, b);

        rep(i, 1, lcmm) s[i] = s[i - 1] + (i % a % b != i % b % a);

        while (q--) {
            int l, r;
            cin >> l >> r;

            cout << calc(r) - calc(l - 1) << " ";
        }

        cout << '\n';
    }

    return 0;
}
