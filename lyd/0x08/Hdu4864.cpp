#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
    bool operator<(const node& r) const {
        if (x != r.x) return x > r.x;
        else return y > r.y;
    }
} mach[100000 + 100], task[100000 + 100];
int N, M;  // machine task
int s[150], x, y;
int main() {
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &x, &y);
            mach[i] = (node){x, y};
        }
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &x, &y);
            task[i] = (node){x, y};
        }
        sort(mach, mach + N);
        sort(task, task + M);
        int num = 0;  //匹配的数量
        long long money = 0;
        memset(s, 0, sizeof(s));
        int j = 0;
        for (int i = 0; i < M; i++) {
            while (j < N && mach[j].x >= task[i].x) {
                s[mach[j].y]++;
                j++;
            }
            for (int k = task[i].y; k <= 100; k++)
                if (s[k] > 0) {
                    num++; money += 500 * task[i].x + 2 * task[i].y;
                    s[k]--; break;
                }
        }
        printf("%d %lld\n", num, money);
    }
    return 0;
}