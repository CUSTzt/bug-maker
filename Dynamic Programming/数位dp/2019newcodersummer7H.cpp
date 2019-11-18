#include <bits/stdc++.h>
//题意：给定abc,问能找到多少对(x,y) x->[1,a],y->[1,b]
//满足x&y > c 和 x^y < c两个条件中至少满足一个

/*
 由于要求上述两个条件中至少满足一个，在处理上需要去重会有些麻烦，
 所以我们考虑取反，用A*B-sub,sub是同时满足x&y<=C和x^y>=C的数的个数。
 好像蛮典型的数位dp的，dp[pos][la][lb][and][xor]表示，
 数字a是否达到上限la,数字b是否达到上限lb,&是否满足条件and,
 ^是否满足条件xor,下面的操作就是正常的数位dp做的了。。
 根据是否需要达到要求规定范围。但是这里最后要减掉max(0ll,A-C+1)
 和max(0ll,B-C+1)，因为在上述条件下,在x=0,y>=C的对数也会被算入
 ，但是题目要求x最低是1，所以要减掉在B大于等于C时，C到B的那些数,
 y=0的时候同理。
 * */
using namespace std;
using ll = long long;
//using pii = pair<int , int >;
const  int maxn = 15;
ll dp[35][2][2][2][2], A, B , C;
ll dfs(int pos , int la, int lb , int And, int Xor){
    if(pos < 0) return 1ll;
    if(dp[pos][la][lb][And][Xor] != -1)return dp[pos][la][lb][And][Xor];
    ll ret = 0;
    int na = 1, nb = 1, nand = 1, nxor = 0;
    if(la) na = (A >> pos & 1);
    if(lb) nb = (B >> pos & 1);
    if(Xor) nxor = (C >> pos & 1);
    for(int i = 0; i <= na;i++){
        for(int j = 0; j <= nb;j++){
            if((i & j) > nand) continue;
            if((i ^ j) < nxor) continue;
            ret += dfs(pos-1, la&& (i == na), lb&&(j == nb),And && ((i&j) == nand),Xor && ((i^j)==nxor));
        }
    }
    return dp[pos][la][lb][And][Xor] = ret;
    //return ret;
}
int main(){
    int t ;
    cin >> t;
    while(t--){
        cin >> A >> B >> C;
        memset(dp, -1, sizeof(dp));
        ll ans = dfs(30,1,1,1,1);
        ans -= max(0ll, A - C + 1);
        ans -= max(0ll, B - C + 1);
        cout << (A*B-ans) << endl;
    }
}
