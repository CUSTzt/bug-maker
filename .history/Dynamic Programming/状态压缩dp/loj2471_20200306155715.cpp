// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n ;
int a[21][21], ok[1 << 21],cnt,sum[21][1<<21];
bool check(int x){
    if(x & (x << 1))return false;
    return true;
}
int get_sum(int i, int j){ // i行状态为j
    int res = 0;
    for(int k = 0; k < n ; k++){
        if((j >> k) & 1)
        res+=a[i][n-1-k];
    }return res;
}
void pre(int x){
    int m = 1 << x;
    cnt = 0;
    memset(sum , 0 , sizeof sum);
    for(int i = 0; i < m; i++){
        if(check(i))ok[cnt++] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < )
    }
}
int main()
{
    while(cin >> n){
        pre(n);
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                cin >> a[i][j] ;
            }
        }
    }
    
    return 0;
}