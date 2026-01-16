#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> res;
int ans = 0;
bool check(string s)
{
    int cnt = 0;
    for (int i = 0; i <= n - k; ++i)
    {
        bool ok = true;
        for (int j = 0; j < k; ++j)
            if (s[i + j] == 'B')
            {
                ok = false;
                break;
            }

        if (ok)
            ++cnt;
    }

    if (cnt == 1)
        return true;
    return false;
}

void sinh(string x, int idx)
{
    if (idx == n)
    {
        if (check(x))
            res.push_back(x);
        return;
    }

    sinh(x + "A", idx + 1);
    sinh(x + "B", idx + 1);
}

int main()
{
    cin >> n >> k;
    string x = "";

    sinh(x, 0);

    cout << res.size() << "\n";
    for (string x : res)
        cout << x << "\n";
}