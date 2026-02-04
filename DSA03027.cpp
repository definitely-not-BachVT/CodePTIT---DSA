#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    long long sum = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
            sum += 2 * a[i];
    }
    cout << sum;
}