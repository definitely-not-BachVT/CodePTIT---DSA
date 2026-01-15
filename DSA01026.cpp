#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> res;
void sinh(string x, int size)
{
    if (size == n)
    {
        res.push_back(x);
        return;
    }

    sinh(x + "6", size + 1);
    sinh(x + "8", size + 1);
}

bool check(string s)
{
    if (s[n - 1] == '8')
        return false;

    for (int i = 0; i < n - 1; ++i)
        if (s[i] == '8' && s[i + 1] == '8')
            return false;

    for (int i = 0; i < n - 3; ++i)
        if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6' && s[i + 3] == '6')
            return false;

    return true;
}

int main()
{
    cin >> n;
    string x = "8";

    sinh(x, 1);
    sort(res.begin(), res.end());
    for (string x : res)
        if (check(x))
            cout << x << "\n";
}