#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
#define int long long
const int maxn = 10005;
#define eps 1e-8
using namespace std;
struct Node{
    int d , v;
}a[maxn];
bool cmp(Node a,Node b){return a.v > b.v;}
int vis[maxn] = {0};
main()
{
    int n;
    while(~scanf("%lld",&n)){
        memset(vis,0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            cin >> a[i].v >> a[i].d;
        }
        sort(a + 1,a + n + 1,cmp);
        int sum = 0;
        for(int i = 1; i <= n;i++){
            if(!vis[a[i].d]){
                vis[a[i].d] = 1;
                sum += a[i].v;
            }
            else {
                for(int j = a[i].d - 1; j >= 1; j--){
                    if(!vis[j]){
                        vis[j] = 1, sum += a[i].v;
                        break;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
}
