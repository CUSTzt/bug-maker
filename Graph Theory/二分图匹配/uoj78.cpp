#include<bits/stdc++.h>

using namespace std;

int nr, nl , m , e, tot;
const int SIZE = 250010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}
int vis[SIZE], match[SIZE];
bool find(int x){
    for(int i = head[x], y; i ; i = Next[i]) if(!vis[ y = ver[i]]){
        vis[y] = 1;
        if(!match[y] || find(match[y])){
            match[y] = x;  return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> nl >> nr >> m;
    for(int i = 1; i <= m; i ++){
        int a , b;
        cin >> a >> b;
        add(b , a);
    }
    int ans = 0;
    for(int i = 1; i <= nr; i++){
        memset(vis , 0 , sizeof vis);
        if(find(i)) ans++;
    }
    cout << ans << endl;
    for(int i = 1; i <= nl; i++){
        if(match[i]) cout << match[i] << ' ';
        else cout << "0 ";
    }
}