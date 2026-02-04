#include <bits/stdc++.h>
using namespace std;

int main()
{
    int e;
    cin >> e;

    vector<vector<long long>> a(e + 3, vector<long long>(e + 3, 0));

    int idx = 1;
    while (idx <= e)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        while (ss >> s)
        {
            long long y = stoll(s);
            a[idx - 1][y] = 1;
            a[y][idx - 1] = 1;
        }

        ++idx;
    }

    for (int i = 1; i <= e; ++i)
    {
        for (int j = 1; j <= e; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}