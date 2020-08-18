#include <bits/stdc++.h>
using namespace std;
set<int> A[30], B[30][30], tmp;
// A 模拟题目中的大写字母(全局指针)
// B 模拟成员变量用
// tmp 临时变量 用于操作4 因为操作4操作的是对象的所有成员变量的对象
string a[300], b[300], c[300];  //读入用
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    int t = 500;
    while (t--) {  //执行多次
        int x, y, z;
        for (int i = 0; i < n; i++) {
            if (a[i].size() == 1 && c[i].size() == 1) {  //操作属于类型1或者类型2
                x = a[i][0] - 'A';
                if (c[i][0] >= 'a' && c[i][0] <= 'z') {  //类型1 "A=x" c存储的是对象
                    y = c[i][0] - 'a';
                    A[x].insert(y);
                } else {  //类型2 "A=B" c存储的是指针c[i][0]
                    y = c[i][0] - 'A';  //所以把c[i][0]的对象全部加入到a[i][0]
                    if (x != y) A[x].insert(A[y].begin(), A[y].end());
                }
            } else if (a[i].size() == 1 &&
                       c[i].size() == 3) {  //类型4--最难理解的一个
                                            /*
                                            操作 "A = B.f"
                                            for every object o accessible via B, 找出的所有可达对象
                                            A can point to every object accessible via the member variable f
                                            of o                             这些可达对象的成员变量对象的对象 全部加入
                                            */
                x = a[i][0] - 'A';
                y = c[i][0] - 'A';
                z = c[i][2] - 'a';
                tmp.clear();
                for (auto it : A[y])
                    tmp.insert(B[it][z].begin(), B[it][z].end());
                A[x].insert(tmp.begin(), tmp.end());
            } else {  //类型3 A.f = B
                x = a[i][0] - 'A';
                y = c[i][0] - 'A';
                z = a[i][2] - 'a';
                for (auto it : A[x]) B[it][z].insert(A[y].begin(), A[y].end());
            }
        }
    }
    for (int i = 0; i < 26; i++) {  //输出结果
        printf("%c: ", i + 'A');
        for (auto it : A[i]) printf("%c", it + 'a');
        printf("\n");
    }
}