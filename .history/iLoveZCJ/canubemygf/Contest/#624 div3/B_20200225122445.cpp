#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define POP pop_back()
#define PII pair<int,int>
#define ULL unsigned long long
using namespace std;
const int INF=0x3f3f3f3f;
const double pi=acos(-1),eps=1e-10;
const int maxn=1<<17;
const int N=5e3+10,M=N*40;
int vis[110],a[110],n,m;
int main()
{
    int t ;
    cin >> t;
    while(t--){
        memset(vis , 0 , sizeof vis);
        cin >> n >> m ;
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 1; i <= m; i++){
            int x;
            cin >> x;
            vis[x] = 1;
        }
        for(int i = 1; i <= n; ){
            int j = i; while(vis[j])j++;
            sort(a+i , a+j+1);
            i = j+1;
        }
        int fl = 1;
        for(int i = 2; i <= n; i++){
            if(a[i] < a[i-1]){
                cout << "NO\n";
                
                break;
            }
        }
    }
}
/*
1
6 7
0 0 0 0 0 0
0 1 0 3 0 1
2 9 1 2 1 2
8 7 1 3 4 3
1 0 2 2 7 7
0 1 0 0 1 0
0 0 0 0 0 0
*/