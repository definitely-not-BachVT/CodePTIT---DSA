#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<string> res;

    {
        string tmp = "Buoc 0: " + to_string(a[0]);
        res.push_back(tmp);
    }

    for (int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        string tmp = "Buoc " + to_string(i) + ": ";
        for (int k = 0; k <= i; ++k)
            tmp += to_string(a[k]) + " ";
        res.push_back(tmp);
    }

    for (int i = n - 1; i >= 0; --i)
        cout << res[i] << "\n";
}
