// Đề bài cho giới hạn 10^3 nhưng test thì có giới hạn cao hơn.
// Nên khai báo to hơn cho chắc

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> mark(100003, 0);

        int mx = -INT_MAX, mi = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            mi = min(mi, a[i]);

            mark[a[i]] = 1;
        }

        int cnt = 0;
        for (int i = mi; i <= mx; ++i)
            if (mark[i] == 0)
                ++cnt;

        cout << cnt << "\n";
    }
}