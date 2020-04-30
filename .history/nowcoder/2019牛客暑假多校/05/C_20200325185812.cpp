#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define int long long 
int phi(int n) {
    int t = 1, i;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            for (n /= i, t *= i-1; n % i == 0; n /= i, t *= i)
                ;
    if (n > 1) t *= n-1;
    return t;
}
int pow(ll a, int b, int m) {
    ll t = 1;
    for (; b; b >>= 1, a = a * a % m)
        if (b & 1) t = t * a % m;
    return t;
}
int bsgs(int a, int r, int m) {
    if (r >= m) return -1;
    int i, g, x, c = 0, at = int(2 + sqrt(m));
    for (i = 0, x = 1 % m; i < 50; i++, x = ll(x) * a % m)
        if (x == r) return i;
    for (g = x = 1; __gcd(int(ll(x) * a % m), m) != g; c++)
        g = __gcd(x = ll(x) * a % m, m);
    if (r % g) return -1;
    if (x == r) return c;
    unordered_map<int, int> u;
    g = phi(m / g), u[x] = 0;
    g = pow(a, g-at % g, m);
    for (i = 1; i < at; i++) {
        u.insert(P(x = ll(x) * a % m, i));
        if (x == r) return c + i;
    }
    for (i = 1; i < at; i++) {
        unordered_map<int, int>::iterator t = u.find(r = ll(r) * g % m);
        if (t != u.end()) return c + i * at + t-> second;
    }
    return -1;
}
