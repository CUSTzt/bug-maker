// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
struct Node {
    ll w, s, v;
} a[N];
bool cmp(Node a, Node b) { return a.w + a.s < b.w + b.s; }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].s >> a[i].v;
    }
    sort(a+1, a+1+n,cmp);
for(int i = 1; i <= n; i++){
for(int )
}

    return 0;
}