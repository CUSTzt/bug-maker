// #include <bits/stdc++.h>
// #define fo0(i, n) for (int i = 0, i##e = n; i < n; i++)
// #define fo1(i, n) for (int i = 1, i##e = n; i <= n; i++)
// struct Z {
//     char b[1700000], *l;
//     Z() { fread(l = b, 1, sizeof b, stdin); }
//     inline operator int() {
//         int r = 0;
//         while (*l < 48) l++;
//         while (*l > 47) r = r * 10 + *l++ - 48;
//         return r;
//     }
// } it;
// typedef long long ll;
// std::vector<ll> s[4];
// int tc;
// ll v[300001], t[300001], u[300001];
// inline void solve(ll* s, int v, int l, int r, int L, int R) {
//     if (l > r || L > R) return;
//     int m = (l + r) >> 1, p = -1;
//     for (int i = std::max(L, m - v); i <= R && i <= m; i++) {
//         ll g = t[i] + s[m - i];
//         if (g > u[m]) u[m] = g, p = i;
//     }
//     solve(s, v, l, m - 1, L, p);
//     solve(s, v, m + 1, r, p, R);
// }
// int main() {
//     int n = it, m = it, x, y;
//     fo1(i, 3) s[i].push_back(2e9);
//     while (n--) {
//         x = it, y = it;
//         s[x].push_back(y);
//     }
//     fo1(i, 3) if (s[i].size() > 1) {
//         std::sort(s[i].begin(), s[i].end(), std::greater<int>());
//         s[i][0] = 0;
//         fo1(j, s[i].size() - 1) s[i][j] += s[i][j - 1];
//         fo1(j, i) {
//             tc = 0;
//             for (int k = j; k <= m; k += i) u[++tc] = 0, t[tc] = v[k];
//             t[0] = i == j ? 0 : -1e18;
//             solve(&s[i][0], s[i].size() - 1, 1, tc, 0, tc);
//             tc = 0;
//             for (int k = j; k <= m; k += i) v[k] = u[++tc];
//         }
//     }
//     printf("%I64d", v[m]);
// }