#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> res;
void Try(string x, int idx, int size)
{
    if (size == k)
    {
        res.push_back(x);
        return;
    }

    for (int i = idx; i <= n; ++i)
    {
        string ad = "";
        char c = (char)('A' + i);
        ad.push_back(c);

        Try(x + ad, i, size + 1);
    }
}

int main()
{

    char c;

    cin >> c >> k;
    n = c - 'A';

    string x = "";
    Try(x, 0, 0);

    for (string y : res)
        cout << y << "\n";
}