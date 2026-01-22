#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    queue<long long> q;

    while (t--)
    {
        string opt;
        cin >> opt;

        if (opt == "PUSH")
        {
            long long x;
            cin >> x;

            q.push(x);
            continue;
        }

        if (opt == "PRINTFRONT")
        {
            if (q.empty())
                cout << "NONE\n";
            else
                cout << q.front() << "\n";
        }

        if (opt == "POP")
        {
            if (!q.empty())
                q.pop();
            continue;
        }
    }
}