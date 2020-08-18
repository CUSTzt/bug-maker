#include <bits/stdc++.h>
using namespace std;
using db = double;
const db eps = 1e-10;
const int maxn = 2020;
struct Point {
    db x, y;
    Point() {}
    Point(db _x, db _y) { x = _x, y = _y; }
    Point operator+(Point a) { return Point(x + a.x, y + a.y); }
    Point operator-(Point a) { return Point(x - a.x, y - a.y); }
    Point operator*(db a) { return Point(x * a, y * a); }
    db operator*(Point a) { return x * a.x + y * a.y; }
    db operator^(Point a) { return x * a.y - y * a.x; }
    db len2() { return x * x + y * y; }
    db len() { return sqrt(len2()); }
} a[maxn];
int n, ans;
int main() {
    // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%lf%lf",&a[i].x,&a[i].y);
    for (int i = 0; i < n; i++) {
        vector<db> angle;
        for (int j = 0; j < n; j++) {
            if ((a[i] ^ a[j]) > eps) {
                db ang = (a[i] - a[j]) * (Point(0, 0) - a[j]) / (a[i] - a[j]).len() / a[j].len();
                angle.emplace_back(ang);
                // cout << "ang === " << ang << endl;
            }
        }
        sort(angle.begin(), angle.end());
        int u = 0, v = 0;
        while (v < angle.size()) {
            v++;
            // cout << "u === " << u << endl;
            // cout << "angv == " << angle[v] << "   angu == " << angle[u] << endl;
            while (angle[v] - angle[u] < eps && v < angle.size()) v++;
            // cout << "after  v == " << v << "  u == " << u << endl;
            ans = max(ans, v - u);
            u = v;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}