#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    do
    {
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
}