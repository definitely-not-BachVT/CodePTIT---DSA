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
        string s;
        cin >> s;

        vector<int> mark(26, 0);
        for (char c : s)
            mark[c - 'a']++;

        int mx = *max_element(mark.begin(), mark.end());
        if (mx > (s.size() + 1) / 2)
            cout << "-1\n";
        else
            cout << "1\n";
    }
}