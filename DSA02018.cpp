#include <bits/stdc++.h>
using namespace std;

long long Try(long long a, long long b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    return a * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        vector<long long> a(5);
        for (int i = 0; i < 5; ++i)
            cin >> a[i];

        bool found = false;
        sort(a.begin(), a.end());

        char ops[3] = {'+', '-', '*'};

        do
        {
            for (char o1 : ops)
                for (char o2 : ops)
                    for (char o3 : ops)
                        for (char o4 : ops)
                        {
                            long long val = a[0];
                            val = Try(val, a[1], o1);
                            val = Try(val, a[2], o2);
                            val = Try(val, a[3], o3);
                            val = Try(val, a[4], o4);

                            if (val == 23)
                            {
                                found = true;
                                break;
                            }
                        }
            if (found)
                break;
        } while (next_permutation(a.begin(), a.end()));

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
