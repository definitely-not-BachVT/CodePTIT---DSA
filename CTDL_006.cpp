#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> a;
    map<long long, int> mp;

    long long tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (mp[tmp]++ == 0)
            a.push_back(tmp);
    }

    for (long long x : a)
        cout << x << " ";
}