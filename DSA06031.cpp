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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        deque<int> dq;
        for (int i = 0; i < n; ++i)
        {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && a[dp.back()] <= a[i])
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1)
                cout << a[dq.front()] << " ";
        }

        cout << "\n";
    }
}