/****************************************************************
# @Author:      iLovePKU_zbtxdy
# @DateTime:    2020-03-21 12:35:38
# @Description: Think twice . Code once.
# @More: Once lots of AC, try Brute-force,dynamic programming
****************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define close std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 1e6;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9 + 7;
double f(int x){
    
}
double simpson(double l, double r) {
    return (f(l) + f(r) + 4 * f((l + r) / 2.0)) * (r−l) / 6.0;
}
double rsimpson(double l, double r) {
    double mid = (l + r) / 2.0;
    if (fabs(simpson(l, r)−simpson(l, mid)−simpson(mid, r)) < eps)
        return simpson(l, mid) + simpson(mid, r);
    return rsimpson(l, mid) + rsimpson(mid, r);
}

int main() {}
/***************************************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
 ***************************************************************************/
