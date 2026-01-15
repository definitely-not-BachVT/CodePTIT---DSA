#include <bits/stdc++.h>
using namespace std;

vector<long long> a = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        int idx = a.size() - 1;
        long long cnt = 0;

        for (int i = idx; i >= 0; --i)
        {
            long long ad = n / a[i];
            cnt += ad;

            n -= ad * a[i];
        }

        cout << cnt << "\n";
    }
}