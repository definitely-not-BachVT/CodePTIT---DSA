#include <bits/stdc++.h>
using namespace std;

string toBin(long long a)
{
    int sz = 0;
    vector<int> res;
    while (a)
    {
        res.push_back(a % 2);
        a /= 2;
        ++sz;
    }
    reverse(res.begin(), res.end());

    string ans = "";
    for (int i = 0; i < sz; ++i)
        ans = ans + to_string(res[i]);
    return ans;
}

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

        string s = to_string(n);
        long long ans = 0;

        int size = s.size();
        long long idx = 1;

        bool ok = false;
        if (s[0] - '0' > 1)
        {
            ok = true;
        }

        for (int i = 1; i < size; ++i)
        {
            if (s[i] - '0' > 1)
            {
                idx *= 2;
                ok = true;
            }
            else if (s[i] - '0' == 1)
            {
                idx *= 2;
            }
            else if (ok)
            {
                idx *= 2;
            }
        }
        // cout << "idx la: " << idx << "\n";

        ans += idx;
        // cout << ans << "\n";

        for (int i = 1; i <= size - 1; ++i)
            ans += pow(2, i - 1);
        cout << ans << "\n";
    }
}
