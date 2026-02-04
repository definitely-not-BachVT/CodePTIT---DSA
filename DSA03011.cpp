#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            long long x;
            cin >> x;

            pq.push(x);
        }

        while (pq.size() > 1)
        {
            long long tp1 = pq.top();
            pq.pop();
            long long tp2 = pq.top();
            pq.pop();

            sum = (sum + tp1 + tp2) % MOD;
            pq.push((tp1 + tp2) % MOD);
        }

        cout << sum << "\n";
    }
}