#include <bits/stdc++.h>
using namespace std;

long long toLL(string x)
{
    long long ans = 0;
    for (char y : x)
        ans = ans * 2 + y - '0';
    return ans;
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
        string a, b;
        cin >> a >> b;

        cout << toLL(a) * toLL(b) << "\n";
    }
}