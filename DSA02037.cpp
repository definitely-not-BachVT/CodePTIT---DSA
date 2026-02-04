#include <bits/stdc++.h>
using namespace std;

bool snt(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n < 2 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int n;
vector<string> np;
void sinh(string x, int idx)
{
    if (idx == n)
    {
        np.push_back(x);
        return;
    }

    sinh(x + "0", idx + 1);
    sinh(x + "1", idx + 1);
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
        np.clear();

        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());

        sinh("", 0);
        for (string x : np)
        {
            long long sum = 0;
            for (int i = 0; i < n; ++i)
                if (x[i] == '1')
                    sum += a[i];

            if (snt(sum))
            {
                for (int i = 0; i < n; ++i)
                    if (x[i] == '1')
                        cout << a[i] << " ";
                cout << "\n";
            }
        }
    }
}