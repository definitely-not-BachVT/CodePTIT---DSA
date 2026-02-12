#include <bits/stdc++.h>
using namespace std;
;

long long mx = -LLONG_MAX, n = 8;
vector<vector<long long>> a(8, vector<long long>(8, 0));
bool col[20], row[20], diag1[20], diag2[20];

void Try(int row, long long curr)
{
    if (row == 8)
    {
        mx = max(mx, curr);
        return;
    }

    for (int c = 0; c < n; ++c)
    {
        if (!col[c] && !diag1[n - c + row] && !diag2[row + c])
        {
            col[c] = diag1[n - c + row] = diag2[row + c] = true;
            curr += a[row][c];
            Try(row + 1, curr);
            curr -= a[row][c];
            col[c] = diag1[n - c + row] = diag2[row + c] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        mx = 0;
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(diag1, false, sizeof(diag1));
        memset(diag2, false, sizeof(diag2));

        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> a[i][j];

        Try(0, 0);
        cout << "Test " << i << ": ";
        cout << mx << "\n";
    }
}
