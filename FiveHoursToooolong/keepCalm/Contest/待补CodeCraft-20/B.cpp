// She is Pretty pretty!
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 100;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int len = 1;
        string ans = s;
        for (int i = 1; i <= n - 1; i++)
        {
            string qian = s.substr(0, i);
            string hou = s.substr(i);
            if ((n - i) & 1)
                reverse(qian.begin(), qian.end());
            hou += qian;
            if (hou < ans)
            {
                ans = hou;
                len = i + 1;
            }
        }
        cout << ans << endl
             << len << endl;
    }
    return 0;
}