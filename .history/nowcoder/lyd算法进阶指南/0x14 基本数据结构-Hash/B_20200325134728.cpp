// She is Pretty pretty!
// #include <bits/stdc++.h>
#include<cstdio>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2000010, P = 31, D = 1000173169, M = 262143;
int n, i, pp[N], f[N];
char a[N];
int hash(int l, int r) {
    return (ll)(f[r]-(ll)f[l-1] * pp[r-l + 1] % D + D) % D;
}
int main() {
    scanf("%s",a+1);
    for(pp[0] = i = 1; i<=n; i++)pp[i]=(ll)pp[i-1]*P%D;
    for(i = 1; i <= n ; i++)f[i] = (ll)((ll)f[i-1]*P+a[i])
    // scanf(”% d % s”, &n, a + 1);
    // for (pp[0] = i = 1; i <= n; i++) pp[i] = (ll)pp[i−1] * P % D;
    // for (i = 1; i <= n; i++) f[i] = (ll)((ll)f[i−1] * P + a[i]) % D;
}
