#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int a;
        cin >> a;

        queue<long long> q;
        long long last;

        while (a--)
        {
            int opt;
            cin >> opt;

            if (opt == 1)
            {
                cout << q.size() << "\n";
                continue;
            }

            if (opt == 2)
            {
                if (q.empty())
                    cout << "YES\n";
                else
                    cout << "NO\n";
                continue;
            }

            if (opt == 3)
            {
                long long x;
                cin >> x;

                last = x;
                q.push(x);
                continue;
            }

            if (opt == 4)
            {
                if (!q.empty())
                    q.pop();
                continue;
            }

            if (opt == 5)
            {
                if (q.empty())
                    cout << "-1\n";
                else
                    cout << q.front() << "\n";
                continue;
            }

            if (opt == 6)
            {
                if (q.empty())
                    cout << "-1\n";
                else
                    cout << last << "\n";

                continue;
            }
        }
    }
}