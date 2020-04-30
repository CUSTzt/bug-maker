#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q2;  //小根堆 ，存较大的一半的数
priority_queue<int> q1;  //大根堆 ，存较小的一半的数
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();  //优先队列没有clear函数，要一个一个弹出
        int m, n;
        scanf("%d %d", &m, &n);
        printf("%d %d\n", m, (n + 1) / 2);
        int x;
        scanf("%d", &x);
        q1.push(x);
        printf("%d ", x);
        for (int i = 2; i <= n; i++) {
            int x;
            scanf("%d", &x);

            if (x <= q1.top())
                q1.push(
                    x);  //如果当前值比大根堆堆顶小，说明在小的这二分之一，塞进大根堆
            else
                q2.push(x);

            int num1 = q1.size();
            int num2 = q2.size();
            if (num1 - num2 > 1)  //大根堆里面元素多了，把堆顶拿出来塞近小根堆
            {
                q2.push(q1.top());
                q1.pop();
            } else if (num2 - num1 >
                       1)  //小根堆里面元素多了，把堆顶拿出来塞近大根堆
            {
                q1.push(q2.top());
                q2.pop();
            }

            if (i % 2 == 1)  //目前的元素个数是奇数
            {
                num1 = q1.size();
                num2 = q2.size();
                if (num1 > num2)
                    printf("%d ", q1.top());  //中位数在大根堆
                else
                    printf("%d ", q2.top());  //中位数在小根堆
                if (i % 20 == 19 && i != n) printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}