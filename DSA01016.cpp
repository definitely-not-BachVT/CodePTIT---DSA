#include <bits/stdc++.h>
using namespace std;

vector<string> res;
vector<int> a;

void sinh(int idx, int last)
{
    if (idx == 0)
    {
        string tmp = "(";
        int size = a.size();

        for (int i = 0; i < size - 1; ++i)
            tmp = tmp + to_string(a[i]) + " ";
        tmp = tmp + to_string(a[size - 1]) + ")";

        res.push_back(tmp);

        return;
    }

    for (int i = min(idx, last); i > 0; --i)
    {
        // Pick
        a.push_back(i);
        sinh(idx - i, i);

        // Unpick
        a.pop_back();
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
        a.clear();
        res.clear();

        int n;
        cin >> n;

        sinh(n, n);

        for (string x : res)
            cout << x << " ";
        cout << "\n";
    }
}