// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n , k , a[N], dp[N];
int boyi(int x){
    if(dp[x]) return dp[x];
    int fl = 0;
    for(int i = 0 ; i < n; i++){
        if(a[i] < x && boyi(x - a[i]) == -1){
            fl = 1;
        }
    }
    return dp[x] =  fl ? 1 : -1;
}
int main()
{
    if(-1)cout <<' '
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    puts(boyi(k) == 1? "First":"Second");
    return 0;
}