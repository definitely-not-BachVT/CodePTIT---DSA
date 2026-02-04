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
        int k;
        cin >> k;

        string s;
        cin >> s;

        vector<int> mark(26, 0);
        for (char c : s)
            mark[c - 'A']++;

        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < 26; ++i)
            pq.push(mark[i]);

        while (k--)
        {
            int tp = pq.top();
            pq.pop();

            --tp;
            pq.push(tp);
        }

        long long sum = 0;
        while (!pq.empty())
        {
            long long tp = pq.top();
            pq.pop();

            sum += tp * tp;
        }

        cout << sum << "\n";
    }
}