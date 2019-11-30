 /****************************************************************
 # @Author:      miniLCT
 # @DateTime: 2019年11月20日 星期三 15时57分02秒
 # @Description: You build it. You run it 
 # @More: Once lots of AC, try Brute-force,dynamic programming 
 ****************************************************************/
/*#include<bits/stdc++.h>

using namespace std;
#define close std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define eps 1e-8
typedef long long ll;
const int maxn = 2e4+10;
const int INF = 1e9;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
ll mod = 1e9+7;
struct Edge{
    int a,b;
}e[maxn];
char c;
int n, m , fa[maxn],  head[maxn], tot, deg[maxn],ans;
void add_edge(int from, int to){
    e[tot] = (Edge){to, head[from]};
    head[from] = tot++;
    deg[to]++;
}
int find(int x){
    if(fa[x] == -1)return x;
    return fa[x] = find(fa[x]);
}
int topo(){
    queue <int >q;
    int f_num = 0;
    int cnt = 0;
    bool isok = true;
    for(int i = 0; i < n;i++){
        if(find(i) == i){
            f_num++;
            if(deg[i] == 0)q.push(i);
        }
    }
    while(!q.empty()){
        if(q.size() > 1)isok = false;
        int u = q.front();q.pop();
        cnt++;
        for(int ii = head[u]; ii != -1; ii = e[ii].b ){
            int kk = e[ii].a;
            if(--deg[find(kk)] == 0)q.push(find(kk));
        }
    }
    if(cnt < f_num)return -1;
    if(isok)return 1;
    return 0;
}
void init(){
    ans = 0;
    memset(fa, -1 , sizeof fa);
    memset(head, -1 , sizeof head);
    memset(deg, 0 , sizeof deg);
    tot = 0;
    for(int i = 0; i < m;i++){
            scanf("%d %c %d", &e[i].a, &c, &e[i].b);
    if(c == '='){
            //int u = e[i].a,v =e[i].b;
               int u = find(e[i].a),v=find(e[i].b);
            if(u!= v)fa[e[i].a] = e[i].b;
        }
    else {
        if(find(e[i].a)==find(e[i].b)){
            ans = -1;
        }
        if(c=='<')add_edge(find(e[i].b), find(e[i].a));
        else  add_edge(find(e[i].a),find(e[i].b));
        }
    }
}
int main(){
    //close;
    while(~scanf("%d%d",&n , &m)){
        init();
        if(ans == 0)ans = topo();
        if(ans == -1)cout << "CONFLICT" << endl;
        else if(ans == 0)cout << "UNCERTAIN" << endl;
        else cout << "OK" << endl;
    }
    return 0;
}
*/
/*****************************************************************
 stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?), set tle
  * do smth instead of nothing and stay organized
*****************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
//others
using namespace std;

int vis[10005],head[10005],cnt,fa[10005],st[10005];

struct p{
    int a,b;
    char op[5];
}kk[10005];

struct node{
    int s,t,nxt;
}e[1000005];

void add(int s,int t){
    e[cnt].s=s;e[cnt].t=t;e[cnt].nxt=head[s];head[s]=cnt++;
}

void INIT(){
    cnt=0;
    memset(head,-1,sizeof(head));
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}


int dfs(int u){
    vis[u]=-1;
    for(int i=head[u];i!=-1;i=e[i].nxt){
        int v=e[i].t;
        if(vis[v]<0)return 0;
        else if(!vis[v] && !dfs(v))return 0;
    }
    vis[u]=1;
    return 1;
}

int OK(int n){
    for(int i=0;i<n;i++){
        if(!vis[i] && !st[i] && !dfs(i))return 0;
    }
    return 1;
}

int IN[10005];

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        INIT();
        for(int i=0;i<n;i++)fa[i]=i;
        memset(IN,0,sizeof(IN));
        memset(st,0,sizeof(st));
        int flag=1;
        for(int i=0;i<m;i++){
            scanf("%d%s%d",&kk[i].a,kk[i].op,&kk[i].b);
            if(kk[i].op[0]=='='){
                int pa=find(kk[i].a);
                int pb=find(kk[i].b);
                if(pa!=pb){
                    fa[pa]=pb;
                    st[pa]=1;
                }
            }
            else{
                int pa=find(kk[i].a);
                int pb=find(kk[i].b);
                if(pa==pb)flag=0;
            }
        }
        if(!flag)puts("CONFLICT");//所给信息矛盾
        else{
            for(int i=0;i<m;i++){
                if(kk[i].op[0]=='>'){
                    add(find(kk[i].a),find(kk[i].b));
                    IN[find(kk[i].b)]++;
                }
                else if(kk[i].op[0]=='<'){
                    add(find(kk[i].b),find(kk[i].a));
                    IN[find(kk[i].a)]++;
                }
            }
            memset(vis,0,sizeof(vis));
            if(!OK(n))puts("CONFLICT");//有环
            else{
                queue <int> q;
                for(int i=0;i<n;i++){
                    if(!st[i] && !IN[i])
                        q.push(i);
                }
                int flag=1;
                while(!q.empty()){
                    if(q.size()>1){
                        flag=0;
                        break;
                    }
                    int u=q.front();
                    q.pop();
                    for(int i=head[u];i!=-1;i=e[i].nxt){
                        int v=e[i].t;
                        IN[v]--;
                        if(!IN[v])q.push(v);
                    }
                }
                if(!flag)puts("UNCERTAIN");//拓扑结构一层多于一个点，有多种情况
                else puts("OK");
            }
        }
    }
    return 0;
}
