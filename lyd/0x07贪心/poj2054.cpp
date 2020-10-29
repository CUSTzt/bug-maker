#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010;

int n, root;
struct Node {
    int p, s, v;
    double avg;
} nodes[N];
int find() {
    double avg = 0;
    int res = -1;
    for (int i = 1; i <= n; i++)
        if (i != root && nodes[i].avg > avg) {
            avg = nodes[i].avg;
            res = i;
        }
    return res;
}
int main() {
    cin >> n >> root;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].v;
        nodes[i].avg = nodes[i].v;
        nodes[i].s = 1;
        ans += nodes[i].v;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        nodes[b].p = a;
    }
    for (int i = 0; i < n - 1; i++) {
        int p = find();
        int father = nodes[p].p;
        ans += nodes[p].v * nodes[father].s;
        nodes[p].avg = -1;
        for (int j = 1; j <= n; j++)
            if (nodes[j].p == p) nodes[j].p = father;
        nodes[father].v += nodes[p].v;
        nodes[father].s += nodes[p].s;
        nodes[father].avg = (double)nodes[father].v / nodes[father].s;
    }
    cout << ans << endl;
    return 0;
}
