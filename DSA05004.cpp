#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> tail;
    for (int i = 0; i < n; ++i)
    {
        vector<long long>::iterator it = lower_bound(tail.begin(), tail.end(), a[i]);
        if (it == tail.end())
            tail.push_back(a[i]);
        else
            *it = a[i];
    }

    cout << tail.size();
}