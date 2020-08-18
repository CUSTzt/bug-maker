// She is Pretty pretty!
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6+100;
int n, len , k, to[N];
std::vector<int> v[N]; // 每个块用一个vector存
void Insert(int x, int num){
    int now = 0;
    int id;
    for(id = 1; id; id = to[id]){ // 遍历所有的块找到需要插到的位置
        now += v[id].size();
        if(now >= x) break;
    }
    now -= v[id].size();
    now = x - now;
    v[id].insert(v[id].begin()+now-1,num);
}
int Query(int x){
    int now = 0, id;
    for(id = 1; id; id = to[id]){ // 遍历所有的块找到查询位置
        now += v[id].size();
        if(now >= x) break;
    }
    now -= v[id].size();
    now = x - now;
    return v[id][now-1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    len = sqrt(n);
    k = (n-1)/len+1;
    int zz;
    for(int i = 1; i <= n; i++){
        cin >> zz; int pos = (i - 1) / len + 1;
        v[pos].emplace_back(zz); 
    }
    for(int i = 1; i <= k-1 ;i++) to[i] = i + 1; // 链表存储，方便优化
    int op , l , r, c;
    for(int i = 1; i <= n; i++){
        cin >> op >> l >> r >> c;
        if(!op){
            Insert(l , r);
        }else {
            cout << Query(r) << endl;
        }
        
    }
    return 0;
}