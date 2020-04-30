// She is Pretty pretty!
//#include <bits/stdc++.h>
#include<iostream>
#include <cstdio>
#include<cstring>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2000010, P = 31, D = 1000173169, M = 262143;
int n, i, pp[N], f[N];
char a[N];
int Hash(int l, int r) {
    cout << "l == " << l << endl;
    return (ll)(f[r] - (ll)f[l - 1] * pp[r - l + 1] % D + D) % D;
}
int main() {
    scanf("%s", a + 1);
    n = strlen(a+1);
    cout << "n === " << n << endl;
    for (pp[0] = i = 1; i <= n; i++) pp[i] = (ll)pp[i - 1] * P % D;
    for (i = 1; i <= n; i++) f[i] = (ll)((ll)f[i - 1] * P + a[i]) % D;
    int ks;
    scanf("%d",&ks);
    for(int i = 1; i <= ks; i++){
        int l1 , l2 , r1, r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,r2);
        cout <<"l1 == " << l1 << endl;
        puts(Hash(l1,r1) == Hash(l2,r2) ? "YES":"NO");
    }
    // scanf(”% d % s”, &n, a + 1);
    // for (pp[0] = i = 1; i <= n; i++) pp[i] = (ll)pp[i−1] * P % D;
    // for (i = 1; i <= n; i++) f[i] = (ll)((ll)f[i−1] * P + a[i]) % D;
}
