// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

void up() {
    int n, k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0;
    int mx = 0;
    while (r < n) {
        while(a[r] - a[l] < k){
            r++;
            if(r == n-1)break;
        }
        if(r==n-1)break;
        mx = max(mx , r-l);
        l++;
    }
    while(a[r] - a[l] > k){
        l++;
    }
    mx = max(r+)
    cout <<mx << endl;
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