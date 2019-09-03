/***********************************************
 * @Author:      miniLCT
 * @DateTime:    2019-08-20 14:28:43
 * @Description: You build it, You run it.  
 * @More : 在会用scanf 的情况下尽量用scanf
 ***********************************************/
//#include <bits/stdc++.h>
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
    int date , value;
}item[maxn];
bool cmp(Node a,Node b){
    return a.value > b.value;
}
int vis[maxn] = {0};
main()
{
    operator
    int n;
    while(~scanf("%lld",&n)){
        memset(vis,0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            cin >> item[i].value >> item[i].date;
        }
        sort(item + 1,item + n + 1,cmp);
        int sum = 0;
        for(int i = 1; i <= n;i++){
            if(!vis[item[i].date]){
                vis[item[i].date] = 1;
                sum += item[i].value;
            }
            else {
                for(int j = item[i].date - 1; j >= 1; j--){
                    if(!vis[j]){
                        vis[j] = 1;
                        sum += item[i].value;
                        break;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
}
/****************************************************
 *stuff you should look for
 *int overflow, array bounds
 *special cases (n=1?), set tle
 *do smth instead of nothing and stay organized
****************************************************/
