#include <bits/stdc++.h>
using namespace std;

long long n, x;
bool cmp(long long a, long long b)
{
    if (abs(x - a) < abs(x - b))
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            v[i].first = abs(a[i] - k);
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            cout << a[v[i].second] << " ";
        cout << endl;
    }
}