#include <algorithm>
#include <cmath>  // 计算距离时需要用到 sqrt 函数
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 200005;
const double INF = 1e15;

int n;
struct point  // 结构体存所有点
{
    double x, y; bool type; // 存每个点的类型
    bool operator<(const point &t) const {
        return x < t.x;
    }
} points[N], tmp[N];  // points 存输入的每个点，tmp 存分治时对于每个点要处理的点
double get_dist(point a, point b)  // 返回点 a 和点 b 的直径距离
{
    if (a.type == b.type)
        return INF;  // 如果这两个点的类型不同，那么为了避免更新答案，返回正无穷
    double dx = a.x - b.x, dy = a.y - b.y;  // 计算出这两个点横纵坐标的差值
    return sqrt(dx * dx + dy * dy);  // 返回这两个点的平面距离
}

double dfs(int l, int r) {
    if (l == r)
        return INF;  // 如果剩下区域只有一个点，那么为了避免更新答案，返回正无穷
    int mid = l + r >> 1;  // 找到剩下区域内中间的点的位置。
    double mid_x =
        points[mid]
            .x;  // 取出该点的 x 坐标，与该坐标距离超过 ans 的点不计入考虑。
    double ans =
        min(dfs(l, mid), dfs(mid + 1, r));  // 分治计算出上述未被更新的 ans

    // 先将 points 中的 [l, mid] 和 [mid + 1, r] 两段进行按 y 轴坐标进行按序归并
    // 注意这里一定要归并，后面对于每个点我们才能快速找出对应的（至多） 6
    // 个点，以保证总时间复杂度是 O(n log n)
    int i = l, j = mid + 1, cnt = 0;
    while (i <= mid && j <= r)
        if (points[i].y < points[j].y)
            tmp[cnt++] = points[i++];
        else
            tmp[cnt++] = points[j++];
    while (i <= mid) tmp[cnt++] = points[i++];
    while (j <= r) tmp[cnt++] = points[j++];
    for (i = l; i <= r; i++) points[i] = tmp[i - l];

    // 找到所有在 [mid_x - ans, mid_x + ans] 中的点，存入 tmp
    cnt = 0;
    for (i = l; i <= r; i++)
        if (points[i].x >= mid_x - ans &&
            points[i].x <= mid_x + ans)  // 如果说该点距离 mid_x 的距离小于
                                         // ans，那么需要考虑该点
            tmp[cnt++] = points[i];
    // 下面第二层循环中，有 tmp[i].y - tmp[j].y <= ans
    // 这个判断，才能保证我们对于每个点最多只考虑六个点
    // 这样在每层递归中，就可以保证时间复杂度是线性的，否则时间复杂度是平方级别的
    for (i = 0; i < cnt; i++)  // 处理所有 tmp 中的点
        for (j = i - 1; ~j && tmp[i].y - tmp[j].y <= ans; j--)
            ans = min(ans, get_dist(tmp[i], tmp[j]));  // 更新 ans
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &points[i].x,&points[i].y);  
            points[i].type = false;  // 核电站的 type 制成 false
        }
        for (int i = n; i < n << 1; i++) {
            scanf("%lf %lf", &points[i].x, &points[i].y);  // 读入所有特工的坐标
            points[i].type = true;  // 特工的 type 制成 true
        }
        sort(points, points + (n << 1));  // 将所有点按 x 坐标排序
        printf("%.3lf\n", dfs(0, (n << 1) - 1));  // 分治函数的返回值即为答案
    }
    return 0;
}
