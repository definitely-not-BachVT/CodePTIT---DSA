#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> res;
void sinh(string s, int idx)
{
    if (idx == n)
    {
        res.push_back(s);
        return;
    }

    sinh(s + "A", idx + 1);
    sinh(s + "B", idx + 1);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        string s = "";
        sinh(s, 0);

        for (string x : res)
            cout << x << " ";
        cout << "\n";

        res.clear();
    }
}