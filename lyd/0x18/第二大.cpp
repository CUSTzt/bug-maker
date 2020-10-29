#include <bits/stdc++.h>
using namespace std;
int s[1005][1005];
char q[1005];
int maxn1, maxn2;
void calc1(int ans) {
    if (ans > maxn1) {
        maxn2 = maxn1; maxn1 = ans;
    } else if (ans > maxn2) maxn2 = ans;
}
void calc(int x, int y) {
    calc1(x * y); calc1(x * (y - 1)); calc1((x - 1) * y);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", q);
        for (int j = 1; j <= m; j++) {
            s[i][j] = q[j - 1] - '0';
            if (s[i][j] == 1) s[i][j] = s[i - 1][j] + 1;
        }
    }
    /*
    for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                    printf("%d%c", s[i][j], j == m ? '\n' : ' ');
    */
    for (int i = 1; i <= n; i++) {
        stack<int> st;
        st.push(0);
        for (int j = 1; j <= m + 1; j++) {
            while (s[i][st.top()] > s[i][j]) {
                int index = st.top();
                st.pop();
                calc(j - 1 - st.top(), s[i][index]);
            }
            st.push(j);
        }
    }
    printf("%d", maxn2);
}