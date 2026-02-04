#include <bits/stdc++.h>
using namespace std;

bool nguyenam(char c)
{
    if (c == 'U' || c == 'E' || c == 'O' || c == 'A' || c == 'I')
        return true;
    return false;
}

int n;
bool ok(vector<char> &a)
{
    for (int i = 1; i < n - 1; ++i)
        if (nguyenam(a[i]) && !nguyenam(a[i - 1]) && !nguyenam(a[i + 1]))
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char c;
    cin >> c;

    n = c - 'A' + 1;
    vector<char> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = (char)('A' + i);

    do
    {
        if (ok(a))
        {
            for (int i = 0; i < n; ++i)
                cout << a[i];
            cout << "\n";
        }
    } while (next_permutation(a.begin(), a.end()));
}