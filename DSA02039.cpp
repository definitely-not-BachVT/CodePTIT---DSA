#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> curr;
vector<string> res;

void Try(int idx, int lst)
{
    if (idx == 0)
    {
        string tmp = "";
        int sz = curr.size();

        tmp = tmp + "(";

        for (int i = 0; i < sz - 1; ++i)
            tmp = tmp + to_string(curr[i]) + " ";
        tmp = tmp + to_string(curr[sz - 1]) + ") ";

        res.push_back(tmp);
        return;
    }

    for (int i = min(idx, lst); i >= 1; --i)
    {
        curr.push_back(i);
        Try(idx - i, i);
        curr.pop_back();
    }
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
        res.clear();
        curr.clear();
        cin >> n;
        Try(n, n);

        cout << res.size() << "\n";
        for (string x : res)
            cout << x << " ";
        cout << "\n";
    }
}