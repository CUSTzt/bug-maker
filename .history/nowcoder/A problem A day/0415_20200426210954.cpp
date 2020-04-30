#include<iostream>
#include<algorithm>
#define MAXN 100005
using namespace std;

int sum[MAXN];
int arr[MAXN];
int pos[MAXN];
int main() {

    int N,K;
    cin >> N;

    for (size_t i = 1; i <=N; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    cin >> K;
    fill(pos, pos + MAXN, INT_MAX);
    int maxL = 0;
    for (int i = 1; i <=N; i++) {
        int m = sum[i] % K;
        if (m == 0)
            maxL = max(maxL, i);
        if (pos[m] != INT_MAX) {
            maxL = max(maxL, i - pos[m]);
        }
        pos[m] = min(pos[m], i);
    }
    cout << maxL << endl;
    return 0;
}