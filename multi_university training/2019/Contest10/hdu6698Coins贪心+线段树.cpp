//https://blog.csdn.net/yopilipala/article/details/100740979
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn = 1e6+100;
const ll INF = 1e18;

struct Node2 {
    ll a, b;
}p[maxn];
struct Node{
    ll MaxA, MaxB, MaxAB, MinA, MinB;//Max部分是能够直接取的，Min部分是能够直接还回去的
}node[maxn];
ll n, t, ans[maxn];

void update(ll root) {
    ll chl = root<<1, chr = root<<1|1;
    node[root].MinB = min(node[chl].MinB, node[chr].MinB);
    node[root].MinA = min(node[chl].MinA, node[chr].MinA);
    node[root].MaxB = max(node[chl].MaxB, node[chr].MaxB);
    node[root].MaxAB = max(node[chl].MaxAB, node[chr].MaxAB);
    node[root].MaxA = max(node[chl].MaxA, node[chr].MaxA);
}

void build_tree(ll root, ll l,ll r) {
    if(l == r) {
        node[root].MaxA = p[l].a;
        node[root].MaxAB = p[l].a + p[l].b;
        node[root].MaxB = 0;
        node[root].MinA = INF;
        node[root].MinB = INF;
        return ;
    }

    ll mid = l + r >> 1;
    build_tree(root<<1, l, mid);
    build_tree(root<<1|1, mid+1, r);

    update(root);
}

void init() {
    scanf("%lld", &n);
    for(ll i=1;i<=n;i++) {
        scanf("%lld%lld", &p[i].a, &p[i].b);
    }
    build_tree(1, 1, n);
}

void changeMaxA(ll root, ll l, ll r, ll va) {
    if(l == r) {
        node[root].MaxA = 0;
        node[root].MaxB = p[l].b;
        node[root].MaxAB = 0;
        node[root].MinA = p[l].a;
        return ;
    }

    ll mid = l + r >> 1;
    ll chl = root<<1, chr = root<<1|1;
    if(node[chl].MaxA == node[root].MaxA) {
        changeMaxA(chl, l, mid, va);
    } else {
        changeMaxA(chr, mid+1, r, va);
    }
    update(root);
}

void changeMaxB(ll root, ll l, ll r, ll va) {
    if(l == r) {
        node[root].MaxB = 0;
        node[root].MinB = p[l].b;
        node[root].MinA = INF;
        return ;
    }

    ll mid = l + r >> 1;
    ll chl = root<<1, chr = root<<1|1;
    if(node[chl].MaxB == node[root].MaxB) {
        changeMaxB(chl, l, mid, va);
    } else {
        changeMaxB(chr, mid+1, r, va);
    }
    update(root);
}

void changeMinA(ll root, ll l, ll r, ll va) {
    if(l  ==  r) {
        node[root].MinA = INF;
        node[root].MaxAB = p[l].a + p[l].b;
        node[root].MaxA = p[l].a;
        node[root].MaxB = 0;
        return ;
    }
    ll chl = root<<1, chr = root<<1|1;
    ll mid = l + r >> 1;
    if(node[chl].MinA == node[root].MinA) {
        changeMinA(chl, l, mid, va);
    } else {
        changeMinA(chr, mid+1, r, va);
    }
    update(root);
}

void changeMinB(ll root, ll l, ll r,ll va) {
    if(l == r) {
        node[root].MinB = INF;
        node[root].MinA = p[l].a;
        node[root].MaxB = p[l].b;
        return ;
    }

    ll mid = l + r >> 1;
    ll chl = root<<1, chr = root<<1|1;
    if(node[chl].MinB == node[root].MinB) {
        changeMinB(chl, l, mid, va);
    } else {
        changeMinB(chr, mid+1, r, va);
    }
    update(root);
}

void changeMaxAB(ll root, ll l, ll r) {
    if(l == r) {
        node[root].MaxAB = 0;
        node[root].MinB = p[l].b;
        node[root].MaxA = 0;
        return ;
    }
    ll mid = l + r >> 1;
    ll chl = root<<1, chr = root<<1|1;
    if(node[chl].MaxAB == node[root].MaxAB) {
        changeMaxAB(chl, l, mid);
    } else {
        changeMaxAB(chr, mid+1, r);
    }
    update(root);
}

void solve() {
    ll sum = 0;

    for(ll i=1;i<=2*n;i++) {
        ll sum1, sum2;
        sum1 = sum2 = sum;

        ll va1 = node[1].MaxA;
        ll va2 = node[1].MaxB;
        sum1 += max(va1, va2);

        ll va3 = min(node[1].MinA, node[1].MinB);
        sum2 = sum2 - va3 + node[1].MaxAB;

        if(sum1 >= sum2) {
            if(sum1 == sum + va1) {
                changeMaxA(1, 1, n, va1);
            } else {
                changeMaxB(1, 1, n, va2);
            }
        } else {
            if(va3 == node[1].MinA) {
                changeMinA(1, 1, n, va3);
            } else {
                changeMinB(1, 1, n, va3);
            }
            changeMaxAB(1, 1, n);
        }
        sum = max(sum1, sum2);
        ans[i] = sum;
    }
}

int main() {
//    freopen("1.in.txt", "r", stdin);
    scanf("%lld", &t);
    while(t--) {
        init();
        solve();
        for(ll i=1;i<=2*n;i++) {
            printf("%lld%c", ans[i], i == 2*n ? '\n': ' ');
        }
    }
    return 0;
}

