#include <bits/stdc++.h>
using namespace std;

set<string> res;
void sinh(string s)
{
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
        string s;
        cin >> s;

        int size = s.size();
        int idx = size - 1;

        while (idx >= 0 && s[idx] == '0')
            --idx;

        if (idx < 0)
        {
            for (int i = 0; i < size; ++i)
                cout << "1";
            cout << "\n";

            continue;
        }

        s[idx] = '0';
        for (int i = idx + 1; i < size; ++i)
            s[i] = '1';

        cout << s << "\n";
    }
}