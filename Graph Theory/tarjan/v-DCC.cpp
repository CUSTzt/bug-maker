// She is Pretty pretty!
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 100, M = 5e5 + 10;
int head[N], ver[M >> 1], Next[M >> 1];
int dfn[N], low[N], Size[N], stack[N], cut[N];
int n, m, tot, num, top, root, cnt;
void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
vector<int> dcc[N];  // dcc[i] 保存了编号为i的v-DCC中的所有节点
void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    stack[++top] = x;
    if (x == root && head[x] == 0) {  // 孤立点
        dcc[++cnt].push_back(x);
        return;
    }
    int fl = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[y];
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                fl++;
                if (x != root || fl > 1) cut[x] = true;
                cnt++;
                int z;
                do{
                    z = stack[top--];
                    dcc[cnt].push_back(z);
                }while(z!=y);
                dcc[cnt].push_back(x);
            }
        }else low[x] = min(low[x], dfn[y]);
    }
}
int main() {
    //加在求割点程序中
    for (int i = 1; i <= cnt; i++) {
        printf("v-DCC #%d:", i);
        for (int j = 0; j < dcc[i].size(); j++) {
            printf(" %d", dcc[i][j]);
        }
        puts("");
    }


    //v-DCC缩点
    return 0;
}