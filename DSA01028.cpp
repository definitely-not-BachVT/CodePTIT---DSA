#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;

        if (!mp[tmp]++)
            a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    n = a.size();
    vector<int> p(n, 0);
    for (int i = 0; i < k; ++i)
        p[i] = 1;

    do
    {
        for (int i = 0; i < n; ++i)
            if (p[i])
                cout << a[i] << " ";
        cout << "\n";
    } while (prev_permutation(p.begin(), p.end()));
}