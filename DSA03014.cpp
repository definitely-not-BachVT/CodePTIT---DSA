#include <bits/stdc++.h>
using namespace std;

vector<long long> cube(1e6 + 3);
void sinh()
{
    for (long long i = 1; i <= 1e6 + 2; ++i)
        cube[i] = i * i * i;
}

bool sub(const string &s, const string &t)
{
    int i = 0, j = 0;
    int s_sz = s.size();
    int t_sz = t.size();
    while (i < s_sz && j < t_sz)
    {
        if (s[i] == t[j])
            i++;
        j++;
    }
    return i == s_sz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    sinh();

    while (t--)
    {
        long long n;
        cin >> n;

        string ns = to_string(n);
        string ans = "-1";

        int pos = lower_bound(cube.begin(), cube.end(), n) - cube.begin();
        for (int i = pos; i >= 0; --i)
            if (sub(to_string(cube[i]), ns))
            {
                ans = to_string(cube[i]);
                break;
            }

        cout << ans << "\n";
    }
}