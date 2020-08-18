// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , m, a, b;
void up() {
    cin >> n >> m >> a >> b;
    if(n * a != m * b){
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    char aa[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            aa[i][j] = '0';
        }
    }
    int cn = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a; j++){
            aa[i][(cn) % m] = '1';
            cn++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << aa[i][j] ;
        }cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _; while (_--) up();
    return 0;
}