#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> res;
void sinh(string x, int idx, char last)
{
    if (idx == n)
    {
        res.push_back(x);
        return;
    }

    if (last == 'H')
        sinh(x + "A", idx + 1, 'A');
    else
    {
        sinh(x + "A", idx + 1, 'A');
        sinh(x + "H", idx + 1, 'H');
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        string x = "H";

        sinh(x, 1, 'H');
        sort(res.begin(), res.end());

        for (string x : res)
            if (x[n - 1] == 'A')
                cout << x << "\n";

        res.clear();
    }
}