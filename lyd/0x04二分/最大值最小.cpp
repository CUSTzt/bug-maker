bool isok(int sz) {
    int group = 1, rest = sz;
    for (int i = 1; i <= n; i++) {
        if (rest > = a[i])
            rest -= a[i];
        else
            group++, rest = sz - a[i];
    }
    return group <= m;
}
int main() {
    int l = 0, r = INF;  // l = 0 , l= 1很迷幻？
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (isok(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}