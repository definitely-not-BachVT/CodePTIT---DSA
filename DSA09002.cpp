#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    set<pair<long long, long long>> st;

    long long idx = 1;
    while (idx <= n)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        while (ss >> s)
        {
            long long y = stoll(s);
            st.insert(make_pair(min(idx, y), max(idx, y)));
        }

        ++idx;
    }

    for (pair<long long, long long> x : st)
        cout << x.first << " " << x.second << "\n";
}