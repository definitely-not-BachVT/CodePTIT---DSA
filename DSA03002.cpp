#include <bits/stdc++.h>
using namespace std;

long long mx(string a, string b)
{
    int size = a.size();
    for (int i = 0; i < size; ++i)
        if (a[i] == '5')
            a[i] = '6';

    size = b.size();
    for (int i = 0; i < size; ++i)
        if (b[i] == '5')
            b[i] = '6';

    return stoll(a) + stoll(b);
}

long long mi(string a, string b)
{
    int size = a.size();
    for (int i = 0; i < size; ++i)
        if (a[i] == '6')
            a[i] = '5';

    size = b.size();
    for (int i = 0; i < size; ++i)
        if (b[i] == '6')
            b[i] = '5';

    return stoll(a) + stoll(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    cout << mi(a, b) << " " << mx(a, b);
}