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

        int cnt4 = 0, cnt7 = 0;
        cnt4 = n / 4;

        for (int i = cnt4; i >= 0; --i)
        {
            if ((n - (i * 4)) % 7 == 0)
            {
                cnt7 = (n - (i * 4)) / 7;
                cnt4 = i;
            }
        }

        if (cnt4 < 1 && cnt7 < 1)
        {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < cnt4; ++i)
            cout << "4";
        for (int i = 0; i < cnt7; ++i)
            cout << "7";
        cout << "\n";
    }
}