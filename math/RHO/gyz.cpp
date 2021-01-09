#include<bits/stdc++.h>
using namespace std;
using LL=long long;
inline LL add(LL x, LL y, LL mod) {
    return (x += y) < mod ? x : x - mod;
}
 
inline LL mul(LL x, LL y, LL mod) {
    const int BLEN = __builtin_clzll(mod) - 1;
    const LL BMSK = (1LL << BLEN) - 1;
    LL ret = 0;
    if(x < y)
        swap(x, y);
    while(y > 0) {
        ret += x * (y & BMSK);
        ret = ret < mod ? ret : ret % mod;
        y >>= BLEN;
        x <<= BLEN;
        x = x < mod ? x : x % mod;
    }
    return ret;
}
 
inline LL Pow(LL x, LL k, LL mod) {
    LL ret = mod > 1 ? 1 : 0;
    for( ; k > 0; k >>= 1, x = mul(x, x, mod))
        if(k & 1)
            ret = mul(ret, x, mod);
    return ret;
}
 
inline bool miller_rabin(LL n) {
    if(n == 2)
        return 1;
    if(n < 2 || !(n & 1))
        return 0;
    LL s, r;
    for(s = 0, r = n - 1; !(r & 1); r >>= 1, ++s);
    static const int ptot = 12, pr[ptot] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int p : pr) {
        if(p >= n)
            break;
        LL cur = 1, nxt = p;
        for(LL k = r; k > 0; k >>= 1, nxt = mul(nxt, nxt, n))
            if(k & 1)
                cur = mul(cur, nxt, n);
        for(int i = 0; i < s; ++i) {
            nxt = mul(cur, cur, n);
            if(nxt == 1 && cur != 1 && cur != n - 1)
                return 0;
            cur = nxt;
        }
        if(cur != 1)
            return 0;
    }
    return 1;
}
 
inline LL pollard_rho(LL n) {
    static mt19937_64 rnd(996);
    while(1) {
        LL x = rnd() % (n - 3) + 2, y = x, c = rnd() % n, tim = 0, prd = 1;
        for(LL i = 1, stp = 2; ; ++i) {
            if(i == stp) {
                y = x;
                stp <<= 1;
            }
            if((x = add(mul(x, x, n), c, n)) == y)
                break;
            LL tmp = prd;
            if((prd = mul(prd, abs(y - x), n)) == 0)
                return __gcd(tmp, n);
            static const int maxt = 100;
            if((++tim) < maxt)
                continue;
            if((prd = __gcd(prd, n)) > 1)
                return prd;
            tim = 0;
        }
        if(tim > 0 && (prd = __gcd(prd, n)) > 1)
            return prd;
    }
    assert(0);
}
 
inline void factorize(LL n, vector<pair<LL, int> > &ret) {
    vector<LL> vec;
    queue<LL> que;
    que.push(n);
    while(!que.empty()) {
        LL x = que.front();
        que.pop();
        for(LL y : vec)
            for( ; x % y == 0; x /= y, vec.push_back(y));
        if(x == 1)
            continue;
        if(miller_rabin(x)) {
            vec.push_back(x);
        } else {
            LL y = pollard_rho(x);
            que.push(y);
            que.push(x / y);
        }
    }
    sort(vec.begin(), vec.end());
    ret.clear();
    for(auto x : vec)
        if(!ret.empty() && ret.back().first == x) {
            ++ret.back().second;
        } else {
            ret.push_back(make_pair(x, 1LL));
        }
}
int main(){
    
}