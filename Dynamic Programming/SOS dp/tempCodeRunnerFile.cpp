const int N = 20;
int A[(1 << N) + 100];
int F[(1 << N) + 100];
int pow2[(1 << N) + 100];
int main(void) {
    // freopen("kosare.in.10","r",stdin);
    // freopen("10.out","w+",stdout);
    int m;
    pow2[0] = 1;
    for (int i = 1; i < (1 << N); ++i) pow2[i] = pow2[i - 1] * 2 % mod;

    int n;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        int t = 0;
        rep(i, 0, k) {
            int a;
            scanf("%d", &a);
            t |= 1 << (a - 1);
        }
        F[t]++;
    }
    for (int i = 0; i < m; ++i) {
        for (int mask = 0; mask < (1 << m); ++mask)
            if (mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        int t = 1;
        if ((m - __builtin_popcount(mask)) & 1) t = -1;
        ans = (ans + 1ll * t * pow2[F[mask]] % mod + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}