#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<long long> a, vector<long long> b)
{
    int size = min(a.size(), b.size());
    for (int i = 0; i < size; ++i)
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;

    return a.size() < b.size();
}

int n;
vector<vector<long long>> res;
vector<long long> curr;

void Try(vector<long long> a, int idx, long long sum)
{
    if (sum % 2)
    {
        res.push_back(curr);
    }

    if (idx == n)
        return;

    curr.push_back(a[idx]);
    Try(a, idx + 1, sum + a[idx]);

    curr.pop_back();
    Try(a, idx + 1, sum);
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
        curr.clear();
        res.clear();

        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end(), greater<int>());
        Try(a, 0, 0);

        sort(res.begin(), res.end(), cmp);
        res.erase(unique(res.begin(), res.end()), res.end());
        for (vector<long long> x : res)
        {
            for (long long y : x)
                cout << y << " ";
            cout << "\n";
        }
    }
}