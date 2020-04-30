// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;
int a[N], b[N] int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = (a[i] + 1) / 2;
        w -= b[i];
    }
    while(w >0){
        int d = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > a[d] && a[i]!= b[i])d=i;
        }
        int p = min(w, a[d] - b[d]);
        w-=p;
        b[d]+=p;
    }if(w < 0){
        
    }
    return 0;
}