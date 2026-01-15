#include <bits/stdc++.h>
using namespace std;

long long n;
vector<vector<long long>> res;
vector<long long> curr;
void Try(vector<long long> &a, int idx)
{
    if (idx == n)
    {
        if (!curr.empty() && curr.size() != 1)
            res.push_back(curr);
        return;
    }

    if (curr.empty())
    {
        curr.push_back(a[idx]);
        Try(a, idx + 1);
        curr.pop_back();
        Try(a, idx + 1);
    }
    else
    {
        if (a[idx] > curr.back())
        {
            curr.push_back(a[idx]);
            Try(a, idx + 1);
            curr.pop_back();
            Try(a, idx + 1);
        }
        else
            Try(a, idx + 1);
    }
}

int main()
{
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    Try(a, 0);

    set<string> ans;
    for (auto x : res)
    {
        string tmp;
        for (auto y : x)
            tmp += to_string(y) + " ";
        ans.insert(tmp);
    }

    for (string x : ans)
        cout << x << "\n";
}