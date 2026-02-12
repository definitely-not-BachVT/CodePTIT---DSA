#include <bits/stdc++.h>
using namespace std;

long long step[100003];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 100003; ++i)
            step[i] = INT_MAX;

        long long n;
        cin >> n;

        queue<long long> q;
        q.push(n);
        step[n] = 0;

        while (!q.empty())
        {
            long long tp = q.front();
            q.pop();

            if (tp == 1)
                break;

            if (tp % 3 == 0)
            {
                if (step[tp / 3] == INT_MAX)
                    q.push(tp / 3);
                step[tp / 3] = min(step[tp / 3], step[tp] + 1);
            }

            if (tp % 2 == 0)
            {
                if (step[tp / 2] == INT_MAX)
                    q.push(tp / 2);
                step[tp / 2] = min(step[tp / 2], step[tp] + 1);
            }

            if (step[tp - 1] == INT_MAX)
                q.push(tp - 1);
            step[tp - 1] = min(step[tp - 1], step[tp] + 1);
        }

        cout << step[1] << "\n";
    }
}
i /