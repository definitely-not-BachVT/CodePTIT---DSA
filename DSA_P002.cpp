#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;

    int idx = 0;
    do
    {
        cout << ++idx << ": ";
        for (int x : a)
            cout << x << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
}