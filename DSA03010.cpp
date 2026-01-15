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
        int n;
        cin >> n;

        long long sum = 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; ++i)
        {
            long long tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        while (pq.size() != 1)
        {
            long long tp1 = pq.top();
            pq.pop();

            long long tp2 = pq.top();
            pq.pop();

            long long su = tp1 + tp2;
            pq.push(su);

            sum += su;
        }

        cout << sum << "\n";
    }
}