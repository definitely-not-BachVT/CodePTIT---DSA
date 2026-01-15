#include <bits/stdc++.h>
using namespace std;

int main()
{
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

        int mx = *max_element(mark.begin(), mark.end());
        if (mx + (mx - 1) * (k - 1) <= s.size())
            cout << "1\n";
        else
            cout << "-1\n";
    }
}