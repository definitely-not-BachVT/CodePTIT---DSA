#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> curr;
vector<vector<string>> res;
void Try(vector<string> &a, int idx, int size)
{
    if (size == k)
    {
        res.push_back(curr);
        return;
    }

    if (idx >= n)
        return;

    // pick
    curr.push_back(a[idx]);
    Try(a, idx + 1, size + 1);

    // bo pick
    curr.pop_back();
    Try(a, idx + 1, size);
}

int main()
{

    cin >> n >> k;

    map<string, int> mp;
    vector<string> a;

    for (int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;

        if (!mp[tmp]++)
            a.push_back(tmp);
    }
    n = a.size();

    sort(a.begin(), a.end());
    // for (auto x : a)
    //     cout << x << " ";
    Try(a, 0, 0);

    for (auto x : res)
    {
        for (string y : x)
            cout << y << " ";
        cout << "\n";
    }
}