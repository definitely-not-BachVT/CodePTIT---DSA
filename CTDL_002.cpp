#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long sum = 0;
vector<vector<int>> res;
vector<int> p;
void Try(vector<long long> &a, int idx)
{
    if (sum > k)
        return;

    // Stop
    if (sum == k)
    {
        res.push_back(p);
        return;
    }

    if (idx == n)
        return;

    // Pick
    sum += a[idx];
    p.push_back(idx);
    Try(a, idx + 1);

    // Unpick
    sum -= a[idx];
    p.pop_back();
    Try(a, idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    Try(a, 0);

    int cnt = 0;

    reverse(res.begin(), res.end());
    for (auto x : res)
    {
        for (auto idx : x)
            cout << a[idx] << " ";
        cout << "\n";
        ++cnt;
    }

    cout << cnt;
}