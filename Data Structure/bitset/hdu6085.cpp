// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 50010;
int b[N], qq[N], q[N], ans[N];
void umax(int &a , int b){ if(a < b) a = b;}
void up() {
    int n , m , k;
    cin >> n >> m >> k;
    bitset<N> A , B;
    int mx = 0;
    memset(b , 0 , sizeof b); memset(qq , 0 , sizeof qq);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        umax(mx , x);
        A.set(x);
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        umax(mx , x);
        b[x] = 1;
    }
    for(int i = 0; i < k; i++){
        cin >> q[i];
        qq[q[i]] = 1;
    }
    for(int i = mx; ~i ; i--){
        if(qq[i]) ans[i] = (B & (A >> i)).count() & 1;
        if(b[i]) for(int j = 0; j <= mx; j += i){
            B.flip(j);
        } 
    }
    for(int i = 0; i < k; i++) cout << ans[q[i]] << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}