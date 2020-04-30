// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

struct node {
    int v, s;
} a[N];
bool cmp(node a, node b) { return a.s > b.s; }
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v >> a[i].s;
    }
    sort(a+1, a+n+1, cmp);
    priority_queue<int, vector<int>, greater<int> > q;
    int ans = -1;
    int zz = 0;
    for(int i = 1; i <= n; i++){
        zz += a[i].v;
        q.push(a[i].v);
        while(q.size() > a[i].s){
            zz-=q.top();
            q.pop();
        }ans = max(ans , zz);
    }cout << ans << endl;
    return 0;
}